# 🔒 Bluetooth Fingerprint Smart Lock

A smart security system that combines **fingerprint authentication** and **Bluetooth connectivity** for enhanced protection.  
The lock unlocks when an authorized fingerprint is detected, and a **buzzer alarm is triggered if the connected phone goes out of Bluetooth range**, ensuring safety and preventing unauthorized removal.

---

## 🚀 Features
- Secure access using **fingerprint sensor**  
- **Bluetooth-enabled** for phone connectivity  
- **Automatic locking** after a few seconds  
- **Buzzer alarm** when the phone goes out of Bluetooth range  
- Suitable for **home, hostel, and personal lockers**  

---

## 🛠️ Components Required
- Arduino UNO / Nano / MEGA  
- Fingerprint Sensor (R305 / R307 or compatible)  
- Bluetooth Module (HC-05 / HC-06)  
- Relay Module / Servo Motor (for lock mechanism)  
- Buzzer  
- Jumper wires & Breadboard  
- Power supply  

---

## ⚡ Circuit Connections

| Component            | Arduino Pin          |
|----------------------|--------------------- |
| Fingerprint Sensor   | D2 (RX), D3 (TX)     |
| Bluetooth Module HC-05 | D10 (RX), D11 (TX) |
| Buzzer               | D6                   |
| Lock (Relay/Servo)   | D7                   |

---

## 📜 Code
The main Arduino sketch is available in **`bluetooth_fingerprint_smartlock.ino`**.  

Key operations in the code:
- Unlocks door on **valid fingerprint detection**  
- Keeps door unlocked for 5 seconds, then re-locks automatically  
- Bluetooth module continuously checks for phone heartbeat signal  
- If phone goes out of range → **buzzer alarm turns ON**  

---

## 📲 Phone App Requirement
- Use a **Bluetooth terminal app** or a custom app (e.g., MIT App Inventor / Kodular)  
- The app must send a **heartbeat signal ("1")** every second while connected  
- If Arduino doesn’t receive signal within **5 seconds**, buzzer is triggered  

---

## 🖼️ System Demo
- **Authorized fingerprint** → Lock opens for 5 seconds  
- **No fingerprint / wrong fingerprint** → Lock stays closed  
- **Bluetooth disconnects** → Buzzer alarm activated  

---

## ⚠️ Important Notes
- Ensure fingerprint sensor is properly enrolled with valid fingerprints before use  
- Use a **stable 5V power supply** for Bluetooth and fingerprint modules  
- Adjust **timeout duration** in the code as per your requirement  

---

## 📌 Future Enhancements
- Add **mobile app notifications** instead of just buzzer alerts  
- Integrate with **IoT (Blynk / Firebase / MQTT)** for remote monitoring  
- Add **multiple user profiles** with admin management  

---

## 👨‍💻 Author
Developed as a **smart security project** using Arduino, Bluetooth, and biometric authentication.  
Feel free to fork, improve, and contribute! 🚀
