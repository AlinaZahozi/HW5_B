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
    data(list<int>()){}

    // Add an element to the container
    void MagicalContainer::addElement(int element){
        
        cout << "Adding " << element << endl;

        data.push_back(element);
        data.sort();
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {

        if (data.empty()) throw runtime_error("Error: The container is empty"); // Throw an error if the container is empty

        auto iter = find(data.begin(), data.end(), element);
        if (iter == data.end()) throw runtime_error("Error: Element not found");

        cout << "Removing " << element << endl;

        data.erase(iter);
    }

    // Get the size of the container
    int MagicalContainer::size() const {

        cout << "The size of the container is: " << data.size() << endl;

        return data.size();
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // AscendingIterator: 

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator(): 
    ascendingIteratorConteiner(*(new MagicalContainer())),
    iterator(ascendingIteratorConteiner.data.begin()){}

    // Constructor with container reference
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container): 
    ascendingIteratorConteiner(container), 
    iterator(ascendingIteratorConteiner.data.begin()){}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other): 
    ascendingIteratorConteiner(other.ascendingIteratorConteiner), 
    iterator(other.iterator){}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){}

    // Copy assignment operator
    MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){

        if (this != &other) throw std::runtime_error("Error: Different container");

        iterator = other.iterator;
        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return iterator == other.iterator;
    }

    // Inequality comparison operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return iterator != other.iterator;
    }

    // Greater than comparison operator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return *iterator > *other.iterator;
    }

    // Less than comparison operator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return *iterator < *other.iterator;
    } 

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const {
        return *iterator;
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {

        if(iterator == ascendingIteratorConteiner.data.end()) throw runtime_error("Error: Out of bounds"); // Throw an error if the iterator is already at the end

        ++iterator; // Increment the index to move to the next element

        return *this; // Return the updated iterator
    }

    // Begin iterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){

        AscendingIterator iterator(ascendingIteratorConteiner);

        if (!(ascendingIteratorConteiner.data.empty())) iterator.iterator = ascendingIteratorConteiner.data.begin();

        return iterator;
    }

    // End iterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){

        AscendingIterator iter(ascendingIteratorConteiner);
        iter.iterator = ascendingIteratorConteiner.data.end();
        return iter;

    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // SideCrossIterator: 

    // Default constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(): 
    sideCrossIteratorContainer(*(new MagicalContainer())), 
    _left(sideCrossIteratorContainer.data.end()),
    _right(sideCrossIteratorContainer.data.end()),
    forward(false){}

    // Constructor with container reference
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): 
    sideCrossIteratorContainer(container), 
    _left(sideCrossIteratorContainer.data.end()),
    _right(sideCrossIteratorContainer.data.end()),
    forward(false){

        if (!(container.data.empty())){

            _left = container.data.begin();
            _right = prev(container.data.end());
            forward = true;
        }
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, list<int>::iterator letf_it, std::list<int>::iterator right_it, bool is_forward):
    sideCrossIteratorContainer(container),
    _left(letf_it),
    _right(right_it), 
    forward(is_forward){}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other): 
    sideCrossIteratorContainer(other.sideCrossIteratorContainer),
    _left(other._left),
    _right(other._right),
    forward(other.forward){}

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    // Assignment operator
    MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){

        if (&sideCrossIteratorContainer != &other.sideCrossIteratorContainer) throw runtime_error("Error: Different container");

        if (this != &other) {
            sideCrossIteratorContainer = other.sideCrossIteratorContainer;
            _left = other._left;
            _right = other._right;
            forward = other.forward;
        }

        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {

        return (this->_left == other._left) && (this->_right == other._right) && (this->forward == other.forward);
    }

    // Inequality comparison operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {

        return !(*this == other);
    }

    // Greater than comparison operator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {

        return *_left > *other._left;
    }
    
    // Less than comparison operator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {

        return *_left < *other._left;
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const {

        if (forward) return *this->_left;
        else return *this->_right;
    }
    
    // Pre-increment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){

        if (_left == sideCrossIteratorContainer.data.end()) throw runtime_error("Error: Out of bounds"); // If iterator is already at the end throw an exception

        if (this->_left == this->_right){
            this->_left = this->sideCrossIteratorContainer.data.end();
            this->_right = this->sideCrossIteratorContainer.data.end();
            this->forward = false;
            return *this;
        }

        if (forward) ++this->_left;
        else --this->_right;

        this->forward = !(this->forward);
        return *this;
    }

    // Begin iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){

        if (sideCrossIteratorContainer.data.empty()) return end();

        return SideCrossIterator(sideCrossIteratorContainer, sideCrossIteratorContainer.data.begin(), prev(sideCrossIteratorContainer.data.end()), true);
    }

    // End iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){

        return SideCrossIterator(sideCrossIteratorContainer, sideCrossIteratorContainer.data.end(), sideCrossIteratorContainer.data.end(), false);
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
    primeIteratorContainer(*(new MagicalContainer())), 
    iterator(primeIteratorContainer.data.begin()){}

    // Constructor with container reference
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container): 
    primeIteratorContainer(container), 
    iterator(primeIteratorContainer.data.begin()){

        while((iterator != primeIteratorContainer.data.end()) && (!isPrime(*iterator))) ++iterator;
    }

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other): 
    primeIteratorContainer(other.primeIteratorContainer),
    iterator(other.iterator){}

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator(){}

    // Assignment operator
    MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){

        if (&primeIteratorContainer != &other.primeIteratorContainer) throw runtime_error("Error: Different container");
        iterator = other.iterator;
        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {

        return iterator == other.iterator;
    }

    

    // Inequality comparison operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {

        return !(*this == other);
    }

    // Greater than comparison operator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {

        auto this_iterator = iterator;
        auto other_iterator = other.iterator;

        for(;(this_iterator != primeIteratorContainer.data.end()) && (other_iterator != other.primeIteratorContainer.data.end()); ++this_iterator , ++other_iterator){

            if (*this_iterator > *other_iterator)return true;
            else if (*this_iterator < *other_iterator) return false;

        }
        return (this_iterator == primeIteratorContainer.data.end() && other_iterator != other.primeIteratorContainer.data.end());
    }

    // Less than comparison operator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {

        return *iterator < *other.iterator;
    }

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const {

        return *iterator;
    }


    // Pre-increment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){

        if(iterator == primeIteratorContainer.data.end()) throw runtime_error("Error: Out of bounds"); // Throw an error if the iterator is already at the end

        ++iterator;

        while((iterator != primeIteratorContainer.data.end()) && (!isPrime(*iterator))) ++iterator;

        return *this;
    }

    // Begin iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){

        return PrimeIterator(primeIteratorContainer);
    }

    // End iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {

        PrimeIterator iter(primeIteratorContainer);
        iter.iterator = primeIteratorContainer.data.end();
        return iter;
    }
}