/********************************************************************************
   BB-1 Self balancing robot by Juerd Mispelblom Beyer
   V1
   CONNECTIONS:
   Arduino D3  - Motor Driver PWM 1 Input
   Arduino D4  - Motor Driver DIR 1 Input
   Arduino D9  - Motor Driver PWM 2 Input
   Arduino D10 - Motor Driver DIR 2 Input
   Arduino GND - Motor Driver GND
 ********************************************************************************/

#include <Arduino.h>
#include <IMU.h>

IMU imu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(5000);
    imu.calibrate();
}

void loop() {
    imu.get_filtered_pitch();
    imu.print_vectors();
    imu.print_filtered_pitch_yaw();
}