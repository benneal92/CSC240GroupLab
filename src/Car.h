#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

#include "Hash.h"
#include "DriveStrategy.h"

class Car {
public:
	Car(int, int, std::string, std::string, DriveStrategy* = nullptr);
	Car(const Car&);
	Car(Car&&) noexcept;
	~Car();
	Car& operator=(const Car&);
	Car& operator=(Car&&) noexcept;
	int getSpeed() const;
	int getYearModel() const;
	std::string getModel() const;
	std::string getBrand() const;
	void setSpeed(int);
	void setYearModel(int);
	void setBrandModel(std::string&, std::string&);
	void setBrandModel(std::string&&, std::string&&);
	void setDrive(DriveStrategy*);
	bool operator==(const Car&);
	bool operator!=(const Car&);
	void performDrive() const;

	friend std::ostream& operator<<(std::ostream& out, const Car& obj);

private:
	int yearModel;
	int speed;
	std::string model;
	DriveStrategy* drive;
};

template<>
class Hash<Car> {
public:
	size_t operator()(const Car& car) {
		std::string hashString = car.getModel() + car.getBrand()
				+ std::to_string(car.getYearModel());

		size_t hashVal = 0;

		for (char ch : hashString)
			hashVal = 37 * hashVal + ch;

		return hashVal;
	}
};

#endif
