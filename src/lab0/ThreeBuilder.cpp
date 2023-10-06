//
// Created by Иван Березуцкий on 05.10.2023.
//

#include "ThreeBuilder.h"
#include "vector.h"

ThreeBuilder &ThreeBuilder::data(unsigned char *value) {
    if (value == nullptr) {
        throw std::invalid_argument("Null is not permitted value");
    }

    size_t size;
    while (value[size] != '\0') {
        size++;
    }

    object._digits = Vector<unsigned char>(size);

    for (size_t i = 0; i < size; i++) {
        object._digits[i] = value[i];
    }
    return *this;
}

ThreeBuilder &ThreeBuilder::size(size_t value) {
    object._digits = value;
    return *this;
}

Three ThreeBuilder::build() {
    return object;
}