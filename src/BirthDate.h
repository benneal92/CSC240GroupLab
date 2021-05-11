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
#include <iostream>

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

    std::string getMonthAsString() const;					// returns month as a string
    std::string getName() const;
    bool operator== (const BirthDate & obj) const;		// overloading == operator
    bool operator!= (const BirthDate & obj) const;		// overloading != operator


    friend std::ostream& operator<<(std::ostream& out, const BirthDate &obj); //overload << operator


private:
    int calculateAge();
    int birthDayInDays();

    int year;
    int month;
    int day;
    int age;
    std::string name;
    int birthdayDays; // What day in the year is your birthday


};


// Number of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                            31, 30, 31};

// Names of the months
static std::string conversionTable[] = {"Error", "January", "February",
    "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};


//set the seed for random name generation
static std::string randomNames[] = {"Viva", "Terrence", "Eusebla", "Cristie", "Linnie", "Mercy", "Chase", "Bennie", "Diego", "Rosaria", "Cayla",
								"Sherril", "Matilde", "Wendell", "Lucas", "Ardath", "Myrna", "Luciana","Alexa", "Matthew", "Lavinia",
								"Brunilda","Sofia", "Isabella", "Tianna", "Rosy", "Kirstie", "Isaac", "Lyndon", "Ashley", "Amanda",
								"George", "James", "Lyndon", "Chanel", "Marva","Autumn", "Elsa", "Tyler", "Luke", "Jake", "Julian", "Bernice", "Domingo"
								"Freddie", "Kay", "Hilda", "Courtney", "Arnold", "Wendell", "Rosalie", "Wayne", "Danielle", "Alex", "Camillia", "Kevin",
								"Joe", "Charles", "Chance", "Olivia", "Torrin", "Kathryn", "Naoko", "Maura", "Hannah", "Nolan"};




/**
 * Default Constructor
 *
 * Pre: srand() is called where object is initialized.
 * Post: Birthday Object is initialized (not empty). Birthday will always be before 1920.
 * Data Members: month, day, name, year, birthdayDays,age
 * Member Functions: rand()
 */
BirthDate::BirthDate(){

	month = rand() % 12 + 1;
	day = rand() % daysInMonth[month] + 1;
	name = randomNames[rand() % 30];
	year = rand() % (2021-1930) + 1920;
	birthdayDays = this->birthDayInDays();
	age = this->calculateAge();

}




/**
 * Initialized Constructor by User
 *
 * Pre: Constructor to initialize BirthDate object. Year must be before 1920
 * Post: BirthDay object is not empty
 * Data Members: day, month, year, name, birthdayDays, age, DayOfYears
 * Member Functions: rand(), birthDayInDays(), calculateAge()
 */
BirthDate::BirthDate(std::string first_name, int newMonth, int newDay, int newYear){

	day = newDay;
	month = newMonth;
	year = newYear; //Birthday is always
	name = first_name;
	birthdayDays = birthDayInDays();
	age = calculateAge();

}


/**
 * Returns birthday in days from Jan. 1st
 *
 * Pre:We are assuming todays date is 05/31/21.BirthDate object is initialized.
 * Post:birthdayDays is the number of days from the first of January is the day of birthday (range 1 to 365).
 * Data Members: month, daysInMonth, day, year
 * Member Functions:N/A
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
 * Calculates age of person
 *
 * Pre:BirthDate object is initialized. Assume date is 5/31/2021
 * Post:age is calculated and assigned to age data member
 * Data Members:daysInMonth,birthdayDays
 * Member Functions:N/A
 */
int BirthDate::calculateAge(){
	//Assume date is 05/31/2021

	int current_inDays = 31 + daysInMonth[1] + daysInMonth[2] + daysInMonth[3] + daysInMonth[4] + daysInMonth[5] + ((2021-1920)*365);

	return (current_inDays - birthdayDays)/365;

}





/**
 * Month getter
 *
 * Pre:BirthDate is initialized
 * Post:Month data member is returned
 * Data Members:month
 * Member Functions:N/A
 */
int BirthDate::getMonth() const
{
   return month;
}


/**
 * Returns Month as String
 *
 * Pre:BirthDate is initialized
 * Post:Month data member is returned as astring
 * Data Members:month,conversionTable
 * Member Functions:N/A
 */
std::string BirthDate::getMonthAsString() const
{
  return conversionTable[month];
}



/**
 * Year getter
 *
 * Pre:BirthDate is initialized
 * Post:year data member is returned
 * Data Members:year
 * Member Functions:N/A
 */
int BirthDate::getYear() const
{
  return year;
}


/**
 * Day getter
 *
 * Pre:BirthDate is initialized
 * Post:day data member is returned
 * Data Members:day
 * Member Functions:N/A
 */
int BirthDate::getDay() const
{
  return day;
}


/**
 * Age getter
 *
 * Pre:BirthDate is initialized
 * Post:age data member is returned
 * Data Members:age
 * Member Functions:N/A
 */
int BirthDate::getAge() const
{
  return age;
}



/**
 * Name getter
 *
 * Pre:BirthDate is initialized
 * Post:name data member is returned
 * Data Members:name
 * Member Functions:N/A
 */
std::string BirthDate::getName() const
{
  return name;
}


/**
 * Overloaded == operator
 *
 * Pre:Both BirthDate objects are initialized
 * Post:Equals operator is overloaded, will check if two BirthDate objects are the same
 * Data Members:N/A
 * Member Functions:getDay(), getMonth(), getYear()
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
 * Overloaded != operator
 *
 * Pre:Both BirthDate objects are initialized
 * Post:Not Equals operator is overloaded, willcheck if two BirthDate objects are the same
 * Data Members:N/A
 * Member Functions:getDay(), getMonth(), getYear()
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
 * Copy Constructor
 *
 * Pre: Both BirthDate objects are initialized
 * Post:anotherBirthDate has the same valued data members as this object
 * Data Members:day, month, year, birthdayDays, name, age
 * Member Functions:N/A
 */
BirthDate::BirthDate(const BirthDate & anotherBirthDate){

	day = anotherBirthDate.day;
	month = anotherBirthDate.month;
	year = anotherBirthDate.year;
	birthdayDays = anotherBirthDate.birthdayDays;
	name = anotherBirthDate.name;
	age = anotherBirthDate.age;




}


/**
 * overloaded << operator. Prints the BirthDate object to the screen
 *
 * Pre:BirthDate Object Initialized
 * Post:The BirthDate object is printed to the screen
 * Data Members: N/A
 * Member Functions:GetName(), GetDay(), GetYear(), GetAge()
 */
std::ostream& operator<<(std::ostream& out, const BirthDate &obj){

	out << "Hi, my name is " << obj.getName() << "!" ;
	out << " My Birthday is "   << obj.getMonth() << "/" << obj.getDay() << "/" << obj.getYear();
	out << " and I am " << obj.getAge() << " years old." << std::endl;

	return out;
}



/**
 * Calculate how many days a BirthDate is from Jan. 1st. Used as the index of the hash table.
 *
 * Pre:BirthDate Object Initialized
 * Post:returns a value between 1 and 365 that represents a persons Birthday in days from Jan. 1st.
 * Data Members: N/A
 * Member Functions:GetName(), GetDay(), GetYear(), GetAge()
 */
size_t calcDayOfYear(const BirthDate& obj){

	int daysInYear=0;

	for(int i = 0;i <obj.getMonth();i++){


		daysInYear += daysInMonth[i];

	}

	daysInYear += obj.getDay();
	return daysInYear;
}

//Just going to return the number of days in a year
/**
 * Hash Function used for BirthDate object
 *
 * Pre:BirthDate Object Initialized
 * Post:calls CalcDayOfYear to determine the value to go into hash table
 * Data Members: index (size_t)
 * Member Functions:calcDayOfYear()
 */
template<>
class Hash<BirthDate>
{
public:
	size_t operator() (const  BirthDate& obj ) const
	{
		size_t index = 0;
		index = calcDayOfYear(obj);
		return index;
		std::cout << "index being returned: " << index << std::endl;
	}


};







#endif /* SRC_BIRTHDATE_H_ */
