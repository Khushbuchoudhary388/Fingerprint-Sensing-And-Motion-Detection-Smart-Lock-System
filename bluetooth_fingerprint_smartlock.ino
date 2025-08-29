#include <SoftwareSerial.h>
#include <Adafruit_Fingerprint.h>

// Bluetooth module pins
SoftwareSerial BT(10, 11); // RX, TX for HC-05

// Fingerprint sensor pins
SoftwareSerial mySerial(2, 3); // RX, TX for fingerprint sensor
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// Buzzer & Lock pins
const int buzzerPin = 6;
const int lockPin = 7;

// Bluetooth connection monitoring
bool btConnected = false;
unsigned long lastSignalTime = 0;
unsigned long timeoutDuration = 5000; // 5 seconds timeout

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(lockPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(lockPin, LOW);

  // Initialize fingerprint sensor
  finger.begin(57600);
  if (finger.verifyPassword()) {
    Serial.println("Fingerprint sensor found!");
  } else {
    Serial.println("Fingerprint sensor not detected :(");
    while (1);
  }

  Serial.println("Bluetooth Smart Lock System Initialized...");
}

void loop() {
  checkBluetoothConnection();

  // Check if fingerprint is placed
  int fingerID = getFingerprintID();
  if (fingerID >= 0) {
    Serial.print("Authorized Fingerprint ID: ");
    Serial.println(fingerID);
    unlockDoor();
  }

  delay(100);
}

void checkBluetoothConnection() {
  if (BT.available()) {
    char c = BT.read();
    if (c == '1') { // Phone sends '1' periodically as heartbeat
      btConnected = true;
      lastSignalTime = millis();
      digitalWrite(buzzerPin, LOW); // Stop buzzer if reconnected
    }
  }

  // If no signal from phone in timeout period → buzzer ON
  if (btConnected && (millis() - lastSignalTime > timeoutDuration)) {
    Serial.println("Bluetooth disconnected! Triggering buzzer.");
    digitalWrite(buzzerPin, HIGH);
    btConnected = false;
  }
}

int getFingerprintID() {
  finger.getImage();
  if (finger.image2Tz() != FINGERPRINT_OK) return -1;
  if (finger.fingerFastSearch() != FINGERPRINT_OK) return -1;

  return finger.fingerID; // return matched fingerprint ID
}

void unlockDoor() {
  Serial.println("Door Unlocked!");
  digitalWrite(lockPin, HIGH);
  delay(5000); // Keep unlocked for 5 seconds
  digitalWrite(lockPin, LOW);
  Serial.println("Door Locked!");
}
