# CSC240GroupLab


The goal of the project is to create a Hash Table that can handle different objects and evenly distribute them throughout a vector. The focus is to reinforce programming concepts and excel in a team-oriented environment. The program itself will provide the following public member functions that are expected to be both accurate and efficient in their execution.


## Usage


    explicit HashTable(int hashTableSize = 11); 
    bool contains(const T& obj) const;
    bool insert(const T& obj);
    bool remove(const T& obj);
    void makeEmpty();
    int getSize() const;


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





## Contributing Members

Ben Neal

Benjamin Liden

Erin Middlemas

Noura Almasri

## License
[MIT](https://choosealicense.com/licenses/mit/)

