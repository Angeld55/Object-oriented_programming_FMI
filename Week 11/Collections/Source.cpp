#include <iostream>
#include "Collection.h"
#include "Set.h"
#include "NormalCollection.h"
#include "SortedCollection.h"
#include "IntervalCollection.h"
#include <chrono>

void testPerformance(Collection* collection) {
    std::srand(std::time(nullptr));

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 50000; ++i) {
        int randomNumber = std::rand() % 10000 + 1; 
        collection->add(randomNumber);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;
    std::cout << "Time taken to add 10000 random elements: " << elapsedTime.count() << " seconds" << std::endl;

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i) {
        int randomNumber = std::rand() % 10000 + 1; 
        collection->remove(randomNumber);
    }
    end = std::chrono::steady_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken to remove 5000 random elements: " << elapsedTime.count() << " seconds" << std::endl;

    int randomQueryNumber = std::rand() % 10000 + 1; 
    start = std::chrono::steady_clock::now();
    unsigned count = collection->count(randomQueryNumber);
    end = std::chrono::steady_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken to count occurrences of random element: " << elapsedTime.count() << " seconds" << std::endl;

    randomQueryNumber = std::rand() % 10000 + 1; 
    start = std::chrono::steady_clock::now();
    bool contains = collection->contains(randomQueryNumber);
    end = std::chrono::steady_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken to check if random element is contained: " << elapsedTime.count() << " seconds" << std::endl;
}

int main()
{
    Collection* c1 = new IntervalCollection(100, 1000);
    Collection* c2 = new NormalCollection();
    Collection* c3 = new SortedCollection();
    Collection* c4 = new Set(NORMAL_COLLECTION);
    Collection* c5 = new Set(SORTED_COLLECTION);

    testPerformance(c1);
    std::cout << std::endl;

    testPerformance(c2);
    std::cout << std::endl;

    testPerformance(c3);
    std::cout << std::endl;

    testPerformance(c4);
    std::cout << std::endl;

    testPerformance(c5);    
    std::cout << std::endl;

}