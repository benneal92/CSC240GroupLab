#include <iostream>
#include <sstream>
#include <cassert>

#include "HashTable.h"
#include "BirthDate.h"
#include "FrontWheelDrive.h"
#include "RearWheelDrive.h"
#include "AllWheelDrive.h"
#include "Car.h"

// test declarations
void testInsert();
void testRemove();
void testLoadFactor();
void testIterator();

int main() {
	testInsert();
	testRemove();
	testLoadFactor();
//	testIterator();
	std::cout << "Tests ran finished without error 🍕" << std::endl;
	return 0;
}

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

void testRemove() {
	std::stringstream testLog;
	std::string const matcher =
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

	HashTable<int> ht;
	ht.insert(1);
	ht.insert(2);
	ht.insert(3);
	ht.remove(2);
	testLog << ht;

	assert(matcher == testLog.str());
}

void testLoadFactor() {
	std::stringstream ss;
	HashTable<int> ht;
	for (int i = 0; i < 15; i++) {
		ht.insert(i);
	}
	ss << ht.loadFactor(); // 15 / 11 = 1.363364
	assert(ss.str() == "1.36364");
}

void testIterator() {
	/*

	 This does not work at all.

	 */
	std::stringstream ss;
	HashTable<int> ht;
	for (int i = 0; i < 15; i++) {
		ht.insert(i);
	}
	for (auto item : ht) {
		ss << item;
	}
	std::cout << ss.str();
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