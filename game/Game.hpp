#ifndef FIGHT_UTILS_H
#define FIGHT_UTILS_H
#include <iostream>
#include <limits>
#include <string>

#include "entities/monster/Monster.hpp"
#include "entities/player/Player.hpp"
#include "utils/Random.hpp"

/**
 * Namespace that handles primary game logic.
 */
namespace game
{
/**
 * Get string from the user.
 *
 * @return `std::string` input by the user. Empty string is something
 * went wrong.
 */
std::string get_name();

/**
 * Get a player's next action.
 *
 * @return `true` if player hits. `false` if player flees.
 */
bool get_player_action();

/**
 * Get a player's next action when encountering a potion.
 *
 * @return `true` if player drinks potion. `false` if player does not.
 */
bool get_player_potion_choice();

/**
 * Handle a single encouter. Handles both cases for fighting and fleeing.
 *
 * @param player reference to the player fighting the monster.
 * @param monster reference to the monster participating in the fight.
 *
 * @return `true` if the player died.
 */
bool fight_monster(Player& player, Monster& monster);

/**
 * Handle the case where a player attacks a monster.
 *
 * @param player reference to the attacking player.
 * @param monster reference to monster being attacked.
 */
void attack_monster(Player& player, Monster& monster);

/**
 * Handle the case where a monster attacks a player.
 *
 * @param player reference to the player being attacked.
 * @param monster const reference to the attacking monster.
 */
void attack_player(Player& player, const Monster& monster);

/**
 * Handle a potion event.
 *
 * @param player player to be participating in the potion event.
 */
void potion_event(Player& player);

}  // namespace game

#endif
