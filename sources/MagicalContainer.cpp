#include <iostream>
#include <string>
#include <list>
#include <cmath> 
#include <algorithm> 
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel{

    // Default constructor
    MagicalContainer::MagicalContainer():
    data(list<int>()),
    primeNumbers(vector<int>()){}

    // Add an element to the container
    void MagicalContainer::addElement(int element) {

        cout << "Adding " << element << endl;

        auto num = lower_bound(data.begin(), data.end(), element); // Find the position to insert the element
        data.insert(num, element); // Insert the element at the found position

        if (isPrime(element)) { // If the added element is prime
            primeNumbers.clear(); // Clear the vector of prime numbers
            size_t i = 0;
            for (const auto& num : data) {
                if (isPrime(num)) primeNumbers.push_back(i); // Rebuild the vector of prime numbers
                i++;
            }
        }
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {

        if (data.empty()) throw runtime_error("Error: The container is empty"); // Throw an error if the container is empty

        for (auto i = data.begin(); i != data.end(); i++) { // Iterate through the elements in the container
            if (*i == element) { // If the current element matches the specified element
                cout << "Removing " << to_string(*i) << endl; // Print the element being removed
                data.erase(i); // Erase the element from the container
                return;
            }
        }
        throw runtime_error("Error: Element not found"); // Throw an error if the element is not found in the container
    }

    // Get the size of the container
    size_t MagicalContainer::size() const {
        return data.size();
    }

    // Check if a number is prime
    bool MagicalContainer::isPrime(int number) const {

        if (number < 2) return false; // Numbers less than 2 are not prime

        for (int i = 2; i <= sqrt(number); i++) { // Iterate from 2 to the square root of the number
            if (number % i == 0) return false; // If the number is divisible by any value in the range, it is not prime
        }

        return true; // The number is prime if no divisors are found
    }

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator(): 
    ascendingIteratorConteiner(*(new MagicalContainer())),
    index(0){}

    // Constructor with container reference
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container): 
    ascendingIteratorConteiner(container), 
    index(0){}

    // Constructor with container reference and starting index
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t index): 
    ascendingIteratorConteiner(container), 
    index(index){}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other): 
    ascendingIteratorConteiner(other.ascendingIteratorConteiner), 
    index(other.index){}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){}

    // Copy assignment operator
    MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){

        if (this != &other) throw std::runtime_error("Error: Wrong container");

        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return index == other.index;
    }

    // Inequality comparison operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    // Greater than comparison operator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return index > other.index;
    }

    // Less than comparison operator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return index < other.index;
    } 

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const {

        auto num = ascendingIteratorConteiner.data.begin(); // Get the iterator to the beginning of the container

        advance(num, index); // Move the iterator to the current index

        return *num; // Dereference and return the value at the current index
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {

        if(*this == this->end()) throw std::runtime_error("Error: Out of bounds"); // Throw an error if the iterator is already at the end

        ++index; // Increment the index to move to the next element

        return *this; // Return the updated iterator
    }

    // Begin iterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){

        if (ascendingIteratorConteiner.size() == 0) throw std::runtime_error("Error: The container is empty");

        return AscendingIterator(ascendingIteratorConteiner, 0);
    }

    // End iterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){

        return AscendingIterator(ascendingIteratorConteiner, ascendingIteratorConteiner.size());
    }

    // Default constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(): 
    sideCrossIteratorContainer(*(new MagicalContainer())), 
    startIndex(0), endIndex(0), 
    flag(true){}

    // Constructor with container reference
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container): 
    sideCrossIteratorContainer(container), 
    startIndex(0), 
    endIndex(container.size()), 
    flag(true){}

    // Constructor with container reference, start index, end index, and flag
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, size_t startIndex, size_t endIndex, bool flag): 
    sideCrossIteratorContainer(container), 
    startIndex(startIndex), 
    endIndex(endIndex), 
    flag(flag){}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other): 
    sideCrossIteratorContainer(other.sideCrossIteratorContainer),
    startIndex(other.startIndex),
    endIndex(other.endIndex),
    flag(other.flag){}

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    // Assignment operator
    MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){

        if (this != &other) {
            sideCrossIteratorContainer = other.sideCrossIteratorContainer;
            startIndex = other.startIndex;
            endIndex = other.endIndex;
            flag = other.flag;
            throw std::runtime_error("Error: Wrong container");
        }
        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {

        return (startIndex == other.startIndex) && (endIndex == other.endIndex);
    }

    // Inequality comparison operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {

        return !(*this == other);
    }

    // Greater than comparison operator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {

        return (startIndex > other.startIndex) || (endIndex < other.endIndex);
    }
    
    // Less than comparison operator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {

        return (startIndex < other.startIndex) || (endIndex > other.endIndex);
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const {

        if(flag){
            auto it = sideCrossIteratorContainer.data.begin(); // Get an iterator pointing to the beginning of the container
            advance(it, startIndex); // Move the iterator to the startIndex position
            return *it; // Dereference and return the value at the iterator position
        }
        else{
            auto it = sideCrossIteratorContainer.data.begin(); // Get an iterator pointing to the beginning of the container
            size_t index = (endIndex != sideCrossIteratorContainer.size()) ? endIndex : endIndex - 1;
            // If endIndex is not the last index, set index to endIndex - otherwise, set it to endIndex - 1
            advance(it, index); // Move the iterator to the determined index position
            return *it; // Dereference and return the value at the iterator position
        }
    }
    
    // Pre-increment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){

        if (*this == this->end()) throw std::runtime_error("Error: Out of bounds"); // If iterator is already at the end throw an exception

        if(!flag){
            if (startIndex + 1 < endIndex) { // If there is more than one element between startIndex and endIndex
                ++startIndex; // Increment startIndex
                flag = !flag; // Toggle the flag value
            }
            else if(startIndex + 1 == endIndex) ++startIndex; // If there is only one element between startIndex and endIndex -  increment startIndex
            else flag = false; // Set flag to false
        }
        else { // If flag is true
            if(startIndex < endIndex - 1){ // If there is more than one element between startIndex and endIndex
                --endIndex; // Decrement endIndex
                flag = !flag; // Toggle the flag value
            }
            else if(startIndex == endIndex - 1) --endIndex; // If there is only one element between startIndex and endIndex - decrement endIndex
            else flag = true; // Set flag to true
        }
        return *this; // Return the updated iterator
    }

    // Begin iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){

        if (sideCrossIteratorContainer.size() == 0) throw std::runtime_error("Error: The container is empty");

        return SideCrossIterator(sideCrossIteratorContainer, 0, sideCrossIteratorContainer.size(), true);
    }

    // End iterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){

        size_t middleIndex = sideCrossIteratorContainer.size() / 2; // Calculate the middle index of the container

        size_t endIndex = middleIndex; // Set the endIndex to the middleIndex

        return SideCrossIterator(sideCrossIteratorContainer, middleIndex, endIndex, true);
        // Create and return a SideCrossIterator object with the container, middleIndex, endIndex, and the flag set to true
    }


    // Default constructor
    MagicalContainer::PrimeIterator::PrimeIterator(): 
    primeIteratorContainer(*(new MagicalContainer())), 
    index(0){}

    // Constructor with container reference
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container): 
    primeIteratorContainer(container), 
    index(0){}

    // Constructor with container reference and starting index
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container, size_t index): 
    primeIteratorContainer(container), 
    index(index){}

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other): 
    primeIteratorContainer(other.primeIteratorContainer),
    index(other.index){}

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator(){}

    // Assignment operator
    MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){

        if (this != &other) throw std::runtime_error("Error: Wrong container");

        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {

        return index == other.index;
    }

    // Inequality comparison operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {

        return !(*this == other);
    }

    // Greater than comparison operator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {

        return index > other.index;
    }

    // Less than comparison operator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {

        return index < other.index;
    }

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const {

        size_t current = static_cast<size_t>(primeIteratorContainer.primeNumbers[index]);
        // Get the current prime number's index and cast it to size_t type

        auto num = primeIteratorContainer.data.begin();
        // Get an iterator pointing to the beginning of the container

        advance(num, current);
        // Move the iterator to the position indicated by the current prime number index

        return *num;
        // Dereference and return the value at the iterator position
    }


    // Pre-increment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){

        if (*this == this->end()) throw std::runtime_error("Error: Out of bounds");

        ++index;

        return *this;
    }

    // Begin iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){

        if (primeIteratorContainer.size() == 0) throw std::runtime_error("Error: The container is empty");

        return PrimeIterator(primeIteratorContainer, 0);
    }

    // End iterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {

        return PrimeIterator(primeIteratorContainer, primeIteratorContainer.primeNumbers.size());
        // Create and return a primeIteratorContainer object with the container and primeNumbers size
    }
}