#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP
#include <vector>
#include <cmath>
#include <stdexcept>

namespace ariel
{
    class MagicalContainer
    {
        std::vector<int> elements;

    public:
        void addElement(int element)
        {
            elements.push_back(element);
        }

        void removeElement(int element)
        {
        }

        unsigned int size() const
        {
            return elements.size();
        }

        class AscendingIterator
        {
            const MagicalContainer &container;
            unsigned int currentIndex;

        public:
            AscendingIterator(const MagicalContainer &cont) : container(cont), currentIndex(0) {}

            bool operator!=(const AscendingIterator &other) const
            {
                return currentIndex != other.currentIndex;
            }

            bool operator==(const AscendingIterator &other) const
            {
                return currentIndex == other.currentIndex;
            }

            bool operator>(const AscendingIterator &other) const
            {
                return currentIndex > other.currentIndex;
            }

            bool operator<(const AscendingIterator &other) const
            {
                return currentIndex < other.currentIndex;
            }

            int operator*() const
            {
                if (currentIndex >= container.size())
                {
                    throw std::out_of_range("Iterator out of range");
                }
                return container.elements[currentIndex];
            }

            AscendingIterator &operator++()
            {
                ++currentIndex;
                return *this;
            }

            AscendingIterator begin() const
            {
                return AscendingIterator(container);
            }

            AscendingIterator end() const
            {
                AscendingIterator iter(container);
                iter.currentIndex = container.size();
                return iter;
            }
        };

        class SideCrossIterator
        {
            const MagicalContainer &container;
            unsigned int currentIndex;
            bool reverse;

        public:
            SideCrossIterator(const MagicalContainer &cont, bool rev = false)
                : container(cont), currentIndex(0), reverse(rev) {}

            bool operator!=(const SideCrossIterator &other) const
            {
                return currentIndex != other.currentIndex;
            }

            bool operator==(const SideCrossIterator &other) const
            {
                return currentIndex == other.currentIndex;
            }

            bool operator>(const SideCrossIterator &other) const
            {
                return currentIndex > other.currentIndex;
            }

            bool operator<(const SideCrossIterator &other) const
            {
                return currentIndex < other.currentIndex;
            }

            int operator*() const
            {
                if (currentIndex >= container.size())
                {
                    throw std::out_of_range("Iterator out of range");
                }
                return container.elements[currentIndex];
            }

            SideCrossIterator &operator++()
            {
                if (reverse)
                {
                    --currentIndex;
                }
                else
                {
                    ++currentIndex;
                }
                return *this;
            }

            SideCrossIterator begin() const
            {
                return SideCrossIterator(container, false);
            }

            SideCrossIterator end() const
            {
                SideCrossIterator iter(container, true);
                iter.currentIndex = container.size() - 1;
                return iter;
            }
        };

        class PrimeIterator
        {
            const MagicalContainer &container;
            unsigned int currentIndex;

            static bool isPrime(int number)
            {
                if (number < 2)
                {
                    return false;
                }
                for (int i = 2; i <= std::sqrt(number); ++i)
                {
                    if (number % i == 0)
                    {
                        return false;
                    }
                }
                return true;
            }

        public:
            PrimeIterator(const MagicalContainer &cont) : container(cont), currentIndex(0)
            {
                while (currentIndex < container.size() && !isPrime(container.elements[currentIndex]))
                {
                    ++currentIndex;
                }
            }

            bool operator!=(const PrimeIterator &other) const
            {
                return currentIndex != other.currentIndex;
            }

            bool operator==(const PrimeIterator &other) const
            {
                return currentIndex == other.currentIndex;
            }

            bool operator>(const PrimeIterator &other) const
            {
                return currentIndex > other.currentIndex;
            }

            bool operator<(const PrimeIterator &other) const
            {
                return currentIndex < other.currentIndex;
            }

            int operator*() const
            {
                if (currentIndex >= container.size())
                {
                    throw std::out_of_range("Iterator out of range");
                }
                return container.elements[currentIndex];
            }

            PrimeIterator &operator++()
            {
                ++currentIndex;
                while (currentIndex < container.size() && !isPrime(container.elements[currentIndex]))
                {
                    ++currentIndex;
                }
                return *this;
            }

            PrimeIterator begin() const
            {
                return PrimeIterator(container);
            }

            PrimeIterator end() const
            {
                PrimeIterator iter(container);
                iter.currentIndex = container.size();
                return iter;
            }
        };
    };
}
#endif