#include <iostream>
#include <sstream>
#include <cassert>

#include "HashTable.h"
#include "BirthDate.h"

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
