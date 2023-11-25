#pragma once;

namespace mobs {

class Werewolf : public NPC {
  public:
   void accept(Battle* battle) override { battle->fight(this); }
   void sayHello() override { std::cout << "hello, im werewolf"; }
};

}  // namespace mobs