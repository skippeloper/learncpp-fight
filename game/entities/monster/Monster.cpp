#include "Monster.hpp"

Monster::Monster(Type type) : Creature{__get_monster_data(type)} {};

Monster Monster::get_random_monster()
{
    Type type{Random::get(0, static_cast<int>(Type::max_types) - 1)};
    return Monster{type};
};

Creature Monster::__get_monster_data(Type type)
{
    assert(type != Monster::Type::max_types && "Monster::Type::max_types is not a valid monster type!");

    return monster_data[static_cast<int>(type)];
}
