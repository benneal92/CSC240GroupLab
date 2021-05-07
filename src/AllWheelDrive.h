#ifndef ALLWHEELDRIVE_H
#define ALLWHEELDRIVE_H

#include <iostream>

#include "DriveStrategy.h"

class AllWheelDrive : public DriveStrategy {
public:
    void drive() const override {
        std::cout << "Driving with all wheel drive";
    }

    AllWheelDrive* clone() const override {
        return new AllWheelDrive;
    }
};

#endif