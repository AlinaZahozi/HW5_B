#include <iostream>
#include <string>
#include <list>
#include <cmath> //
#include <algorithm> //
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel{

    //
    MagicalContainer::MagicalContainer():
    data(list<int>()){}

    //
    void MagicalContainer::addElement(int element){
        
        auto it = lower_bound(data.begin(), data.end(), element); //
        data.insert(it, element); //
        cout << "Add " << element << endl;

        if (isPrime(element)) {
            primeNumbers.clear();
            size_t i = 0;
            for (const auto& num : data) {
                if (isPrime(num)) {
                    primeNumbers.push_back(i);
                }
                i++;
            }
        }
    }


    // 
    bool MagicalContainer::isPrime(int number) const {
        if(number < 2) return false;
        for(int i = 2 ; i <= sqrt(number) ; i++){
            if(number % i == 0) return false;
        }
        return true;
    }


    //
    void MagicalContainer::removeElement(int element){

        if(data.empty()) throw runtime_error("Error: The container is empty");

        for (auto i = data.begin(); i != data.end(); i++ ) {
            if(*i == element){
                cout << "Remove " << to_string(*i) << endl;
                data.erase(i);
                return;
            }
        }
        throw runtime_error("Error: Element not found");
    }

    //
    size_t MagicalContainer::size() const {
        return data.size();
    }

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator(): 
    ascendingIteratorConteiner(*(new MagicalContainer())),
    index(0){}

    //
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container): 
    ascendingIteratorConteiner(container), 
    index(0){}

    //
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t index): 
    ascendingIteratorConteiner(container), 
    index(index){}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other): 
    ascendingIteratorConteiner(other.ascendingIteratorConteiner), 
    index(other.index){}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Copy assignment operator
    MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if (this != &other) {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        return *this;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if (*this == this->end()) {
            throw std::runtime_error("Got to the end of the container");
        }
        ++index;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        auto it = ascendingIteratorConteiner.data.begin();
        std::advance(it, index);
        return *it;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return index > other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return index < other.index;
    }

    // This function returns an instance of this iterator in the first index of the container
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        if (ascendingIteratorConteiner.size() == 0) {
            throw std::runtime_error("Container is empty!");
        }
        return AscendingIterator(ascendingIteratorConteiner, 0);
    }

    // This function returns an instance of this iterator in the last index of the container
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        return AscendingIterator(ascendingIteratorConteiner, ascendingIteratorConteiner.size());
    }

    // ------------------------------------------------SideCrossIterator functions--------------------------------------------------
    // Constructors

    // Default constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator()
        : sideCrossIteratorContainer(*(new MagicalContainer())), startIndex(0), endIndex(0), flag(true) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : sideCrossIteratorContainer(container), startIndex(0), endIndex(container.size()), flag(true) {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, size_t startIndex, size_t endIndex, bool flag)
        : sideCrossIteratorContainer(container), startIndex(startIndex), endIndex(endIndex), flag(flag) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
        : sideCrossIteratorContainer(other.sideCrossIteratorContainer),
        startIndex(other.startIndex),
        endIndex(other.endIndex),
        flag(other.flag) {}


    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if (this != &other) {
            sideCrossIteratorContainer = other.sideCrossIteratorContainer;
            startIndex = other.startIndex;
            endIndex = other.endIndex;
            flag = other.flag;
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        // Check which index to return according to the "isFront" variable
        if (flag) {
            auto it = sideCrossIteratorContainer.data.begin();
            std::advance(it, startIndex);
            return *it;
        }
        else {
            if (endIndex != sideCrossIteratorContainer.size()) {
                auto it = sideCrossIteratorContainer.data.begin();
                std::advance(it, endIndex);
                return *it;
            }
            else {
                auto it = sideCrossIteratorContainer.data.begin();
                std::advance(it, endIndex - 1);
                return *it;
            }
        }
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (*this == this->end()) {
            throw std::runtime_error("Reached the end");
        }

        if (!flag) {
            if (startIndex + 1 < endIndex) {
                ++startIndex;
                flag = !flag;
            }
            else if (startIndex + 1 == endIndex) {
                ++startIndex;
            }
            else {
                flag = false;
            }
        }
        else {
            if (startIndex < endIndex - 1) {
                --endIndex;
                flag = !flag;
            }
            else if (startIndex == endIndex - 1) {
                --endIndex;
            }
            else {
                flag = true;
            }
        }

        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return (startIndex == other.startIndex) && (endIndex == other.endIndex);
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return (startIndex > other.startIndex) || (endIndex < other.endIndex);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return (startIndex < other.startIndex) || (endIndex > other.endIndex);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        if (sideCrossIteratorContainer.size() == 0) {
            throw std::runtime_error("Container is empty!");
        }

        return SideCrossIterator(sideCrossIteratorContainer, 0, sideCrossIteratorContainer.size(), true);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        size_t middleIndex = sideCrossIteratorContainer.size() / 2;
        size_t endIndex = middleIndex;
        return SideCrossIterator(sideCrossIteratorContainer, middleIndex, endIndex, true);
    }

    // ------------------------------------------------PrimesIterator functions--------------------------------------------------
    // Constructors

    // Default constructor
    MagicalContainer::PrimeIterator::PrimeIterator()
        : primeIteratorContainer(*(new MagicalContainer())), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container, size_t index)
        : primeIteratorContainer(container), index(index) {}

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
        : primeIteratorContainer(other.primeIteratorContainer),
        index(other.index) {}


    MagicalContainer::PrimeIterator& ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if (this != &other) {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        return *this;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
        : primeIteratorContainer(container), index(0) {
    }

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    int MagicalContainer::PrimeIterator::operator*() const {
        size_t current = static_cast<size_t>(primeIteratorContainer.primeNumbers[index]);
        auto it = primeIteratorContainer.data.begin();
        std::advance(it, current);
        return *it;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if (*this == this->end()) {
            throw std::runtime_error("Reached the end");
        }
        ++index;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return index > other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return index < other.index;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        if (primeIteratorContainer.size() == 0) {
            throw std::runtime_error("Container is empty!");
        }
        return PrimeIterator(primeIteratorContainer, 0);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        return PrimeIterator(primeIteratorContainer, primeIteratorContainer.primeNumbers.size());
    }
}