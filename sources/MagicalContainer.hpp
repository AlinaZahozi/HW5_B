#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

namespace ariel {

    class MagicalContainer {

        private:

            list<int> data; // List to store elements
            vector<int> primeNumbers; // Vector to store prime numbers

        public:

            // Default constructor
            MagicalContainer();

            // Add an element to the container
            void addElement(int element);

            // Remove an element from the container
            void removeElement(int element);

            // Get the size of the container
            size_t size() const;

            // Check if a number is prime
            bool isPrime(int number) const;

            // Iterator class for iterating in ascending order
            class AscendingIterator;

            // Iterator class for iterating in a side-cross pattern
            class SideCrossIterator;

            // Iterator class for iterating over prime numbers
            class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator {

        private:

            MagicalContainer &ascendingIteratorConteiner; // Reference to the container being iterated
            size_t index; // Current index of the iterator

        public:

            // Default constructor
            AscendingIterator();

            // Constructor with container reference
            AscendingIterator(MagicalContainer &container);

            // Constructor with container reference and starting index
            AscendingIterator(MagicalContainer &container, size_t index);

            // Copy constructor
            AscendingIterator(const AscendingIterator &other);

            // Destructor
            ~AscendingIterator();

            // Assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);

            // Equality comparison operator
            bool operator==(const AscendingIterator &other) const;

            // Inequality comparison operator
            bool operator!=(const AscendingIterator &other) const;

            // Greater than comparison operator
            bool operator>(const AscendingIterator &other) const;

            // Less than comparison operator
            bool operator<(const AscendingIterator &other) const;

            // Dereference operator
            int operator*() const;

            // Pre-increment operator
            AscendingIterator &operator++();

            // Begin iterator
            AscendingIterator begin();

            // End iterator
            AscendingIterator end();
    };

    class MagicalContainer::SideCrossIterator {

        private:

            MagicalContainer &sideCrossIteratorContainer; // Reference to the container being iterated
            size_t currentIndex; // Current index of the iterator
            size_t startIndex; // Starting index of the iteration
            size_t endIndex; // Ending index of the iteration
            bool flag; // Flag to determine the direction of iteration

        public:

            // Default constructor
            SideCrossIterator();

            // Constructor with container reference
            SideCrossIterator(MagicalContainer &container);

            // Constructor with container reference, start index, end index, and flag
            SideCrossIterator(MagicalContainer &container, size_t startIndex, size_t endIndex, bool flag);

            // Copy constructor
            SideCrossIterator(const SideCrossIterator &other);

            // Destructor
            ~SideCrossIterator();

            // Assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);

            // Equality comparison operator
            bool operator==(const SideCrossIterator &other) const;

            // Inequality comparison operator
            bool operator!=(const SideCrossIterator &other) const;

            // Greater than comparison operator
            bool operator>(const SideCrossIterator &other) const;

            // Less than comparison operator
            bool operator<(const SideCrossIterator &other) const;

            // Dereference operator
            int operator*() const;

            // Pre-increment operator
            SideCrossIterator &operator++();

            // Begin iterator
            SideCrossIterator begin();

            // End iterator
            SideCrossIterator end();
    };

    class MagicalContainer::PrimeIterator {

        private:

            const MagicalContainer &primeIteratorContainer; // Reference to the container being iterated
            size_t index; // Current index of the iterator

        public:
        
            // Default constructor
            PrimeIterator();

            // Constructor with container reference
            PrimeIterator(const MagicalContainer &container);

            // Constructor with container reference and starting index
            PrimeIterator(const MagicalContainer &container, size_t index);

            // Copy constructor
            PrimeIterator(const PrimeIterator &other);

            // Destructor
            ~PrimeIterator();

            // Assignment operator
            PrimeIterator &operator=(const PrimeIterator &other);

            // Equality comparison operator
            bool operator==(const PrimeIterator &other) const;

            // Inequality comparison operator
            bool operator!=(const PrimeIterator &other) const;

            // Greater than comparison operator
            bool operator>(const PrimeIterator &other) const;

            // Less than comparison operator
            bool operator<(const PrimeIterator &other) const;

            // Dereference operator
            int operator*() const;

            // Pre-increment operator
            PrimeIterator &operator++();

            // Begin iterator
            PrimeIterator begin();

            // End iterator
            PrimeIterator end();
    };
}