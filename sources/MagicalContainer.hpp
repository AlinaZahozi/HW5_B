#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include <list>
#include <cmath> 
#include <algorithm> 

using namespace std;

namespace ariel {

    class MagicalContainer {

        private:

            list<int> data; // List to store elements

        public:

            // Default constructor
            MagicalContainer();

            // Add an element to the container
            void addElement(int element);

            // Remove an element from the container
            void removeElement(int element);

            // Get the size of the container
            int size() const;

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
            list<int>::const_iterator iterator;

        public:

            // Default constructor
            AscendingIterator();

            // Constructor with container reference
            AscendingIterator(MagicalContainer &container);

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
            list<int>::iterator _left;
            list<int>::iterator _right;
            bool forward; 

        public:

            // Default constructor
            SideCrossIterator();

            // Constructor with container reference
            SideCrossIterator(MagicalContainer &container);

            // Constructor with parameters
            SideCrossIterator(MagicalContainer &container, list<int>::iterator letf_it, std::list<int>::iterator right_it, bool forward);

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
            list<int>::const_iterator iterator;

            bool isPrime(int number);

        public:
        
            // Default constructor
            PrimeIterator();

            // Constructor with container reference
            PrimeIterator(const MagicalContainer &container);

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