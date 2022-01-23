
#ifndef BB_1_IMU_H
#define BB_1_IMU_H

#include "MPU9250.h"
#include <stdint.h>
#include <math.h>

// IMU object
MPU9250 mpu;

class IMU {

private:
    float acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z;

    long last_measurement=0;
    float filtered_pitch, filtered_jaw;

    float pitch_offset;

public:
    IMU();
    void calibrate();
    void update_vectors();
    float get_filtered_pitch();
    void print_vectors();
    void print_filtered_pitch_yaw();
};


#endif //BB_1_IMU_H
