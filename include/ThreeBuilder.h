//
// Created by Иван Березуцкий on 05.10.2023.
//

#pragma once

#include "three.h"


class ThreeBuilder {
private:
    Three object;

public:
    ThreeBuilder() = default;

    ThreeBuilder &data(unsigned char *value);

    ThreeBuilder &size(size_t value);

    Three build();
};


