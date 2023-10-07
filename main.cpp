#include <iostream>
#include "converters.h"
#include "three.h"

using namespace std;

int main() {

    Three three1 = Three(110);
    Three three2 = Three(102);
    Three result = three1 + three2;
    cout << result << endl;
    return 0;
}