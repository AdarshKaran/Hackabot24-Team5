# Hackabot24-Team5
Check out the GitHub repo for Team 5's Teleoperated Extraterrestrial Rover from the University of Manchester HackABot2024 event.

- **ESP32_VideoFeed.ino** folder contains code for the video streaming and object detection in ESP32 Cam
- **MotorControl** folder contains the code to control the 4 motors based on the direction input of _up, down, left, right, stop_
- **Robot Controller Android App** contains the android app used to teleoperate the rover through _Bluetooth_

# Challenge
Create a Teleoperated Extraterrestrial Rover for Completing a Series of Tasks. 

Within a 24-hour time limit, tasks included:

- Task 1: Teleoperating the robot to follow a designated path, maneuvering through diverse terrains such as sand, ramps, and bridges.
- Task 2: Remote operation of the robot using live camera data to contain and push ping-pong balls scattered across the arena into a central pit. Implemented color detection algorithms to identify the color of the ping-pong balls.
- Task 3: Conducting the final demonstration to exhibit the successful completion of all tasks and showcasing the innovations achieved within the allocated time frame at the University of Manchester's HackABot2024 event.

### The Arena
<img src="https://github.com/AdarshKaran/Hackabot24-Team5/blob/main/hacakbot%20media/Arena.jpg?raw=true" width="600">



# Implementation
Our team of 3 successfully built and programmed a teleoperated robot in just 24 hours! This versatile robot tackled diverse terrains (sand, ramps, bridges) while completing two key tasks:

- Precise Path Following: We designed a control system allowing the robot to follow a designated path while being teleoperated remotely.
- Autonomous Ball Collection with Vision Guidance: The robot utilized live camera data and color detection algorithms to identify and maneuver ping-pong balls scattered across an arena. An inverted scooping arm efficiently pushed the balls into a central pit.
    
Components Used:
- Arduino Uno
- HW 130 Motor Controller (L293D Motor Driver Shield)
- ESP32-CAM
- HC-05 Bluetooth Module
- 4 x Wheels
- 4 x DC Motors
- 1 x Mini 9g Analog Servo Motor

### Work In Progress
<img src="https://github.com/AdarshKaran/Hackabot24-Team5/blob/main/hacakbot%20media/WIP1.jpg?raw=true" width="400">

### Final Robot
<img src="https://github.com/AdarshKaran/Hackabot24-Team5/blob/main/hacakbot%20media/Final.jpg?raw=true" height="400">

Watch The Video (5x Speed)

https://github.com/AdarshKaran/Hackabot24-Team5/assets/112091438/a527f25f-3c85-4d18-b004-9edc8e40fd9a

### Acknowledgements
The ESP32 Cam Color Detection code was originally written by [fustyles](https://github.com/fustyles/Arduino/tree/master/ESP32-CAM_Tracking.js).

