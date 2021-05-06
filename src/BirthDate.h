/*
 * BirthDates.h
 *
 *  Created on: May 4, 2021
 *      Author: Erin
 *
 *
 */

//Not using template here because data members will always be the same data type

#ifndef SRC_BIRTHDATE_H_
#define SRC_BIRTHDATE_H_

#include <string>
#include <chrono>

#include <cmath>
#include "Hash.h"



class BirthDate
{
public:

    BirthDate(); // Default Constructor
    BirthDate(std::string first_name, int newMonth, int newDay, int newYear);
    BirthDate(const BirthDate & anotherBirthDate); //copy constructor
    int getMonth() const;							// returns year
    int getYear() const;							// returns month
    int getDay() const;							// returns day
    int getAge() const;
    int calcDayOfYear();
    std::string getMonthAsString() const;					// returns month as a string
    std::string getName() const;
    bool operator== (const BirthDate & obj) const;		// overloading == operator
    bool operator!= (const BirthDate & obj) const;		// overloading != operator
    size_t getDayOfYear();

    friend std::ostream& operator<<(std::ostream& out, const BirthDate &obj); //overload << operator



private:
    int calculateAge();
    int birthDayInDays();

    int year;
    int month;
    int day;
    int age;
    std::string name;
    int birthdayDays;
    size_t DayOfYear;	//how many days into the year is your birthday? Used for hash function



};


// Number of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                            31, 30, 31};

// Names of the months
static std::string conversionTable[] = {"Error", "January", "February",
    "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};

//set the seed for random number generation
static std::string randomNames[] = {"Viva", "Terrence", "Eusebla", "Cristie", "Linnie", "Mercy", "Chase", "Bennie", "Diego", "Rosaria", "Cayla",
								"Sherril", "Matilde", "Wendell", "Lucas", "Ardath", "Myrna", "Luciana","Alexa", "Matthew", "Lavinia",
								"Brunilda","Sofia", "Isabella", "Tianna", "Rosy", "Kirstie", "Isaac", "Lyndon", "Ashley", "Amanda",
								"George", "James", "Lyndon", "Chanel", "Marva","Autumn", "Elsa", "Tyler", "Luke", "Jake"};




/**
 * Pre: HashTable is initialized and T has Hash functor implemented
 * Post: size_t representing hashed index is returned. State of Hashtable is unchanged
 * Data Members: hashTable
 * Member Functions: N/A
 */
BirthDate::BirthDate(){

	day = rand() % daysInMonth[month] + 1;
	month = rand() % 12 + 1;
	name = randomNames[rand() % 30];
	year = rand() % (2021-1930) + 1920;
	birthdayDays = this->birthDayInDays();
	age = this->calculateAge();
	DayOfYear = this->calcDayOfYear();


}




/**
 * Pre: Constructor to initialize BirthDate object. Year must be before 1920
 * Post: BirthDay object is not empty
 * Data Members: day, month, year, name, birthdayDays, age, DayOfYears
 * Member Functions: N/A
 */
BirthDate::BirthDate(std::string first_name, int newMonth, int newDay, int newYear){

	day = newDay;
	month = newMonth;
	year = newYear; //Birthday is always
	name = first_name;
	birthdayDays = birthDayInDays();
	age = calculateAge();
	DayOfYear = calcDayOfYear();

}


/**
 * Pre:We are assuming todays date is 05/31/21
 * Post:
 * Data Members:
 * Member Functions:
 */
int BirthDate::birthDayInDays(){
	//Assume date is 05/31/2021

	int daysSinceBirthDay = 0;
	for(int i = 0;i < month;i++){


		daysSinceBirthDay += daysInMonth[i];
	}

	daysSinceBirthDay = daysSinceBirthDay + day + (year - 1920)*365;

	return daysSinceBirthDay;

}



/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
int BirthDate::calculateAge(){
	//Assume date is 05/31/2021


	int current_inDays = 31 + daysInMonth[1] + daysInMonth[2] + daysInMonth[3] + daysInMonth[4] + daysInMonth[5] + ((2021-1920)*365);



	return (current_inDays - birthdayDays)/365;

}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
int BirthDate::calcDayOfYear(){

	int daysInYear=0;

	for(int i = 0;i <month;i++){


		daysInYear += daysInMonth[i];

	}

	daysInYear += day;
	return daysInYear;
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
int BirthDate::getMonth() const
// Accessor function for data member month.
{
   return month;
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
std::string BirthDate::getMonthAsString() const
// Returns data member as a string
{
  return conversionTable[month];
}



/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
int BirthDate::getYear() const
// Accessor function for data member year.
{
  return year;
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
int BirthDate::getDay() const
// Accessor function for data member day.
{
  return day;
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
int BirthDate::getAge() const
// Accessor function for data member day.
{
  return age;
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
size_t BirthDate::getDayOfYear(){

	return DayOfYear;
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
std::string BirthDate::getName() const
// Accessor function for data member day.
{
  return name;
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
bool BirthDate::operator== (const BirthDate & obj) const
		{
			if((getDay() == obj.getDay()) and (getMonth() == obj.getMonth()) and (getYear() == obj.getYear())){
				return true;
			}
			else
				return false;
		}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
bool BirthDate::operator!= (const BirthDate &obj) const{
	{

		if((getDay() == obj.getDay()) and (getMonth() == obj.getMonth()) and (getYear() == obj.getYear())){
			return false;
		}
		else
			return true;
	}
}


/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */
BirthDate::BirthDate(const BirthDate & anotherBirthDate){

	day = anotherBirthDate.day;
	month = anotherBirthDate.month;
	year = anotherBirthDate.year;
	birthdayDays = anotherBirthDate.birthdayDays;
	name = anotherBirthDate.name;
	age = anotherBirthDate.age;
	DayOfYear = anotherBirthDate.DayOfYear;



}


/**
 * Pre:BirthDate Object Initialized
 * Post:N/A
 * Data Members: N/A
 * Member Functions:GetName(), GetDay(), GetYear(), GetAge()
 */
std::ostream& operator<<(std::ostream& out, const BirthDate &obj){

	out << "Hi, my name is " << obj.getName() << "!" ;
	out << " My Birthday is "   << obj.getMonth() << "/" << obj.getDay() << "/" << obj.getYear();
	out << " and I am " << obj.getAge() << " years old." << std::endl;

	return out;
}



//Just going to return the number of days in a year, or hash to decade
template<>
class std::hash<BirthDate>
{
public:
	size_t operator() ( BirthDate &obj ) const
	{

		return (obj.getDayOfYear());
	}


};







#endif /* SRC_BIRTHDATE_H_ */
