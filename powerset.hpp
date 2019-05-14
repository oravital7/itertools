#pragma once

#include <iostream>

namespace itertools
{
template <typename T>
class Itpowerset
{
private:
   const T a;

public:
    Itpowerset(const T &a) : a(a) {}

    class iterator
    {
        std::pair<T, uint> it;

    public:
        iterator(std::pair<T, uint> it) : it(it) {}

        std::pair<T, uint> &operator*()
        {
            return it;
        }

        bool operator==(const iterator &other) const
        {
            return it.second == other.it.second;
        }

        bool operator!=(const iterator &other) const
        {
            return it.second != other.it.second;
        }

        iterator &operator=(const iterator &other)
        {
            it.first = other.it.first;
            it.second = other.it.second;
            return *this;
        }

        // ++i;
        iterator &operator++()
        {
            it.second++;
            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            it.second++;
            return tmp;
        }
    };

public:
    auto begin() const
    {
        return iterator{std::pair<T, uint>(a, 0)};
    }

    auto end() const
    {
        int i = 1;
        auto it = a.begin();
        while (it != a.end())
        {
            i = i << 1;
            it++;
        }
        return iterator{std::pair<T, uint>(a, i)};
    }
};

template <typename T>
auto powerset(T a)
{
    return Itpowerset<T>(a);
}

} // namespace itertools

template <typename T1>
std::ostream &operator<<(std::ostream &os, std::pair<T1, uint> &a)
{
    os << "{";
    auto it = a.first.begin();
    auto end = a.first.end();
    int i = 1;
    bool first = true;
    while (it != end)
    {
        if (i & a.second)
        {
            if (!first)
                os << ",";
                
            os << *it;
            first = false;
        }
        it++;
        i = i << 1;
    }
    os << "}";
    return os;
}
