//
// Created by ruoyo on 2020/6/27.
//

#ifndef SRC_FOURWHEELCONTROL_H
#define SRC_FOURWHEELCONTROL_H
#include "twist2multiarray/Node.h"

extern wheel_t wheel_3;
void twc(float Vx, float Vy, float Omega);
void adjustSteerAngle(float &targetVel, float &targetAngle_rad, float currentAngle_rad);

#endif //SRC_FOURWHEELCONTROL_H
