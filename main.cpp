#include <iostream>
#include <string>

#include "game/Game.hpp"
#include "game/entities/monster/Monster.hpp"
#include "game/entities/player/Player.hpp"

int main()
{
    std::string name{game::get_name()};
    Player player{name};

    std::cout << "Welcome, " << player.get_name() << ".\n";

    while (true)
    {
        Monster monster{Monster::get_random_monster()};
        bool is_player_dead = game::fight_monster(player, monster);

#ifdef DEBUG
        std::cout << "DEBUG: " << player << '\n';
#endif

        if (is_player_dead)
        {
            std::cout << "You died at level " << player.get_level() << " with " << player.get_gold() << " gold.\n";
            std::cout << "Too bad you can't take it with you!\n";
            break;
        }
        else if (monster.get_symbol() == 'D' && monster.is_dead())
        {
            std::cout << "You won!\n";
            std::cout << "Your final level was " << player.get_level() << " with " << player.get_gold() << " gold.\n";
            break;
        }
    }

    return 0;
}
