//
// Created by ruoyo on 2020/6/27.
//

#include "twist2multiarray/ThreeWheelControl.h"
#include <algorithm>
#include <math.h>

wheel_t wheel_3={0};
float delta[4]={3*PI/4, PI/4, 7*PI/4, 5*PI/4};
void twc(float Vx, float Vy, float Omega)
{
//    for(int i=0;i<4;i++)
//    {
//        wheel.angle[i] = atan2((Omega*AFA*sin(delta[i])+V*sin(theta)) ,(Omega*AFA*cos(delta[i])+V*cos(theta)));
//        //获得的速度永远>=0
//        wheel.vol[i] = sqrt(pow(Omega*AFA,2)+V*V+ 2*V*Omega*AFA*cos(delta[i]-theta));
//    }
    double theta1 = PI/3;
    double theta2 = PI/6;
    wheel_3.vel[0] = (double)(Vx+Omega*AFA);
    wheel_3.vel[1] = (double)(-Vx * cos(theta1) + Vy*sin(theta1)+ Omega*AFA);
    wheel_3.vel[2] = (double)(-Vx * sin(theta2) - Vy*cos(theta2)+ Omega*AFA);

}
