#include "Car.h"

/**
 * Pre: Car is not initialized
 * Post: Car is initialized with values from parameters
 * Data Members: yearModel, speed, model, brand
 * Member Functions: N/A
 */ 
Car::Car(int yearModel, int speed, std::string model, std::string brand)
: yearModel{yearModel}, speed{speed}, model{model}, brand{brand}
{ }

/**
 * Pre: Car is initialized
 * Post: return yearModel. State unchanged
 * Data Members: yearModel
 * Member Functions: N/A
 */ 
int Car::getYearModel() const{
	return yearModel;
}

/**
 * Pre: Car is initialized
 * Post: return speed. State unchanged
 * Data Members: speed
 * Member Functions: N/A
 */ 
int Car::getSpeed() const{
	return speed;
}

/**
 * Pre: Car is initialized
 * Post: return model. State unchanged
 * Data Members: mode
 * Member Functions: N/A
 */ 
std::string Car::getModel() const {
	return model;
}

/**
 * Pre: Car is initialized
 * Post: return brand. State unchanged
 * Data Members: brand
 * Member Functions: N/A
 */ 
std::string Car::getBrand() const {
	return brand;
}

/**
 * Pre: Car is initialized
 * Post: state unchanged. Returns true/false
 * Data Members: brand and model
 * Member Functions: N/A
 */ 
bool Car::operator==(const Car& other){
	return (brand == other.brand && model == other.model);
}
