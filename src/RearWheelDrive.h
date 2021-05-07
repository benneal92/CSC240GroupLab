#ifndef REARWHEELDRIVE_H
#define REARWHEELDRIVE_H

#include <iostream>

#include "DriveStrategy.h"

class RearWheelDrive : public DriveStrategy {
public:
    void drive() const override {
        std::cout << "Driving with rear wheel drive";
    }

    RearWheelDrive* clone() const override {
        return new RearWheelDrive;
    }

};

#endif