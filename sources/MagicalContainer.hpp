#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

namespace ariel{

    class MagicalContainer{
            
        private:

            list<int> data;
            vector<int> primeNumbers;

        public:

            //
            MagicalContainer();

            //
            void addElement(int element);

            //
            void removeElement(int element);

            //
            size_t size() const;

            //
            bool isPrime(int number) const;

            //
            class AscendingIterator;
            class SideCrossIterator;
            class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator{

        private:
        
            MagicalContainer &ascendingIteratorConteiner;
            size_t index;

        public:

            //
            AscendingIterator();

            //
            AscendingIterator(MagicalContainer &container);
            
            //
            AscendingIterator(MagicalContainer &container, size_t index);

            //
            AscendingIterator(const AscendingIterator &other);

            //
            ~AscendingIterator();

            //
            AscendingIterator &operator=(const AscendingIterator &other);

            //
            bool operator==(const AscendingIterator &other) const;

            //
            bool operator!=(const AscendingIterator &other) const;

            //
            bool operator>(const AscendingIterator &other) const;

            //
            bool operator<(const AscendingIterator &other) const;

            //
            int operator*() const;

            //
            AscendingIterator &operator++();

            //
            AscendingIterator begin();

            //
            AscendingIterator end();
    };

    class MagicalContainer::SideCrossIterator{

        private:

            MagicalContainer &sideCrossIteratorContainer;
            size_t currentIndex;
            size_t startIndex;
            size_t endIndex;
            bool flag;

        public:

            //
            SideCrossIterator();

            //
            SideCrossIterator(MagicalContainer &container);

            //
            SideCrossIterator(MagicalContainer &container, size_t startIndex, size_t endIndex, bool flag);

            //
            SideCrossIterator(const SideCrossIterator &other);

            //
            ~SideCrossIterator(); 

            //                  
            SideCrossIterator &operator=(const SideCrossIterator &other);

            //
            bool operator==(const SideCrossIterator &other) const;

            //
            bool operator!=(const SideCrossIterator &other) const;

            //
            bool operator>(const SideCrossIterator &other) const;

            //
            bool operator<(const SideCrossIterator &other) const;

            //
            int operator*() const;

            //
            SideCrossIterator &operator++();

            //
            SideCrossIterator begin();

            //
            SideCrossIterator end();
    };

    class MagicalContainer::PrimeIterator{

        private:

            const MagicalContainer &primeIteratorContainer;
            size_t index;

        public:

            //
            PrimeIterator();

            //
            PrimeIterator(const MagicalContainer &container);

            //
            PrimeIterator(const MagicalContainer &container, size_t index);

            //
            PrimeIterator(const PrimeIterator &other);

            //
            ~PrimeIterator(); 

            //                           
            PrimeIterator &operator=(const PrimeIterator &other);

            //
            bool operator==(const PrimeIterator &other) const;

            //
            bool operator!=(const PrimeIterator &other) const;

            //
            bool operator>(const PrimeIterator &other) const;

            //
            bool operator<(const PrimeIterator &other) const;

            //
            int operator*() const;

            //
            PrimeIterator &operator++();

            //
            PrimeIterator begin();

            //
            PrimeIterator end();
    };
}