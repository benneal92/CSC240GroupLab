#include <iostream>
#include <sstream>
#include <cassert>
#include <math.h>
#include "HashTable.h"
#include "BirthDate.h"
#include "FrontWheelDrive.h"
#include "RearWheelDrive.h"
#include "AllWheelDrive.h"
#include "Car.h"

// test declarations
void testInsert();
void testRemove();
void testRemoveMultiple();
void testLoadFactor();
void testIterator();
void testEmptyIterator();
void testIteratorWithEmptyBeginPosition();

//simulation declaration

void simulateBirthdayParadox(int numberOfPeople);

int main() {

	int numberPeople;


	testInsert();
	testRemove();
	testRemoveMultiple();
	testLoadFactor();
	testIterator();
	testEmptyIterator();
	testIteratorWithEmptyBeginPosition();
	std::cout << "Tests ran finished without error 🍕" << std::endl;
	std::cout << std::endl;
	std::cout << "Let's run a Birthday Paradox Simulator!" << std::endl;
	std::cout << "In a classroom of students what is the chance you will have the same birthday as someone else??" << std::endl;
	std::cout << "The first assumption is usually that birthdays are evenly distributed throughout the year. That is not the case due to combinatorics!!"<< std::endl;
	std::cout << "Please enter the number of people in the class room:";
	std::cin >> numberPeople;


	simulateBirthdayParadox(numberPeople);



	return 0;
}




void simulateBirthdayParadox(int numberOfPeople){

	srand(time(0));
	float probability = 0;
		float actualProb = 1-((pow((364/365.0), (numberOfPeople*(numberOfPeople-1))/2.0)));
		int CollisionFound = 0;
		for (int i = 0; i<=10000;i++){
			HashTable<BirthDate> ht(365);
			for(int i =0; i<numberOfPeople; i++){
				BirthDate person;
				ht.insert(person);
			}

			if(ht.findCollisions() > 0){
				CollisionFound++;
			}

		}

		probability = CollisionFound/10000.0;

		std::cout << std::endl;
		std::cout << "Calculated Probability: " << actualProb << std::endl;
		std::cout << "Simulated Probability: " <<  probability << std::endl;
		std::cout << "This means with " << numberOfPeople << " of people in a class room you";
		std::cout << " are this likely to have the same birthday as someone else." << std::endl;
		std::cout << std::endl;
		std::cout << "The Birthday Paradox is a great example of how common collisions can be in a hash table. " << std::endl;
		std::cout << "In our hash table we have each calendar day as a bucket. When one person has a birthday the same as another ";
		std::cout << "these two birthdays are assigned to the same bucket. " << std::endl;
		std::cout << "The Birthday Paradox illustrates how you don't need a large number of items before there is a likely chance there will be a collision. "<< std::endl;



}

/*
 * Does it insert items?
 */
void testInsert() {
	std::stringstream testLog;
	std::string const matcher =
			R"(HashTable [
0>> 0, 
1>> 
2>> 9, 6, 3, 
3>> 
4>> 
5>> 5, 2, 
6>> 
7>> 8, 
8>> 1, 
9>> 
10>> 7, 4, 
] 
)";

	HashTable<int> ht;
	for (int i = 0; i < 10; i++) {
		ht.insert(i);
	}
	testLog << ht;

	assert(matcher == testLog.str());
}

/*
 * Does it remove one item?
 */
void testRemove() {
	std::stringstream testLog;

	HashTable<int> ht;
	ht.insert(1);
	ht.insert(2);
	ht.insert(3);
	ht.remove(2);
	testLog << ht;

	std::string const expected =
			R"(HashTable [
0>> 
1>> 
2>> 3, 
3>> 
4>> 
5>> 
6>> 
7>> 
8>> 1, 
9>> 
10>> 
] 
)";
	assert(expected == testLog.str());
}

/*
 * Does it remove multiple of the same item?
 */
void testRemoveMultiple() {
	std::stringstream ss;
	HashTable<int> ht;
	for (int i = 0; i < 15; i++) {
		ht.insert(i);
	}
	for (int i = 0; i < 15; i++) {
		ht.insert(i);
	}
	ht.remove(7);
	ht.remove(11);
	ss << ht;

	std::string expected =
			R"(HashTable [
0>> 0, 0, 
1>> 
2>> 9, 6, 3, 9, 6, 3, 
3>> 
4>> 12, 12, 
5>> 5, 2, 5, 2, 
6>> 
7>> 14, 8, 14, 8, 
8>> 1, 1, 
9>> 
10>> 13, 10, 4, 13, 10, 4, 
] 
)";
	assert(expected == ss.str());
}

/*
 * Does it calculate the load factor correctly?
 */
void testLoadFactor() {
	std::stringstream ss;
	HashTable<int> ht;
	for (int i = 0; i < 15; i++) {
		ht.insert(i);
	}
	ss << ht.loadFactor(); // 15 / 11 = 1.363364
	assert(ss.str() == "1.36364");
}

/*
 * Does it correctly iterate a full list?
 */
void testIterator() {
	std::stringstream ss;
	HashTable<int> ht;
	for (int i = 0; i < 15; i++) {
		ht.insert(i);
	}
	for (auto &item : ht) {
		ss << item << ',';
	}
	std::string expected = R"(0,9,6,3,12,5,2,14,11,8,1,13,10,7,4,)";
	assert(expected == ss.str());
}

/*
 * Will the iterator be fine if no items are added?
 */
void testEmptyIterator() {
	std::stringstream ss;
	HashTable<int> ht;
	// add NO items at all
	for (auto &item : ht) {
		ss << item << ',';
	}
	std::string expected = "";
	assert(expected == ss.str()); // nothing printed. Correct!
}

/*
 * Will the iterator find the first good item?
 */
void testIteratorWithEmptyBeginPosition() {
	std::stringstream ss;
	HashTable<int> ht;
	ht.insert(5);
	ht.insert(5);
	ht.insert(5);

	auto iterator = ht.begin();
	coords expected { 5, 0 }; // iterator should automatically seek to first 5

	assert(iterator.position == expected);
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
