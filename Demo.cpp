#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;

int main() {

    cout << "\nMy Demo:\n\n";

    // Create a MagicalContainer
    MagicalContainer container;

    for(int i = 1 ; i <= 11 ; i++){
        container.addElement(i); // Add elements 1 to 11 to the container
    }

    int size = container.size(); // Get the size of the container

    // Use AscendingIterator to display elements in ascending order
    cout << "Elements in ascending order:\n";

    MagicalContainer::AscendingIterator iterator(container); // Create an AscendingIterator with the container

    for (auto it = iterator.begin(); it != iterator.end(); ++it) {
        cout << *it << ' ';   // Print each element in ascending order: 1 2 3 4 5 6 7 8 9 10 11
    }
    cout << endl;

    // Use DescendingIterator to display elements in cross order
    cout << "Elements in cross order:\n";

    MagicalContainer::SideCrossIterator crossIter(container); // Create a SideCrossIterator with the container

    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // Print each element in cross order: 1 11 2 10 3 9 4 8 5 7 6
    }
    cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    cout << "Prime numbers:\n";

    MagicalContainer::PrimeIterator primeIter(container); // Create a PrimeIterator with the container

    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        cout << *it << ' ';  // Print each prime number: 2 3 5 7 11
    }
    cout << std::endl;

    // Remove an element from the container and display the size
    for(int i = 1 ; i <= 11 ; i++){
        container.removeElement(i); // Remove elements 1 to 11 from the container
        container.size(); // Get the updated size of the container
    }

    return 0;
}
