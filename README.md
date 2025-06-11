# 🕹️ Hero Maze Game with ESP32

A real-time interactive maze game on an 8x8 LED matrix using an ESP32, joystick, ultrasonic sensor, and buzzer — with a twist: **reversed horizontal controls** that challenge the player to adapt on the fly.

---

## 📍 Objective

Navigate a hero (single LED) across an 8x8 matrix to reach the goal at (7,7), while avoiding:
- A 2×2 moving tank (vertical motion)
- Dynamically triggered walls (via ultrasonic sensor)
- Self-inflicted collision traps

---

## 🔧 Components Used

- ESP32 Devkit V1  
- MAX7219 8x8 LED Matrix  
- Joystick Module  
- Ultrasonic Sensor (HC-SR04)  
- Buzzer  
- Jumper Wires, Breadboard  
- [🧪 Simulated in Wokwi](https://wokwi.com/projects/433384301215423489)  

---

## 🎮 Gameplay Features

- **Player Movement**: Joystick-controlled (X reversed, Y normal)  
- **Tank**: A 2×2 LED block moving up/down that resets the game on collision  
- **Walls**: Triggered when the hero moves within 30 cm of ultrasonic sensor  
- **Victory**: Reach (7,7) → buzzer victory tone + restart  
- **Game Over**: Collision → buzzer alert + game reset  
- **Matrix Display**: Fully visualizes tank, hero, walls, and food (if extended)

---

## 🧠 Gameplay Twist – Mismatched Controls

- Moving the joystick **left goes right**, and **right goes left**  
- Up/Down controls remain the same  
- This twist adds a unique challenge requiring spatial coordination

---

## 🧪 Simulation

- Full simulation available on [Wokwi](https://wokwi.com/projects/433384301215423489)
- Use virtual joystick and simulate ultrasonic triggering
- 🖼️ [🎥 Watch Simulation Video](https://drive.google.com/file/d/1OYQVFlwMawgpuAFgyrmFXFeG0MBdqrK4/view?usp=drivesdk)

---

## 🧰 Pin Connections

| Component         | ESP32 Pin |
|------------------|-----------|
| DIN (Matrix)     | GPIO 23   |
| CS  (Matrix)     | GPIO 5    |
| CLK (Matrix)     | GPIO 18   |
| Joystick VRx     | GPIO 36   |
| Joystick VRy     | GPIO 39   |
| Joystick SW      | GPIO 4    |
| Ultrasonic TRIG  | GPIO 12   |
| Ultrasonic ECHO  | GPIO 14   |
| Buzzer           | GPIO 15   |

---

## ✅ Setup Notes

- Matrix brightness controlled using `matrix.control(INTENSITY, level)`
- Use Arduino framework or PlatformIO with libraries:
  - `MD_MAX72XX`
  - `SPI`

---

## 📈 Future Improvements

- Add scoring mechanism  
- Add difficulty levels (tank speed, wall rate)  
- Support multiplayer or pause feature  
- Optional Bluetooth support

---

## 📦 Author

**Vinay Kumar**  


