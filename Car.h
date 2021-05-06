#ifndef CAR_H
#define CAR_H
#include "Hash.h"
#include <string>

class Car{

public:
	Car(int,std::string, int,std::string);
	int getYearModel()const;
	int getSpeed()const;
	bool operator==(const Car&);

private:
	int yearModel;
	int speed;
	std::string brand;
	std::string model;
};
template<>
class Hash<Car> {
public:
	size_t operator()(const Car &car1, const &car2) {

		std::string hashString = car.getModel() + car.getBrand()
				+ std::to_string(car.getYearModel());

		size_t hashVal = 0;

		for (char ch : hashString)
			hashVal = 37 * hashVal + ch;

		return hashVal;
	}

};

#endif
