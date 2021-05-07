#ifndef CAR_H
#define CAR_H
#include "Hash.h"
#include <string>

class Car{

public:
	Car(int, int, std::string, std::string);
	int getYearModel() const;
	int getSpeed() const;
	std::string getModel() const;
	std::string getBrand() const;
	bool operator==(const Car&);

private:
	int yearModel;
	int speed;
	std::string model;
	std::string brand;
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
