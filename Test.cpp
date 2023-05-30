#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;

MagicalContainer createTestContainer()
{
    ariel::MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    return container;
}

TEST_CASE("Empty container")
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator ascIter(container);
    CHECK(*ascIter.begin() == *ascIter.end());
    CHECK(container.size() == 0);
}

TEST_CASE("Test addElement, removeElement and size")
{
    MagicalContainer container;

    container.addElement(4);
    container.addElement(97);
    container.addElement(8);
    CHECK(container.size() == 3);

    container.removeElement(8);
    CHECK(container.size() == 2);

    /* The size of the container is not affected by adding existing elements */
    container.addElement(4);        // Element already exists
    container.addElement(97);       // Element already exists
    CHECK(container.size() == 2);   

    container.removeElement(97);
    container.removeElement(4);
    CHECK(container.size() == 0);
}

TEST_CASE("Testing Iterators")
{
    MagicalContainer container = createTestContainer();

    SUBCASE("Test AscendingIterator")
    {
        string resultAsc;
        MagicalContainer::AscendingIterator ascIter(container);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
            resultAsc += to_string(*it) + " ";

        CHECK(resultAsc == "2 3 9 17 25 ");
    }

    SUBCASE("Test SideCrossIterator")
    {
        string resultCross;
        MagicalContainer::SideCrossIterator crossIter(container);
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
            resultCross += to_string(*it) + " ";

        CHECK(resultCross == "2 25 3 17 9 ");
    }

    SUBCASE("Test PrimeIterator")
    {
        string resultPrime;
        MagicalContainer::PrimeIterator primeIter(container);
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
            resultPrime += to_string(*it) + " ";

        CHECK(resultPrime == "2 3 17 ");
    }
}

TEST_CASE("Removing elements that do not exist")
{
    MagicalContainer container;
    CHECK_THROWS(container.removeElement(4));
    
    container.addElement(17);
    CHECK_NOTHROW(container.removeElement(17));
    CHECK_THROWS(container.removeElement(17));

    container.addElement(2);
    container.addElement(2);
    CHECK_NOTHROW(container.removeElement(2));
    CHECK_THROWS(container.removeElement(2));
}

// TEST_CASE("Illegal use of operators")
// {
//     MagicalContainer container = createTestContainer();
//     MagicalContainer::AscendingIterator ascIter(container);
//     MagicalContainer::SideCrossIterator crossIter(container);
//     MagicalContainer::PrimeIterator primeIter(container);

//     SUBCASE("Operators for iterators of different types")
//     {
//         CHECK_THROWS(*ascIter.begin() < *crossIter.begin());
//         CHECK_THROWS(*ascIter.begin() > *crossIter.begin());
//         CHECK_THROWS(*ascIter.begin() == *primeIter.begin());
//         CHECK_THROWS(*crossIter.begin() != *primeIter.begin());
//     }

//     SUBCASE("Identical iterators containing different containers")
//     {
//         MagicalContainer container_2 = createTestContainer();
//         MagicalContainer::AscendingIterator ascIter_2(container_2);
//         auto it = ascIter_2.begin();
//         CHECK_THROWS(*ascIter.begin() == *it);
//         CHECK_THROWS(*ascIter.begin() < *++it);
//         CHECK_THROWS(*ascIter.begin() != *it);
//     }
// }

TEST_CASE("Checking operators")
{
    MagicalContainer container = createTestContainer();
    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::PrimeIterator primeIter(container);

    SUBCASE("AscendingIterator operators")
    {
        // 2 3 9 17 25
        auto it_1 = ascIter.begin();
        auto it_2 = ascIter.begin();
        CHECK(*it_1 < *++it_2);     // 2 < 3
        CHECK(*++it_1 == *it_2);    // 3 == 3
        CHECK(*++it_1 > *it_2);     // 9 > 3
        CHECK(*it_1 != *it_2);      // 9 != 3
    }

    SUBCASE("SideCrossIterator operators")
    {
        // 2 25 3 17 9
        auto it_1 = crossIter.begin();
        auto it_2 = crossIter.begin();
        CHECK(*it_1 < *++it_2);     // 2 < 25
        CHECK(*++it_1 < *++it_2);   // 25 < 3
        CHECK(*++it_1 == *it_2);    // 3 == 3
        CHECK(*++it_1 > *it_2);     // 17 > 3
        CHECK(*++it_1 != *it_2);    // 9 != 3 
    }

    SUBCASE("PrimeIterator operators")
    {
        // 2 3 17
        auto it_1 = primeIter.begin();
        auto it_2 = primeIter.begin();
        CHECK(*it_1 < *++it_2);     // 2 < 3
        CHECK(*++it_1 == *it_2);    // 3 == 3
        CHECK(*++it_1 > *it_2);     // 17 > 3
        CHECK(*it_1 != *it_2);      // 17 != 3
    }
}
