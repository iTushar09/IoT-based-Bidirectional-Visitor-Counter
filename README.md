# 🚪 IoT-Based Bidirectional Visitor Counter

A homemade electronic counter using **Arduino** and **IR sensors** to track people walking in and out of spaces. It knows whether someone is coming or going and shows the current number of people on an LCD display in real-time.

## ✨ Key Features

- **Bidirectional Detection**: Distinguishes between entry and exit movements
- **Real-Time Display**: Live visitor count shown on 16x2 LCD
- **Accurate Counting**: Uses dual IR sensors for reliable detection
- **Compact Design**: Perfect for rooms, offices, events, or retail spaces
- **Easy Integration**: Simple setup with common Arduino components

## 🛠️ Hardware Requirements

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Uno | 1 | Main microcontroller |
| IR Sensors | 2 | Motion detection |
| 16x2 I2C LCD Display | 1 | Count visualization |
| Jumper Wires | Multiple | Connections |
| Breadboard | 1 | Prototyping |
| Power Supply (5V/12V) | 1 | System power |

## 🔗 Wiring Configuration

![Circuit View](<Circuit view.png>)

### Connection Details:
- **IR Sensor 1 (Entry)** → Digital Pin (configurable)
- **IR Sensor 2 (Exit)** → Digital Pin (configurable)
- **LCD Display** → I2C connection (SDA/SCL pins)
- **Power Rails** → 5V and GND distribution

## 🎯 Applications

- **Smart Buildings**: Automated lighting and HVAC control
- **Retail Analytics**: Customer flow monitoring
- **Event Management**: Attendance tracking
- **Security Systems**: Occupancy monitoring
- **Energy Efficiency**: Room-based automation

## 🚀 Getting Started

1. Assemble the circuit according to the diagram
2. Upload the Arduino code to your board
3. Calibrate IR sensor sensitivity
4. Position sensors at optimal detection points
5. Power up and start monitoring!

## 📊 How It Works

The system uses two IR sensors positioned strategically to detect the sequence of interruptions. When someone enters, Sensor 1 triggers first, followed by Sensor 2. For exits, the sequence reverses, allowing the system to accurately determine direction and update the counter accordingly.

## 👨💻 Created By

**Tushar Chaudhari**  
*Electronics Enthusiast & IoT Maker*

***

*This project demonstrates practical IoT applications using affordable components, making it perfect for learning embedded systems and automation concepts.*
