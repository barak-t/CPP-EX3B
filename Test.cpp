#include <sstream>

#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("check") {
    CHECK_NOTHROW(Fraction(5, 3));
    CHECK_THROWS( Fraction(5, 0));

    Fraction a(5,3);
    Fraction b(5,3);
    Fraction b1(10,6);
    Fraction c(10, 3);
    Fraction d(9, 3);

    CHECK(a+b == c);
    CHECK(a > 1);
    CHECK(1 < a);
    CHECK(a < 2);
    CHECK(2 > a);
    CHECK(a < c);
    CHECK(c > a);
    CHECK(a == b);
    CHECK(a == b1);
    CHECK(b1 == b);
    CHECK(d == 3);
    CHECK(3 == d);
    CHECK_EQ(a*2, c);
}

TEST_CASE("cin and cout"){

    Fraction a(5,3);
    Fraction d(9, 3);

    Fraction cin_1;
    //cin
    stringstream ss_in1("5 3");
    ss_in1 >> cin_1;
    CHECK((a == cin_1) == true);

    //cin
    stringstream ss_in2("1");
    Fraction f1;
    CHECK_THROWS(ss_in2 >> f1);

    stringstream ss_in3("1/4");
    Fraction f2;
    CHECK_THROWS(ss_in3 >> f2);

    //cout
    stringstream ss_out1;
    ss_out1 << a;
    CHECK(ss_out1.str() == "5/3");

    stringstream ss_out2;
    ss_out2 << d;
    CHECK(ss_out2.str() == "3/1");

}
