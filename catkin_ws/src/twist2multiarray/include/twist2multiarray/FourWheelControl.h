//
// Created by chrisliu on 2019/9/25.
//

#ifndef VREP_PKG_FWC_H
#define VREP_PKG_FWC_H
#include "twist2multiarray/Node.h"

extern wheel_t wheel;
void fwc(float V, float theta, float Omega);
void adjustSteerAngle(float &targetVel, float &targetAngle_rad, float currentAngle_rad);
#endif //VREP_PKG_FWC_H
