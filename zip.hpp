#pragma once

namespace itertools
{

template<typename T1, typename T2>
class Itzip {

    private:
    std::pair<T1,T2> a;
    std::pair<T1,T2> b;

    public:
    Itzip(pair<T1,T2> a, pair<T1,T2> b) : a(a) , b(b) {}



    class iterator {
        std::pair<T1,T2> it;

        iterator(std::pair<T1,T2> it)
    }
};



}