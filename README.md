# Landmine Detection Robot with Differential Drive and Metal Detector

This Arduino-based project is a Landmine Detection Robot designed to navigate through an environment using a differential drive mechanism. The robot is equipped with a servo-mounted metal detector to scan the area for landmines. If a metal signal is detected, the robot activates a buzzer to alert the user.

## Components Used

- **Arduino**: The central control unit for the robot.
- **Motor Drive Shield**: Provides control for the robot's DC traction motors.
- **Servo Motor**: Mounted with the metal detector to scan the ground.
- **Ultrasonic Sensor**: Used to measure distances for obstacle avoidance.
- **Buzzer**: Activated when a metal signal is detected.
- **DC Traction Motors**: Drive the robot's movement.
- **Ultrasonic Sensor**: Measures distances to detect obstacles.

## Functionalities

1. **Ultrasonic Sensor**: The robot uses an ultrasonic sensor to measure distances in front of it. If it detects an obstacle within a certain range (defined by `COLL_DIST`), the robot stops and changes direction.

2. **Servo-Mounted Metal Detector**: The robot is equipped with a servo-mounted metal detector. The servo is controlled to scan the ground in front of the robot. When a metal signal is detected, the robot responds by activating the buzzer.

3. **Differential Drive Mechanism**: The robot uses a differential drive mechanism to move. It can move forward, backward, turn left, turn right, or turn around based on obstacle detection and metal detection.

4. **Obstacle Avoidance**: When an obstacle is detected, the robot stops and changes direction to avoid collisions. It uses the `moveStop()` and `changePath()` functions to handle this.

5. **Metal Detection**: The `readPing()` function reads the ultrasonic sensor to detect distances. When a distance less than `COLL_DIST` is detected, the `changePath()` function is called to check for metal signals using the servo-mounted metal detector.

6. **Buzzer Activation**: If a metal signal is detected, the robot activates the buzzer using the `digitalWrite` function.

## Main Loop

The main loop of the code controls the robot's behavior:

- It starts by positioning the servo-mounted metal detector to face forward.
- It then continuously reads the distance using the ultrasonic sensor and checks for obstacles.
- If an obstacle is detected, the robot changes its path to avoid it.
- The robot continuously moves forward, periodically checking for metal signals.
- When a metal signal is detected, the buzzer is activated.

## Conclusion

This Landmine Detection Robot is designed to navigate through environments, avoiding obstacles, and detecting metal signals that might indicate the presence of landmines. It serves as a basic prototype for a real-world application of robotics in hazardous situations.
