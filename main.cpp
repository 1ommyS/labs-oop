#include <iostream>
#include "Three.h"

using namespace std;

int main() {
   Three three = Three::builder().withDigits("210").build();
   three.print();
}