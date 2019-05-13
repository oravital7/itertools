#pragma once

namespace itertools {


template<typename T>
class Itrange
{
private:
    const T a, b;

public:
    Itrange(const T &a, const T &b) : a(a), b(b) {}

    class iterator
    {
    private:
        T pointer;

    public:
        iterator(T pointer)
        {
            this->pointer = pointer;
        }

        T &operator*() 
        {
            return pointer;
        }

        bool operator==(const iterator &other) const
        {
            return pointer == other.pointer;
        }

        bool operator!=(const iterator &other) const
        {
            return pointer != other.pointer;
        }

        iterator &operator=(const iterator &other)
        {
            this->pointer = other.pointer;
            return *this;
        }

        // ++i;
        iterator &operator++()
        {
            pointer++;
            return *this;
        }

        // i++;
        const iterator operator++(int)
        {
            iterator tmp = *this;
            pointer++;
            return tmp;
        }
    };

    iterator begin() const
    {
        return iterator{a};
    }

   iterator end() const
    {
        return iterator{b};
    }

};

template<typename T> Itrange<T> range(T a, T b) {
    return Itrange<T>(a,b);
}

}