# CSC240GroupLab

The goal of the project is to create a Hash Table that can handle different objects and evenly distribute them throughout a vector. The focus is to reinforce programming concepts and excel in a team-oriented environment. For the data structure, the team chose to implement a Hash Table using Separate Chaining. This Data Structure was chosen since it explores many areas of computer science and provides a deeper understanding of Hashing. It also provided the opportunity to explore concepts around designing classes that are hashable. Each team member was given the freedom to take on work that they found interesting and we saw interest in Design Patterns, Iterators and member functions, and probability with the Birthday Paradox. All of these unique interests have a direct relation with Hashing as they enable specific functionality and cover different perspectives of using a Hash Table.


The program itself will provide the following public member functions that are expected to be both accurate and efficient in their execution.


# Usage


## HashTable

    explicit HashTable(int hashTableSize = 11); 
    bool contains(const T& obj) const;
    bool insert(const T& obj);
    bool remove(const T& obj);
    void makeEmpty();
    int getSize() const;
    bool isEmpty();
    float loadFactor() const;
    int findCollisions() const;


### explicit HashTable(int hashTableSize = 11); 

The constructor of the class is marked as explicit to ensure that no implicit conversions take place during intialization of the object. It has a default parameter set to the prime number 11. This parameter can be supplied by the client and if not prime will be set to the next prime greater than the supplied number.


### bool contains(const T& obj) const;

This member function returns a boolean value and will not change the state of the Hash Table or any objects within it. Will return true if the object is found and false otherwise.


### bool insert(const T& obj);

When adding an object to the Hash Table the insert function will return a boolean value based on the success or failure of inserting the element. The function will not change the state of the object that is being added but will change the state of the Hash Table.


### bool remove(const T& obj);

The remove function is used to remove existing objects from the Hash Table. if the object is not there the function will return false. If the function finds the object it will be removed and true will be returned. The state of the Hash Table will be updated.


### void makeEmpty();

makeEmpty will remove all objects residing in the Hash Table resetting size to zero. The state of the Hash Table will be changed when calling this function. No return value is provided.


### int getSize() const;

getSize will return a constant integer value for the number of objects currently inside the Hash Table. The state of the Hash Table is not changed from this function call.


### bool isEmpty();

isEmpty will return true if the current number of items in the Hash Table is zero and false otherwise. The state of the Hash Table is not changed from this function call.


### float loadFactor() const;

Load Factor is important concept in Hash Tables and gives insight into how full the table has become. This function will return the Load Factor at any point it is called. The state of the Hash Table is not changed from this function call.

###  int findCollisions() const;

findCollision will return the number of collisions that have occured so far in the Hash Table. The state of the Hash Table is not changed from this function call.


## Hash

The Hash class is where we define our Hash function. The templated class is known as a functor because the main behavior of the class is being used as a hash function itself. The approach is to simply define a member function of the class that overrides the operator() behavior. In our main hash class, this function is only defined and then overridden for particular template arguments. We chose to include the Hash header in the header file of the class we need to implement the particular hash function in.


## Car 

The Car object demonstrates several concepts in C++ programming. It has several constructors, a destructor, operator overloading, makes use of lvalues and rvalues, friend functions for printing, getters and setters, separation of declaration and implementation, and finally implements the Strategy Design pattern.

In the strategy pattern, the car object has a DriveStrategy. DriveStrategy is an interface the specifies a contract that all concrete implementations of the interface must uphold. The concrete classes RearWheelDrive, FrontWheelDrive, and AllWheelDrive implement the DriveStrategy Interface.

When we instantiate a car object we pass a pointer to particular concrete implementation. This passing of the object into our constructor function is known as dependency injection.

Depending on the object passed we can expect different behavior from our Car object. This is an example of Polymorphism. The car object also has the necessary functions implemented to make it hashable and can be used with our separate chained Hash table data structure.


## Birthday Paradox

In a group of n people, what is the probability two people have the same birthday? People think that the chances of someone having the same birthday increase linearly with the amount of people, however this is not the case. The actual probability increases exponentially:

1 - (364 &frasl; 365)<sup>n(n-1) %fras1 2</sup>

We can generalize the Birthday Paradox to hashing and the importance of dealing with collisions within a hashtable.Despite numbers having a random probability of occuring in a certain range, the probability that another number randomly generated will match that number is not a linear function. 

The simulateBirthdayParadox function within the Driver simulates the probability of there being a collision of birthdays in a hash table. The function uses a Birthdate object and the HashTable objects our team has developed. To effectively simulate the Birthday Paradox, the BirthDate object does not call the actual hash function - instead the day in the year of the birthday (from Jan. 1st) is returned to emulate people having their birthdays on the same day. The simulateBrithdayParadox function gets a number of people from the user and then outputs the **actual** probability and **simulated** probability (randomly generating **n** BirthDate objects, putting these birthdays in a hashtable, and running 1000 times).

### BirthDate

The BirthDate class also includes many concepts in c++ programming, including operator overloading, random number generation, and handling of dates. The class includes getters, a copy constructor and a friend function that overloads the ostream operator.

To make these objects more personable, a random name is generated with each birthday in the default constructor. The age of the person is also calculated as well, assuming that today's date is 05/31/2021 (to make calculations simpler).


# Outcome of Project

From the start of the assignment, we encouraged each member to make the success of the project a shared responsibility and a team effort. We created a discord server to communicate and frequently used Zoom to meet digitally. Every team member was responsive and helpful in each stage of the assignment. 

The goal of the project was to create a Separate Chained Hash Table and to cover C++ programming concepts we each found interesting. Because of this open goal, our project captures many diverse perspectives of using a Hash Table. 

By the rubric of learning and teamwork, the project exceeded early expectations. The Data structure was properly implemented and many deeper concepts explored. Team members assisted each other in design, debugging, and environment setup.

The lessons learned throughout the process facilitated a better understanding of Hashing. One area the team encountered was the benefits and limitations of using the data members of each class as the key. 

In our implementation of the Hash Table, the class only takes an object and then does hashing directly based on the functor's implementation. Each function would look at the data members of the class to generate the hash.

In other implementations frequently the HashTable class will take two template arguments for a key-value pair. The benefit is that searching and retrieving items are decoupled from the object itself.


# Contributing Members

Ben Neal
- Car class, Project Setup

Benjamin Liden
- HashTable Iterator, HashTable Member Functions

Erin Middlemas
- Birthday Paradox, HashTable Member Functions

Noura Almasri
- Car class, HashTable Member Functions

## License
[MIT](https://choosealicense.com/licenses/mit/)

