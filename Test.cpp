#include <iostream>

#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"

using namespace itertools;

int main()
{
    int grade = 0, check = 0;
    badkan::TestCase testCase("Contains");
    string expected = "";

    int arr[11];
    for (int i = 0; i <= 10; i++)
    {
        arr[i] = i;
    }

    for (auto i : range(0, 11))
    {
        testCase.CHECK_EQUAL(i, arr[i]);
    }

    for (auto i : chain(range(0, 6), range(6, 11)))
    {
        testCase.CHECK_EQUAL(i, arr[i]);
    }

    for (auto i : chain(chain(range(0, 3), range(3, 6)),chain(range(6, 8), range(8, 11))))
    {
        testCase.CHECK_EQUAL(i, arr[i]);
    }

    for (auto i : range(99, 102))
    {
        expected += to_string(i);
    }

    testCase.CHECK_EQUAL(expected == "99100101", true);
    expected = "";

    for (auto i : range('a', 'z'))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 25);

    check = 0;
    for (auto i : powerset(string("abcba")))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 32);

    check = 0;
    for (auto i : powerset(chain(range(10, 11), range(100, 101))))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 4);

    check = 0;
    for (auto i : powerset(chain(range(10, 10), range(100, 100))))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 1);

    std::stringstream buffer;
    for (auto i : zip(range(10, 13), string("aaa")))
    {
        buffer << i;
    }
    buffer >> expected;
    testCase.CHECK_EQUAL(expected == "10,a11,a12,a", true);

    buffer.clear();
    expected = "";

    for (auto i : chain(string("aaa"), string("aaa")))
    {
        buffer << i;
    }
    buffer >> expected;

    buffer.clear();
    expected = "";
    check = 0;
    for (auto i : product(string("aaa"), string("aaa")))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 9);

    check = 0;
    for (auto i : product(range('a', 'd'), range('a', 'd')))
    {
        check++;
    }

    testCase.CHECK_EQUAL(check, 9);

    check = 0;
    for (auto i : zip(range(-0.5, 3.5), range(-1, 3)))
    {
        check++;
        buffer << i;
    }
    buffer >> expected;
    testCase.CHECK_EQUAL(expected == "-0.5,-10.5,01.5,12.5,2", true);

    buffer.clear();
    check = 0;
    for (auto i : powerset(range(-0.5, 10.5)))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 2048);

    check = 0;
    for (auto i : powerset(string("")))
    {
        buffer << i;
    }
    expected = "";
    buffer >> expected;

    testCase.CHECK_EQUAL(expected == "{}", true);

    check = 0;
    buffer.clear();
    for (auto i : powerset(string("1")))
    {
        buffer << i;
    }
    expected = "";
    buffer >> expected;

    testCase.CHECK_EQUAL(expected == "{}{1}", true);


    check =0;
    buffer.clear();
    for (auto i : zip(zip(range(0,5),range(5,10)),zip(range(0,5),range(5,10))))
    {
        check++;
        buffer << i;
    }
    expected = "";
    buffer >> expected;
    testCase.CHECK_EQUAL(expected=="0,5,0,51,6,1,62,7,2,73,8,3,84,9,4,9", true);

    check =0;
    buffer.clear();
    for (auto i : zip(zip(range(0,5),range(5,10)),zip(range('a','f'),range('a','f'))))
    {
        check++;
        buffer << i;
    }
    expected = "";
    buffer >> expected;
    testCase.CHECK_EQUAL(expected=="0,5,a,a1,6,b,b2,7,c,c3,8,d,d4,9,e,e", true);

    check = 0;
    for (auto i : product(chain(range(-0.5, 10.5),range(0,5)),chain(range('a', 'f'),range('a','f'))))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 160);

    check = 0;
    for (auto i : product(chain(range(-0.5, 0.5),range(0,0)),chain(range('a', 'b'),range('a','b'))))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 2);

    check = 0;
    for (auto i : product(range(0,0),range(0,0)))
    {
        check++;
    }
    testCase.CHECK_EQUAL(check, 0);

    check = 0;
    expected = "";
    buffer.clear();
    for (auto i : product(range(0,0),range(0,1)))
    {
        check++;
        buffer << i;
    }
    buffer >> expected;
    testCase.CHECK_EQUAL(check, 0);
    testCase.CHECK_EQUAL(expected=="", true);


    grade = testCase.grade();

    std::cout << "*** Grade: " << grade << " ***" << std::endl;

    return 0;
}