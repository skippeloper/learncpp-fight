#ifndef FIGHT_CREATURE_H
#define FIGHT_CREATURE_H
#include <string>

/**
 * Represents a creature.
 */
class Creature
{
public:
    Creature(std::string_view name, char symbol, int health, int attack_damage, int gold);

    /**
     * Reduce the creature's health by x.
     *
     * @param x Amount to reduce the creature's health by.
     */
    void reduce_health(int x);

    /**
     * Check whether the creature is dead or not.
     *
     * @return `bool` that is `true` if the creature is dead.
     */
    bool is_dead() const;

    /**
     * Add x amount of gold to the creature.
     *
     * @param x The amount of gold to add to the creature's inventory.
     */
    void add_gold(int x);

    std::string_view get_name() const;
    char get_symbol() const;
    int get_health() const;
    int get_attack_damage() const;
    int get_gold() const;

protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_attack_damage{};
    int m_gold{};
};

#endif
