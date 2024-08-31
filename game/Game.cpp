#include "Game.hpp"

std::string game::get_name()
{
    while (true)
    {
        std::string name{};

        std::cout << "Please enter your name: ";
        std::cin >> name;

        if (std::cin)
        {
            return name;
        }
        else
        {
            std::cout << "Failed to read input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool game::get_player_action()
{
    while (true)
    {
        char action{};
        std::cout << "(f) to fight, or (r) to flee: ";
        std::cin >> action;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin) switch (action)
            {
            case 'f':
                return true;
            case 'r':
                return false;
            default:
                std::cout << "Input was not a valid action! Please try again.\n";
                continue;
            }
        else
        {
            std::cin.clear();
            std::cout << "Input was not recognized! Please try again.\n";
        }
    }
}

bool game::get_player_potion_choice()
{
    while (true)
    {
        char action{};
        std::cout << "You found a mythical potion. Will you drink it? [y/n]: ";
        std::cin >> action;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin) switch (action)
            {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cout << "Input was not a valid action! Please try again.\n";
                continue;
            }
        else
        {
            std::cin.clear();
            std::cout << "Input was not recognized! Please try again.\n";
        }
    }
}

bool game::fight_monster(Player& player, Monster& monster)
{
    std::cout << "You encountered a " << monster.get_name() << " (" << monster.get_symbol() << ").\n";

    while (!monster.is_dead() && !player.is_dead())
    {
        bool player_chose_fight{get_player_action()};

        if (player_chose_fight)
        {
            attack_monster(player, monster);
        }
        else
        {
            bool is_flee_successful{static_cast<bool>(Random::get(0, 1))};

            if (!is_flee_successful)
            {
                attack_player(player, monster);
                std::cout << "You failed to flee.\n";
            }
            else
            {
                std::cout << "You successfully fled.\n";
                break;
            }
        }
    }

    if (player.is_dead())
    {
        return true;
    }
    else
    {
        int potion_roll{Random::get(0, 9)};
        if (potion_roll < 3) game::potion_event(player);

        return player.is_dead();
    }
}

void game::attack_monster(Player& player, Monster& monster)
{
    int player_attack_damage{player.get_attack_damage()};
    monster.reduce_health(player_attack_damage);

    std::cout << "You hit the " << monster.get_name() << " for " << player_attack_damage << " damage.\n";

    if (!monster.is_dead())
    {
        attack_player(player, monster);
    }
    else
    {
        player.level_up();

        int new_gold = monster.get_gold();
        player.add_gold(new_gold);

        std::cout << "You have killed the " << monster.get_name() << ".\n";
        std::cout << "You are now level " << player.get_level() << ".\n";
        std::cout << "You found " << new_gold << " gold.\n";
    }
}

void game::attack_player(Player& player, const Monster& monster)
{
    int monster_attack_damage{monster.get_attack_damage()};
    player.reduce_health(monster_attack_damage);

    std::cout << "The " << monster.get_name() << " hit you for " << monster_attack_damage << " damage.\n";
}

void game::potion_event(Player& player)
{
    bool is_player_drinking{get_player_potion_choice()};

    if (is_player_drinking)
    {
        Potion potion{Potion::get_random_potion()};
        player.drink_potion(potion);

        std::cout << "You drank a " << potion.get_size() << " potion of " << potion.get_type() << ".\n";
    }
}
