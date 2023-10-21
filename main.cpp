#include <iostream>
#include "Trapezoid.h"

using namespace std;

int main() {
    Vector<Point> p{Point(0, 0), Point(1, 1), Point(2, 5), Point(3, 4)};

    Trapezoid th = Trapezoid(p);
    cout << th.CalculateArea() << endl;
}