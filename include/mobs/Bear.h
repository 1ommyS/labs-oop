#pragma once;
#include "iostream"
namespace mobs {
class Bear : public NPC {
  public:
   void accept(Battle* battle) override { battle->fight(this); }
   void sayHello() override { std::cout << "hello, im bear"; }
};

}  // namespace mobs
