#include <iostream>
#include <string>
#include <list>
#include <cmath> 
#include <algorithm> 
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel{

    // MagicalContainer :

    // Default constructor
    MagicalContainer::MagicalContainer():
    data(list<int>()){} // Initialize the data member as an empty list

    // Add an element to the container
    void MagicalContainer::addElement(int element){

        cout << "Adding " << element << endl; 

        data.push_back(element); // Add the element to the back of the container
        data.sort(); // Sort the container in ascending order
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element){

        if (data.empty()) throw runtime_error("Error: The container is empty"); // Throw an error if the container is empty

        auto iter = find(data.begin(), data.end(), element); // Find the iterator pointing to the element in the container

        if (iter == data.end()) throw runtime_error("Error: Element not found"); // Throw an error if the element is not found

        cout << "Removing " << element << endl;

        data.erase(iter); // Erase the element from the container
    }

    // Get the size of the container
    int MagicalContainer::size() const {

        cout << "The size of the container is: " << data.size() << endl;

        return data.size(); // Return the size of the container
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // AscendingIterator:

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator(): 
    ascendingIteratorConteiner(*(new MagicalContainer())), // Create a new MagicalContainer and initialize the reference
    iterator(ascendingIteratorConteiner.data.begin()){} // Set the iterator to the beginning of the container

    // Constructor with container reference
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container): 
    ascendingIteratorConteiner(container), // Initialize the reference to the container
    iterator(ascendingIteratorConteiner.data.begin()){} // Set the iterator to the beginning of the container

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other): 
    ascendingIteratorConteiner(other.ascendingIteratorConteiner), // Copy the container reference
    iterator(other.iterator){} // Copy the iterator

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){}

    // Copy assignment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){

        if (&ascendingIteratorConteiner != &other.ascendingIteratorConteiner) throw std::runtime_error("Error: Different container");

        iterator = other.iterator; // Copy the iterator
        return *this; // Return the updated iterator
    }

    // Equality comparison operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return iterator == other.iterator; // Compare the iterators for equality
    }

    // Inequality comparison operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return iterator != other.iterator; // Compare the iterators for inequality
    }

    // Greater than comparison operator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return *iterator > *other.iterator; // Compare the values pointed by the iterators
    }

    // Less than comparison operator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return *iterator < *other.iterator; // Compare the values pointed by the iterators
    } 

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const {
        return *iterator; // Return the value pointed by the iterator
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {

        if(iterator == ascendingIteratorConteiner.data.end()) throw runtime_error("Error: Out of bounds"); // Throw an error if the iterator is already at the end

        ++iterator; // Increment the iterator to move to the next element

        return *this; // Return the updated iterator
    }

    // Begin iterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){

        AscendingIterator iterator(ascendingIteratorConteiner); // Create a new iterator object with the same container reference

        if (!(ascendingIteratorConteiner.data.empty())) iterator.iterator = ascendingIteratorConteiner.data.begin(); // Set the iterator to the beginning of the container if it's not empty

        return iterator; // Return the iterator
    }

    // End iterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){

        AscendingIterator iter(ascendingIteratorConteiner); // Create a new iterator object with the same container reference
        iter.iterator = ascendingIteratorConteiner.data.end(); // Set the iterator to the end of the container
        return iter; // Return the iterator
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // SideCrossIterator:

    // Default constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(): 
    sideCrossIteratorContainer(*(new MagicalContainer())), // Create a new MagicalContainer and initialize the reference
    _left(sideCrossIteratorContainer.data.end()), // Initialize _left iterator to the end of the container
    _right(sideCrossIteratorContainer.data.end()), // Initialize _right iterator to the end of the container
    forward(false){} // Set forward flag to false

    // Constructor with container reference
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): 
    sideCrossIteratorContainer(container), // Initialize the reference to the container
    _left(sideCrossIteratorContainer.data.end()), // Initialize _left iterator to the end of the container
    _right(sideCrossIteratorContainer.data.end()), // Initialize _right iterator to the end of the container
    forward(false){ // Set forward flag to false

        if (!(container.data.empty())){
            _left = container.data.begin(); // Set _left iterator to the beginning of the container
            _right = prev(container.data.end()); // Set _right iterator to the last element of the container
            forward = true; // Set forward flag to true
        }
    }

    // Constructor with parameters
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, list<int>::iterator letf_it, std::list<int>::iterator right_it, bool is_forward):
    sideCrossIteratorContainer(container),
    _left(letf_it), // Initialize _left iterator with the provided iterator
    _right(right_it), // Initialize _right iterator with the provided iterator
    forward(is_forward){} // Set forward flag to the provided value

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other): 
    sideCrossIteratorContainer(other.sideCrossIteratorContainer), // Copy the container reference
    _left(other._left), // Copy _left iterator
    _right(other._right), // Copy _right iterator
    forward(other.forward){} // Copy the forward flag

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    // Assignment operator
    MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){

        if (&sideCrossIteratorContainer != &other.sideCrossIteratorContainer) throw runtime_error("Error: Different container"); // Check for different containers

        if (this != &other) {
            sideCrossIteratorContainer = other.sideCrossIteratorContainer; // Copy the container
            _left = other._left; // Copy _left iterator
            _right = other._right; // Copy _right iterator
            forward = other.forward; // Copy the forward flag
        }

        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return (_left == other._left) && (_right == other._right) && (forward == other.forward); // Compare _left, _right, and forward flags for equality
    }

    // Inequality comparison operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other); // Negate the equality comparison result
    }

    // Greater than comparison operator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return *_left > *other._left; // Compare the values pointed by the _left iterators
    }

    // Less than comparison operator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return *_left < *other._left; // Compare the values pointed by the _left iterators
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const {
        if (forward) return *_left; // Return the value pointed by _left if forward is true
        else return *_right; // Otherwise, return the value pointed by _right
    }

    // Pre-increment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){

        if (_left == sideCrossIteratorContainer.data.end()) throw runtime_error("Error: Out of bounds"); // If iterator is already at the end throw an exception

        if (_left == _right){
            _left = sideCrossIteratorContainer.data.end(); // Set _left iterator to the end of the container
            _right = sideCrossIteratorContainer.data.end(); // Set _right iterator to the end of the container
            forward = false; // Set forward flag to false
            return *this;
        }

        if (forward) ++_left; // Increment _left iterator if forward is true
        else --_right; // Decrement _right iterator if forward is false

        forward = !forward; // Toggle the value of forward flag
        return *this; // Return the updated iterator
    }

    // Begin iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){

        if (sideCrossIteratorContainer.data.empty()) return end(); // If the container is empty, return end iterator

        return SideCrossIterator(sideCrossIteratorContainer, sideCrossIteratorContainer.data.begin(), prev(sideCrossIteratorContainer.data.end()), true); // Return a SideCrossIterator starting at the beginning of the container
    }

    // End iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){

        return SideCrossIterator(sideCrossIteratorContainer, sideCrossIteratorContainer.data.end(), sideCrossIteratorContainer.data.end(), false); // Return a SideCrossIterator pointing to the end of the container
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // PrimeIterator:

    // Check if a number is prime
    bool MagicalContainer::PrimeIterator::isPrime(int number){

        if (number < 2) return false; // Numbers less than 2 are not prime

        for (int i = 2; i <= sqrt(number); i++) { // Iterate from 2 to the square root of the number
            if (number % i == 0) return false; // If the number is divisible by any value in the range, it is not prime
        }

        return true; // The number is prime if no divisors are found
    }

    // Default constructor
    MagicalContainer::PrimeIterator::PrimeIterator(): 
    primeIteratorContainer(*(new MagicalContainer())), // Create a new MagicalContainer and initialize the reference
    iterator(primeIteratorContainer.data.begin()){} // Set iterator to the beginning of the container

    // Constructor with container reference
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container): 
    primeIteratorContainer(container), // Initialize the reference to the container
    iterator(primeIteratorContainer.data.begin()){

        while((iterator != primeIteratorContainer.data.end()) && (!isPrime(*iterator))) ++iterator; // Find the first prime number in the container
    }

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other): 
    primeIteratorContainer(other.primeIteratorContainer), // Copy the container reference
    iterator(other.iterator){} // Copy the iterator

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator(){}

    // Assignment operator
    MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){

        if (&primeIteratorContainer != &other.primeIteratorContainer) throw runtime_error("Error: Different container"); // Check for different containers

        iterator = other.iterator; // Copy the iterator
        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {

        return iterator == other.iterator; // Compare the iterators for equality
    }

    // Inequality comparison operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {

        return !(*this == other); // Negate the equality comparison result
    }

    // Greater than comparison operator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {

        auto this_iterator = iterator;
        auto other_iterator = other.iterator;

        for(;(this_iterator != primeIteratorContainer.data.end()) && (other_iterator != other.primeIteratorContainer.data.end()); ++this_iterator , ++other_iterator){

            if (*this_iterator > *other_iterator) return true; // Compare the values pointed by the iterators
            else if (*this_iterator < *other_iterator) return false;

        }
        return (this_iterator == primeIteratorContainer.data.end() && other_iterator != other.primeIteratorContainer.data.end());
    }

    // Less than comparison operator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {

        return *iterator < *other.iterator; // Compare the values pointed by the iterators
    }

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const {

        return *iterator; // Return the value pointed by the iterator
    }


    // Pre-increment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){

        if(iterator == primeIteratorContainer.data.end()) throw runtime_error("Error: Out of bounds"); // Throw an error if the iterator is already at the end

        ++iterator; // Increment the iterator

        while((iterator != primeIteratorContainer.data.end()) && (!isPrime(*iterator))) ++iterator; // Find the next prime number in the container

        return *this; // Return the updated iterator
    }

    // Begin iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){

        return PrimeIterator(primeIteratorContainer); // Return a PrimeIterator starting at the beginning of the container
    }

    // End iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {

        PrimeIterator iter(primeIteratorContainer); // Create a new PrimeIterator object with the container reference
        iter.iterator = primeIteratorContainer.data.end(); // Set the iterator to the end of the container
        return iter; // Return the end iterator
    }
}