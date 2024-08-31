#ifndef FIGHT_PLAYER_H
#define FIGHT_PLAYER_H
#include <iostream>
#include <string_view>

#include "../../items/potion/Potion.hpp"
#include "../creature/Creature.hpp"

/**
 * Represents a player in the game.
 */
class Player : public Creature
{
public:
    Player(std::string_view name);

    /**
     * Increase the player's `m_attack_damage` and `m_level` by 1.
     */
    void level_up();

    /**
     * Check if the player has won.
     *
     * @return `true` if the player level if above or equal to 20.
     */
    bool has_won();

    /**
     * Drink a potion and apply its effects.
     *
     * @param `Potion` Reference to the potion to be drank.
     */
    void drink_potion(const Potion& potion);

    int get_level() const;

    friend std::ostream& operator<<(std::ostream& out, const Player& player);

private:
    int m_level{1};
};

#endif
