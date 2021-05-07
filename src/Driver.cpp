#include <iostream>
#include "HashTable.h"
#include "BirthDate.h"
#include "FrontWheelDrive.h"
#include "RearWheelDrive.h"
#include "AllWheelDrive.h"
#include "Car.h"

int main() {
    

    return 0;
}

/*
    Car c1{2020, 0, "Corolla", "Toyota", new FrontWheelDrive};
    Car c2{c1};
    Car c3{2021, 100, "Model S", "Tesla", new AllWheelDrive};

    c1 = c3;
    c1.performDrive();

    c2.setSpeed(55);

    std::cout << c1 << '\n';
    std::cout << (c1 == c2) << '\n';
    std::cout << "c2 speed " << c2.getSpeed() << '\n';

    c2.setBrandModel("Ford", "Focus");
    std::cout << c2 << '\n';
    std::cout << (c1 == c2) << '\n';

    c1.performDrive();

    std::cout << '\n';

    c2.setDrive(new RearWheelDrive);
    c2.performDrive();

    std::cout << '\n';
*/