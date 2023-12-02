#pragma once

#include <utility>
#include <sstream>

#include "../battleMap/Position.h"
#include "ISerializable.h"


namespace Mobs {
    class NPC : public ISerializable {
    protected:
        std::string _name;
    public:
        NPC(int32_t x, int32_t y, std::string _name) : _name(std::move(_name)) {
            position = Position(x, y);
        };

        Position position;

        virtual void Die();

        virtual ~NPC() = default;

        std::string Serialize() override {
            std::ostringstream oss;
            oss << position.GetX() << " " << position.GetY() << " " << _name;
            return oss.str();
        }

        // Реализация метода десериализации
        void Deserialize(const std::string &fileName) override {
            std::istringstream iss(fileName);
            std::string x, y;
            iss >> x >> y >> _name;
            position = Position(std::stoi(x), std::stoi(y));
        }
    };
}

