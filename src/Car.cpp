#include "Car.h"

#include <typeinfo>

/**
 * Pre: Car is not initialized
 * Post: Car is initialized with values from parameters
 * Data Members: yearModel, speed, model, brand
 * Member Functions: N/A
 */ 
Car::Car(int yearModel, int speed, std::string model, std::string brand, DriveStrategy* drive)
: yearModel{yearModel}, speed{speed}, model{model}, 
	brand{brand}, drive{drive}
{ }

/**
 * Pre: Car is not initialized
 * Post: Car is initialized with values from another Car object
 * Data Members: yearModel, speed, model, brand
 * Member Functions: N/A
 */ 
Car::Car(const Car& car) 
: yearModel{car.yearModel}, speed{car.speed}, model{car.model}, 
	brand{car.brand}, drive{car.drive->clone()}
{ }

/**
 * Pre: Car is not initialized
 * Post: Car is initialized with values from another Car object
 * Data Members: yearModel, speed, model, brand
 * Member Functions: N/A
 */ 
Car::Car(Car&& car) noexcept
: yearModel{std::move(car.yearModel)}, speed{std::move(car.speed)}, model{std::move(car.model)}, 
	brand{std::move(car.brand)}, drive{std::move(car.drive->clone())}
{ }

/**
 * Pre: Car is initialized
 * Post: Car is destroyed and placed in junkyard
 * Data Members: deletes drive
 * Member Functions: N/A
 */ 
Car::~Car(){
	delete drive;
	drive = nullptr;
}

/**
 * Pre: Car is initialized
 * Post: assignment operator takes values and sets current car
 * Data Members: yearModel, speed, model, brand, and drive
 * Member Functions: N/A
 */ 
Car& Car::operator=(const Car& car) {
	if(*this != car){
		yearModel = car.yearModel;
		speed = car.speed;
		model = car.model;
		brand = car.brand;

		if(drive)
			delete drive;

		drive = car.drive->clone();
	}

	return *this;
}

/**
 * Pre: Car is initialized
 * Post: assignment operator takes values and sets current car
 * Data Members: yearModel, speed, model, brand, and drive
 * Member Functions: N/A
 */ 
Car& Car::operator=(Car&& car) noexcept {
	if(this != &car){
		yearModel = std::move(car.yearModel);
		speed = std::move(car.speed);
		model = std::move(car.model);
		brand = std::move(car.brand);

		if(drive)
			delete drive;

		drive = std::move(car.drive->clone());
	}
	return *this;
}

/**
 * Pre: Car is initialized
 * Post: return yearModel. State unchanged
 * Data Members: yearModel
 * Member Functions: N/A
 */ 
int Car::getYearModel() const {
	return yearModel;
}

/**
 * Pre: Car is initialized
 * Post: Sets yearModel. State changed
 * Data Members: yearModel
 * Member Functions: N/A
 */ 
void Car::setYearModel(int yearModel) {
	this->yearModel = yearModel;
}

/**
 * Pre: Car is initialized
 * Post: return speed. State unchanged
 * Data Members: speed
 * Member Functions: N/A
 */ 
int Car::getSpeed() const {
	return speed;
}

/**
 * Pre: Car is initialized
 * Post: Sets speed. State changed
 * Data Members: speed
 * Member Functions: N/A
 */ 
void Car::setSpeed(int speed) {
	this->speed = speed;
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
 * Post: Sets brand and model. State changed
 * Data Members: brand and model
 * Member Functions: N/A
 */ 
void Car::setBrandModel(std::string& brand, std::string& model) {
	this->brand = brand;
	this->model = model;
}

/**
 * Pre: Car is initialized
 * Post: Sets brand and model. State changed
 * Data Members: brand and model
 * Member Functions: N/A
 */ 
void Car::setBrandModel(std::string&& brand, std::string&& model) {
	this->brand = std::move(brand);
	this->model = std::move(model);
}

/**
 * Pre: Car is initialized
 * Post: state changed. Sets drive to new DriveStrategy object
 * Data Members: drive
 * Member Functions: N/A
 */
void Car::setDrive(DriveStrategy* drive) {
	if(this->drive)
		delete this->drive;
	this->drive = drive;
}

/**
 * Pre: Car is initialized
 * Post: state unchanged. Returns true/false
 * Data Members: brand and model
 * Member Functions: N/A
 */ 
bool Car::operator==(const Car& car){
	return (brand == car.brand && model == car.model) &&
			(yearModel == car.yearModel);
}

/**
 * Pre: Car is initialized
 * Post: state unchanged. Returns true/false
 * Data Members: brand and model
 * Member Functions: N/A
 */ 
bool Car::operator!=(const Car& car){
	return !(*this == car);
}

/**
 * Pre: Car is initialized
 * Post: state unchanged. Prints brand, model, and year. returns ostream reference
 * Data Members: This nonmember function will access the data members of a Car object. (brand, model, and yearModel)
 * Member Functions: N/A
 */ 
std::ostream& operator<<(std::ostream& out, const Car& car) {
	out << "Brand: " << car.brand << " Model: " << car.model << " Year: " << car.yearModel;
	return out;
}

/**
 * Pre: Car is initialized
 * Post: state unchanged. Does drive behavior
 * Data Members: drive
 * Member Functions: N/A
 */ 
void Car::performDrive() const {
	if(drive)
		drive->drive();
	else
		std::cout << "No drive strategy";
}