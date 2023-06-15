#include "MagicalContainer.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

namespace ariel {

    // Default Constructor
    MagicalContainer::MagicalContainer() {}


    // Method to add an element to the container
    void MagicalContainer::addElement(int newItem) {
        dataVector.push_back(newItem);
    }

    // Method to remove an element from the container
    void MagicalContainer::removeElement(int targetItem) {
        for(auto it = dataVector.begin(); it != dataVector.end(); ++it){
            if (*it == targetItem) {
                dataVector.erase(it);
                return;
            }
        }
        throw std::out_of_range("Item not found in the container");
    }

    // Method to return the size of the container
    size_t MagicalContainer::size() const {
        return dataVector.size();
    }

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator()
        : iterScope(*(new MagicalContainer())), curIndex(0) {}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &src)
        : iterScope(src.iterScope), curIndex(src.curIndex) {}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Assignment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &src) {
        if (this != &src) {
            iterScope = src.iterScope;
            curIndex = src.curIndex;
        }
        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return (curIndex == other.curIndex);
    }

    // Inequality comparison operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return (curIndex != other.curIndex);
    }

    // Greater-than comparison operator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        return (curIndex > other.curIndex);
    }

    // Less-than comparison operator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return (curIndex < other.curIndex);
    }

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const {
        if (curIndex >= iterScope.size()) {
            throw std::out_of_range("Iterator is out of range");
        }
        return iterScope.dataVector[curIndex];
    }

    // Prefix increment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        ++curIndex;
        return *this;
    }

    // Returns an iterator pointing to the first element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(iterScope);
    }

    // Returns an iterator pointing one past the last element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        return AscendingIterator(iterScope, iterScope.size());
    }

    // Construct an iterator associated with a container
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &scope)
        : iterScope(scope), curIndex(0) {}

    // Construct an iterator associated with a container with a current index
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &scope, size_t curIndex)
        : iterScope(scope), curIndex(curIndex) {}

    // Method to sort elements in ascending order
    void MagicalContainer::AscendingIterator::sortAscending() {
        std::sort(iterScope.dataVector.begin(), iterScope.dataVector.end());
    }

    // Default constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator()
        : iterScope(*(new MagicalContainer())), curIdx(0), startIdx(0), endIdx(0), isBeginning(true) {}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &src)
        : iterScope(src.iterScope), curIdx(src.curIdx), startIdx(src.startIdx), endIdx(src.endIdx), isBeginning(src.isBeginning) {}

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Assignment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &src) {
        if (this != &src) {
            iterScope = src.iterScope;
            curIdx = src.curIdx;
            startIdx = src.startIdx;
            endIdx = src.endIdx;
            isBeginning = src.isBeginning;
        }
        return *this;
    }

    // Method to arrange elements in a specific pattern
    void MagicalContainer::SideCrossIterator::arrangeSideCross(MagicalContainer &scope) {
        size_t size = scope.size();
        if (size < 4) {
            throw std::length_error("Insufficient elements in the container");
        }
        startIdx = 0;
        endIdx = size - 1;
        isBeginning = true;
        curIdx = startIdx;
    }

    // Equality comparison operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        return (curIdx == other.curIdx);
    }

    // Inequality comparison operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return (curIdx != other.curIdx);
    }

    // Greater-than comparison operator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        return (curIdx > other.curIdx);
    }

    // Less-than comparison operator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return (curIdx < other.curIdx);
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const {
        if (curIdx >= iterScope.size()) {
            throw std::out_of_range("Iterator is out of range");
        }
        return iterScope.dataVector[curIdx];
    }

    // Prefix increment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        if (isBeginning) {
            ++curIdx;
            if (curIdx >= endIdx) {
                curIdx = startIdx + 1;
                isBeginning = false;
            }
        } else {
            --curIdx;
            if (curIdx <= startIdx) {
                curIdx = endIdx - 1;
                isBeginning = true;
            }
        }
        return *this;
    }

    // Returns an iterator pointing to the first element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        SideCrossIterator it(iterScope);
        it.arrangeSideCross(iterScope);
        return it;
    }

    // Returns an iterator pointing one past the last element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        return SideCrossIterator(iterScope, startIdx, endIdx, !isBeginning);
    }

    // Construct an iterator associated with a container
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &scope)
        : iterScope(scope), curIdx(0), startIdx(0), endIdx(0), isBeginning(true) {}

    // Construct an iterator associated with a container with a current index, start index, end index, and direction of traversal
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &scope, size_t startIdx, size_t endIdx, bool isBeginning)
        : iterScope(scope), curIdx(startIdx), startIdx(startIdx), endIdx(endIdx), isBeginning(isBeginning) {}


    // Default constructor
    MagicalContainer::PrimeIterator::PrimeIterator()
    : iterScope(*(new MagicalContainer())), curIdx(0) {}

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& src)
    : iterScope(src.iterScope), curIdx(src.curIdx) {}

    // Construct an iterator associated with a container
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& scope)
    : iterScope(scope), curIdx(0) {}

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Assignment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& src) {
    if (this != &src) throw std::runtime_error("Error");
    return *this;
    }


    // Equality comparison operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        return (curIdx == other.curIdx);
    }

    // Inequality comparison operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return (curIdx != other.curIdx);
    }

    // Greater-than comparison operator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        return (curIdx > other.curIdx);
    }

    // Less-than comparison operator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return (curIdx < other.curIdx);
    }

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const {
        if (curIdx >= iterScope.size()) {
            throw std::out_of_range("Iterator is out of range");
        }
        return iterScope.dataVector[curIdx];
    }

    // Prefix increment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        ++curIdx;
        while (curIdx < iterScope.size()) {
            if (isPrime(iterScope.dataVector[curIdx])) {
                break;
            }
            ++curIdx;
        }
        return *this;
    }

    // Returns an iterator pointing to the first element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return PrimeIterator(iterScope);
    }

    // Returns an iterator pointing one past the last element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        return PrimeIterator(iterScope, iterScope.size());
    }

    // Construct an iterator associated with a container with a current index
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &scope, size_t curIdx)
        : iterScope(scope), curIdx(curIdx) {}

    // Method to check if a number is prime
    bool MagicalContainer::PrimeIterator::isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

