Hero Maze Game with ESP32 
�
�
 Objective: 
To develop a real-time interactive game where the player (hero) must navigate across an 
8x8 LED matrix while avoiding dynamic walls and a moving tank using a joystick. The game 
includes proximity-triggered wall generation, a moving tank, collision detection, and victory 
conditions. 
�
�
 Components Used: 
● ESP32 Devkit V1 
● 8x8 LED Matrix (MAX7219-based) 
● Joystick Module 
● Ultrasonic Sensor (HC-SR04) 
● Buzzer 
● Jumper wires + Breadboard 
● Simulated on Wokwi: 
�
�
 Project Link 
⚙
 Working Principle and Features: 
1. Player Movement: 
● Player is represented by a single lit LED. 
● Joystick movement mapped to change X, Y coordinates. 
● Movement restricted to 8x8 boundary. 
● Deadzone logic avoids jitter or accidental movement. 
2. Tank Movement: 
● Tank is shown as a 2x2 LED block. 
● Moves up and down continuously on the same X position. 
● Bounces off the top and bottom edges. 
● If the hero touches the tank → buzzer beeps and game resets. 
3. Wall Generation: 
● Ultrasonic sensor checks if hero is within 30 cm. 
● Based on last move direction: 
○ If UP/DOWN → horizontal wall. 
○ If LEFT/RIGHT → vertical wall. 
● Wall = 3 LEDs wide in line, blocks further movement. 
● Hero cannot cross active wall tiles. 
4. Collision Detection: 
● Collision with tank or wall → triggers buzzer + resets game. 
5. Victory Condition: 
● If the hero reaches (7, 7) corner → buzzer beeps, game restarts 
�
�
 Gameplay Twist – Mismatched Controls: 
To increase difficulty, joystick controls are intentionally reversed: 
● Left movement sends the player right, and vice versa. 
● Vertical controls (up/down) are unchanged. This twist disorients the player and 
makes maneuvering toward the goal more challenging and engaging. 
⚙
 Key Features: 
● Hero movement via joystick (with reversed left/right logic) 
● Tank moves up and down continuously; colliding with it resets the game 
● Wall generation is triggered by proximity using an ultrasonic sensor 
● Walls block player movement and are placed based on last direction of travel 
● Buzzer provides feedback on collisions and victory 
● Goal is to reach coordinate (7, 7) without crashing 
● Game display runs on a MAX7219-based 8x8 LED matrix 
�
�
 Simulation & Testing (Wokwi): 
● Simulated successfully on Wokwi Project. 
● Used virtual joystick and ultrasonic approximations. 
● Simulation video  
