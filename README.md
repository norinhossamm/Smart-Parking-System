# Smart Parking System 

The Smart Parking System harnesses advanced technologies, including sensors and real-time data analysis, to streamline parking management in urban areas, significantly enhancing space utilization and user convenience.

**Technologies Used**: Arduino IDE - Flame sensor module - Bluetooth Module (HC-05) - Light dependent resistor (LDR) - Passive infrared sensor (PIR) - Ultrasonic sensor (HC - SR04) - Servomotor - LED - Buzzer - LCD display

<div align=center>
<img width="614" alt="Screenshot 2024-08-06 at 5 09 33 PM" src="https://github.com/user-attachments/assets/32bdad10-7669-47e7-b744-7a1d0a85ff65">
</div>

## Key Features:

### 1. Entry Gate Control and Operation:

- Ultrasonic Sensors at Entrance: Detect the presence of a vehicle approaching the gate, ensuring responsiveness to incoming traffic.
  
- Gate Opening Criteria: The gate operates based on the availability of parking spaces, opening only if there are spots free.
  
- Servomotor for Gate: Manages the physical opening and closing of the gate, providing precise control over gate movements.
  
- Bluetooth Voice Control: Activates upon vehicle detection. It processes voice commands to trigger the gate operation. If the voice command matches "open" and conditions for an empty space are met, the gate opens.
  
- Dynamic Gate Operation:
  
  - Opening: The gate opens if there are 1 to 4 empty spaces available and a car is detected near the gate, following a successful voice command.
    
  - Closing: After the vehicle passes through, the gate closes automatically once the second ultrasonic sensor positioned after the gate detects the vehicle leaving, ensuring security 
    and controlled access.

### 2. Parking Space Monitoring:

- Ultrasonic Sensors at Each Spot: Determine the presence or absence of vehicles in individual parking spots.
  
- LED Indicators:
  
  - Red LED: Indicates a parking spot is occupied.
    
  - Green LED: Indicates a parking spot is available.

### 3. LCD Display Information:

- Dynamic Space Count: Displays the number of available parking spaces.
  
- Full Capacity Message: Shows "Sorry, No available slots!" if no spaces are left.
  
### 4. Fire Detection System:  

- Flame Sensor: Monitors analog readings to detect the presence of flames.
  
- Fire Alert: Activates a red LED and sounds a buzzer if the reading is below 1000, indicating the presence of a flame.

### 5. Lighting and Security:

- LDR Sensor: Automatically lights up the parking lot in low-light conditions.
  
- PIR Sensor: Enhances parking security by detecting movement during daylight hours, activating an additional lighting system that ensures a high level of security and mitigates potential risks.

![Prototype](https://github.com/user-attachments/assets/0e01059e-8418-48bf-af5d-771f26cbff39)

