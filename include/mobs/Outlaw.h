#pragma once;

namespace mobs {

class Outlaw : public NPC {
  public:
   void accept(Battle* battle) override { battle->fight(this); }
   void sayHello() override { std::cout << "hello, im outlaw"; }
};
}  // namespace mobs