

#include "Car.h"
using namespace std;

Car::Car(int yearModel, int speed, std::string model, std::string brand)
: yearModel{yearModel}, speed{speed}, model{model}, brand{brand}
{ }

int Car::getYearModel() const{
	return yearModel;
}

int Car::getSpeed() const{
	return speed;
}

std::string Car::getModel() const {
	return model;
}

std::string Car::getBrand() const {
	return brand;
}

bool Car::operator==(const Car& other){
	return (brand == other.brand && model == other.model);
}
