// #ifndef MAGICALCONTAINER_HPP
// #define MAGICALCONTAINER_HPP
// #include <vector>

// namespace ariel
// {
//     class MagicalContainer
//     {
//     private:
//         std::vector<int> _elements;

//     public:
//         // MagicalContainer(){}
//         // ~MagicalContainer() = default;
//         void addElement(int element)
//         {
//             _elements.push_back(element);
//         }
//         void removeElement(int element)
//         {
//         }
//         int size() const
//         {
//             return _elements.size();
//         }

//         class AscendingIterator
//         {
//         private:
//             const MagicalContainer &_container;
//             int _currentIndex;

//         public:
//             AscendingIterator(const MagicalContainer &cont) : _container(cont), _currentIndex(0) {}
//             ~AscendingIterator() = default;
//             AscendingIterator begin() const
//             {
//                 // return nullptr;
//                 return AscendingIterator(_container);
//             }
//             AscendingIterator end() const
//             {
//                 // AscendingIterator iter(_container);
//                 // iter._currentIndex = _container.size();
//                 // return iter;
//                 return AscendingIterator(_container);
//             }

//             bool operator==(const AscendingIterator &other) const
//             {
//                 return true;
//             }
//             bool operator!=(const AscendingIterator &other) const
//             {
//                 return true;
//             }
//             bool operator>(const AscendingIterator &other) const
//             {
//                 return true;
//             }
//             bool operator<(const AscendingIterator &other) const
//             {
//                 return true;
//             }
//             int operator*() const
//             {
//                 return _container._elements[static_cast<std::vector<int>::size_type>(_currentIndex)];
//             }
//             AscendingIterator &operator++()
//             {
//                 ++_currentIndex;
//                 return *this;
//             }
//         };

//         class SideCrossIterator
//         {
//         private:
//             const MagicalContainer &_container;
//             int _currentIndex;

//         public:
//             SideCrossIterator(const MagicalContainer &cont) : _container(cont), _currentIndex(0) {}
//             ~SideCrossIterator() = default;
//             SideCrossIterator begin() const
//             {
//                 return SideCrossIterator(_container);
//             }
//             SideCrossIterator end() const
//             {
//                 SideCrossIterator iter(_container);
//                 iter._currentIndex = _container.size();
//                 return iter;
//             }

//             bool operator==(const SideCrossIterator &other) const
//             {
//                 return true;
//             }
//             bool operator!=(const SideCrossIterator &other) const
//             {
//                 return true;
//             }
//             bool operator>(const SideCrossIterator &other) const
//             {
//                 return true;
//             }
//             bool operator<(const SideCrossIterator &other) const
//             {
//                 return true;
//             }
//             int operator*() const
//             {
//                 return 2;
//             }
//             SideCrossIterator &operator++()
//             {
//                 ++_currentIndex;
//                 return *this;
//             }
//         };

//         class PrimeIterator
//         {
//         private:
//             const MagicalContainer &_container;
//             int _currentIndex;

//         public:
//             PrimeIterator(const MagicalContainer &cont) : _container(cont), _currentIndex(0) {}
//             ~PrimeIterator() = default;
//             PrimeIterator begin() const
//             {
//                 return PrimeIterator(_container);
//             }
//             PrimeIterator end() const
//             {
//                 PrimeIterator iter(_container);
//                 iter._currentIndex = _container.size();
//                 return iter;
//             }

//             bool operator==(const PrimeIterator &other) const
//             {
//                 return true;
//             }
//             bool operator!=(const PrimeIterator &other) const
//             {
//                 return true;
//             }
//             bool operator>(const PrimeIterator &other) const
//             {
//                 return true;
//             }
//             bool operator<(const PrimeIterator &other) const
//             {
//                 return true;
//             }
//             int operator*() const
//             {
//                 return 3;
//             }
//             PrimeIterator &operator++()
//             {
//                 ++_currentIndex;
//                 return *this;
//             }
//         };
//     };
// }

// #endif

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