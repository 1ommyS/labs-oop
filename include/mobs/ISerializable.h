#pragma once

#include "iostream"

class ISerializable {
public:
    virtual std::string Serialize() = 0;

    virtual void Deserialize(const std::string &fileName) = 0;
};
