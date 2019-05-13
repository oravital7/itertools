#pragma once

namespace itertools
{

template <typename T1, typename T2>
class Itchain
{

private:
    std::pair<T1, T1> a;
    std::pair<T2, T2> b;

public:
    Itchain(std::pair<T1, T1> a, std::pair<T2, T2> b) : a(a), b(b) {}

    class iterator
    {
    private:
        std::pair<T1, T1> aPoint;
        std::pair<T2, T2> bPoint;
        bool first;

    public:
        iterator(std::pair<T1, T1> a, std::pair<T2, T2> b, bool first) : aPoint(a), bPoint(b)
        {
            this->first = first;
        }

        auto &operator*()
        {
            if (first)
                return *aPoint.first;
            return *bPoint.first;
        }

        bool operator==(const iterator &other) const
        {
            if (first)
                return aPoint.first == other.aPoint.second;
            return bPoint.first == other.bPoint.second;
        }

        bool operator!=(const iterator &other) const
        {

            if (first)
                return aPoint.first != other.aPoint.second;
            return bPoint.first != other.bPoint.second;
        }

        iterator &operator=(const iterator &other)
        {
            aPoint = other.aPoint;
            bPoint = other.bPoint;
            first = other.first;
            return *this;
        }

        // ++i;
        iterator &operator++()
        {
            if (first)
            {
                if (++aPoint.first == aPoint.second)
                    first = false;

                return *this;
            }
            bPoint.first++;
            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            if (first)
            {
                if (++aPoint.first == aPoint.second)
                    first = false;
                return *this;
            }
            bPoint.first++;
            return tmp;
        }
    };

public:
    auto begin() const
    {
        return iterator{a, b, true};
    }

    auto end() const
    {
        return iterator{a, b, false};
    }
};

template <typename T1, typename T2>
auto chain(T1 a, T2 b)
{
    std::pair<decltype(a.begin()), decltype(a.end())> aPair(a.begin(), a.end());
    std::pair<decltype(b.begin()), decltype(b.end())> bPair(b.begin(), b.end());

    return Itchain<decltype(a.begin()), decltype(b.begin())>(aPair, bPair);
}

} // namespace itertools