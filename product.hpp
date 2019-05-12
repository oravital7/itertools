#pragma once

namespace itertools
{

template <typename T1, typename T2>
class Itproduct
{

private:
    std::pair<T1, T2> a;
    std::pair<T1, T2> b;

public:
    Itproduct(std::pair<T1, T2> a, std::pair<T1, T2> b) : a(a), b(b) {}

    class iterator
    {
    private:
        std::pair<T1, T2> it;
        std::pair<T2, T2> b;

    public:
        iterator(std::pair<T1, T2> it, std::pair<T2, T2> b) : it(it), b(b) {}

        std::pair<T1, T2> &operator*()
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
            this->b.first = other.b.first;
            this->b.second = other.b.second;
            return *this;
        }

        // ++i;
        iterator &operator++()
        {
            it.second++;
            if (it.second == b.second)
            {
                it.first++;
                it.second = b.first;
            }
            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            it.second++;
            if (it.second == b.second)
            {
                it.first++;
                it.second = b.first;
            }
            return tmp;
        }
    };

public:
    auto begin()
    {
        return iterator{a, std::pair<T2, T2>(a.second, b.second)};
    }

    auto end()
    {
        return iterator{std::pair<T1, T2>(b.first, b.second), std::pair<T2, T2>(a.second, b.second)};
    }
};

template <typename T1, typename T2>
auto product(T1 a, T2 b)
{
    std::pair<decltype(a.begin()), decltype(b.begin())> aPair(a.begin(), b.begin());
    std::pair<decltype(a.end()), decltype(b.end())> bPair(a.end(), b.end());

    return Itproduct<decltype(a.begin()), decltype(b.begin())>(aPair, bPair);
}

} // namespace itertools
