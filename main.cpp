#include <iostream>
#include "three.h"

using namespace std;

int main() {
   Three three = Three::builder().withDigits(210).build();
   three.print();
}