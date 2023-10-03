#include <iostream>
#include "three.h"

using namespace std;

int main() {
    Three three{122};
    cout << three << endl;
    Three three1{101};
    Three th = three - three1;
    cout << th << endl;
}