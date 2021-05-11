/******************************
 Erin Middlemas, Noura Almasri, Ben Neal, Benjamin Liden
 05/11/2021

 This program tests iterating over the HashTable object and simulates the Birthday Paradox with the HashTable object.

 Input: For simulateBirthDayParadox, number of random people to put into hash table.

 Output: For simulateBirthDayParadox, the calculated and simulated probability are returned

 Given: For the simulatedBirthDayParadox, if the number of people entered is 30, this can be the result printed to the terminal:

 Calculated Probability: 0.696816
 Simulated Probability: 0.7067

 This means there is a 30% chance 2 people in the classroom have the same birthday.

 ******************************/

#include <iostream>
#include <math.h>

#include "HashTable.h"
#include "BirthDate.h"
#include "FrontWheelDrive.h"
#include "RearWheelDrive.h"
#include "AllWheelDrive.h"
#include "Car.h"
#include "TestSuite.h"

//simulation declaration

void runBirthdayParadoxCLI();
void simulateBirthdayParadox(int numberOfPeople);

int main() {
	Test::runAll();
	runBirthdayParadoxCLI();
	return 0;
}

void runBirthdayParadoxCLI() {
	int numberPeople;
	std::cout << "Let's run a Birthday Paradox Simulator!" << std::endl;
	std::cout
			<< "In a classroom of students what is the chance you will have the same birthday as someone else??"
			<< std::endl;
	std::cout
			<< "The first assumption is usually that birthdays are evenly distributed throughout the year. That is not the case due to combinatorics!!"
			<< std::endl;
	std::cout << "Please enter the number of people in the class room:";
	std::cin >> numberPeople;

	simulateBirthdayParadox(numberPeople);
}

/**
 * Calculate the likelihood someone in a classroom with n students  has the same birthday.
 *
 * Pre:numberOfPeople given as input from the terminal
 * Post:returns the actual probability calculated by the N choose K function and a simulated value utilizing the groups hash table separate chaining implementation
 * Data Members: probability, actualProb, CollisionFound, HashTable ht, BirthDate person (reinitialized over and over again randomly)
 * Member Functions:insert() (HashTable), findCollisions() (HashTable)
 */
void simulateBirthdayParadox(int numberOfPeople) {

	srand(time(0));
	float probability = 0;
	float actualProb = 1
			- ((pow((364 / 365.0),
					(numberOfPeople * (numberOfPeople - 1)) / 2.0)));
	int CollisionFound = 0;
	for (int i = 0; i < 10000; i++) {
		HashTable<BirthDate> ht(365);
		for (int i = 0; i < numberOfPeople; i++) {
			BirthDate person;
			ht.insert(person);
		}

		if (ht.findCollisions() > 0) {
			CollisionFound++;
		}

	}

	probability = CollisionFound / 10000.0;

	std::cout << std::endl;
	std::cout << "Calculated Probability: " << actualProb << std::endl;
	std::cout << "Simulated Probability: " << probability << std::endl;
	std::cout << "This means with " << numberOfPeople
			<< " of people in a class room you";
	std::cout << " are this likely to have the same birthday as someone else."
			<< std::endl;
	std::cout << std::endl;
	std::cout
			<< "The Birthday Paradox is a great example of how common collisions can be in a hash table. "
			<< std::endl;
	std::cout
			<< "In our hash table we have each calendar day as a bucket. When one person has a birthday the same as another ";
	std::cout << "these two birthdays are assigned to the same bucket. "
			<< std::endl;
	std::cout
			<< "The Birthday Paradox illustrates how you don't need a large number of items before there is a likely chance there will be a collision. "
			<< std::endl;

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
