//
// Created by Juerd Mispelblom Beyer on 23/01/2022.
//
#include "Arduino.h"
#include "IMU.h"

IMU::IMU(){
    mpu.setup(0x68);  // change to your own address
}

void IMU::calibrate(){
    mpu.calibrateAccelGyro();
    mpu.calibrateMag();
}


void IMU::update_vectors() {
    mpu.update();
    this->acc_x = mpu.getAccX();
    this->acc_y = mpu.getAccY();
    this->acc_z = mpu.getAccZ();
    this->gyro_x = mpu.getGyroX();
    this->gyro_y = mpu.getGyroY();
    this->gyro_z = mpu.getGyroZ();
}

float IMU::get_filtered_pitch(){
    long now = micros();

    // Get new values from IMU
    update_vectors();

    // Calculate pitch from accelerometers x and z
    float pitch_acc_measured = atan2(acc_x, acc_z) / 2 / M_PI;

    // Complementary filter
    float dt = ((now - last_measurement) / 1000000.0);
    filtered_pitch = (filtered_pitch + gyro_y * dt) * .95 + pitch_acc_measured * .05;

    last_measurement = now;

    return filtered_pitch;
}

void IMU::print_vectors(){
    Serial.print(acc_x,2); Serial.print(",");
    Serial.print(acc_y,2); Serial.print(",");
    Serial.print(acc_z,2); Serial.print(",");
}

void IMU::print_filtered_pitch_yaw(){
    Serial.println(filtered_pitch);
}