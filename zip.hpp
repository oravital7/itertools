#pragma once

namespace itertools
{

template <typename T1, typename T2>
class Itzip
{

private:
    std::pair<T1, T2> a;
    std::pair<T1, T2> b;

public:
    Itzip(std::pair<T1, T2> a, std::pair<T1, T2> b) : a(a), b(b) {}

    class iterator
    {
    private:
        std::pair<T1, T2> it;

    public:
        iterator(std::pair<T1, T2> it) : it(it) {}

        pair<T1,T2> &operator*()
        {
            return it;
        }

        bool operator==(const iterator &other) const
        {
            return it.first == other.it.first;
        }

        bool operator!=(const iterator &other) const
        {
            return it.first != other.it.first;
        }

        iterator &operator=(const iterator &other)
        {
            this->it.first = other.it.first;
            this->it.second = other.it.second;
            return *this;
        }

        // ++i;
        iterator &operator++()
        {
            it.first++;
            it.second++;
            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            it.first++;
            it.second++;
            return tmp;
        }
    };

public:
    auto begin()
    {
        return iterator{a};
    }

    auto end()
    {
        return iterator{b};
    }
};


template <typename T1, typename T2>
auto zip(T1 a, T2 b)
{
    std::pair<decltype(a.begin()), decltype(b.begin())> aPair(a.begin(), b.begin());
    std::pair<decltype(a.end()), decltype(b.end())> bPair(a.end(), b.end());
    return Itzip<decltype(a.begin()), decltype(b.begin())>(aPair, bPair);
}

} // namespace itertools

template <typename T1, typename T2> 
ostream& operator<<(ostream &os, std::pair<T1, T2> &a)
{
    os << *a.first << "," << *a.second;
    return os;
}
