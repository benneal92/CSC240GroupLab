#ifndef FRONTWHEELDRIVE_H
#define FRONTWHEELDRIVE_H

#include <iostream>

#include "DriveStrategy.h"

class FrontWheelDrive : public DriveStrategy {
public:
    void drive() const override {
        std::cout << "Driving with front wheel drive";
    }

    FrontWheelDrive* clone() const override {
        return new FrontWheelDrive;
    }
};

#endif