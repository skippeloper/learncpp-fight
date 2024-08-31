
#ifndef FIGHT_MONSTER_H
#define FIGHT_MONSTER_H
#include <cassert>
#include <iostream>

#include "../../utils/Random.hpp"
#include "../creature/Creature.hpp"

/**
 * Represents a monster. Primary creature that attacks the player.
 */
class Monster : public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

    Monster(Type type);

    /**
     * Generate a random monster.
     *
     * @return A random `Monster`
     */
    static Monster get_random_monster();

private:
    /**
     * A list of starting stats for each monster type.
     */
    static inline Creature monster_data[]{Creature("dragon", 'D', 20, 4, 100), Creature("orc", 'o', 4, 2, 25),
                                          Creature("slime", 's', 1, 1, 10)};

    /**
     * Returns a creature while doing bounds checking in case max_types is used.
     *
     * @return `Creature`
     */
    static Creature __get_monster_data(Type type);

    static_assert(std::size(monster_data) == static_cast<int>(Type::max_types));
};

#endif
