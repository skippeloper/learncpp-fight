#include "Player.hpp"

Player::Player(std::string_view name) : Creature{name, '@', 10, 1, 0} {};

int Player::get_level() const { return m_level; }

void Player::level_up()
{
    ++m_attack_damage;
    ++m_level;
}

bool Player::has_won() { return m_level >= 20; }

void Player::drink_potion(const Potion& potion)
{
    // potion effect scalar will be enum + 1
    int potion_effect_scalar{static_cast<int>(potion.get_size()) + 1};

    switch (potion.get_type())
    {
    case Potion::Type::health:
        m_health += (potion_effect_scalar * 2);
        break;
    case Potion::Type::strength:
        m_attack_damage += potion_effect_scalar;
        break;
    case Potion::Type::poison:
        m_health -= potion_effect_scalar;
        break;
    case Potion::Type::max_types:
        std::cerr << "Potion type was no recognized!";
        break;
    }
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    out << "Player(name=" << player.get_name() << ", symbol=" << player.get_symbol()
        << ", health=" << player.get_health() << ", attack_damage=" << player.get_attack_damage()
        << ", gold=" << player.get_gold() << ", level=" << player.get_level() << ")";

    return out;
}
