#include "Car.h"
using namespace std;

Car::Car(int YearOfModel,std::string Makeby, int spd,std::string model ){
	YearModel = YearOfModel;
	Make = brand;
	speed = spd;
	model = type;

}
int Car::getYearModel()const{
	return YearModel;

}
int Car::getSpeed()const{
	return speed;
}
bool Car::operator==(const Car &car1, const Car &car2){
	return(car1.Make == car2.Make && car1.Model == car2.Model);
}
