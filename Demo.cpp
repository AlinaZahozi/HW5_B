#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;

int main() {

    cout << "\nMy Demo:\n\n";

    // Create a MagicalContainer and add some elements
    MagicalContainer container;

    for(int i = 1 ; i <= 11 ; i++){
        container.addElement(i);
    }

    int size = container.size();

    // Use AscendingIterator to display elements in ascending order
    cout << "Elements in ascending order:\n";

    MagicalContainer::AscendingIterator iterator(container);

    for (auto it = iterator.begin(); it != iterator.end(); ++it) {
        cout << *it << ' ';   // 1 2 3 4 5 6 7 8 9 10 11
    }
    cout << endl;

    // Use DescendingIterator to display elements in descending order
    cout << "Elements in cross order:\n";

    MagicalContainer::SideCrossIterator crossIter(container);

    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 1 11 2 10 3 9 4 8 5 7 6
    }
    cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    cout << "Prime numbers:\n";

    MagicalContainer::PrimeIterator primeIter(container);

    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        cout << *it << ' ';  // 2 3 5 7 11
    }
    cout << std::endl;

    // Remove an element from the container and display the size
   for(int i = 1 ; i <= 11 ; i++){
        container.removeElement(i);
        container.size();
    }

    return 0;
}
