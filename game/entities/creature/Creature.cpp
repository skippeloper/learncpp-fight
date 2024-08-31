#include "Creature.hpp"

Creature::Creature(std::string_view name, char symbol, int health, int attack_damage, int gold)
    : m_name{name}, m_symbol{symbol}, m_health{health}, m_attack_damage{attack_damage}, m_gold{gold} {};

std::string_view Creature::get_name() const { return m_name; }
char Creature::get_symbol() const { return m_symbol; }
int Creature::get_health() const { return m_health; }
int Creature::get_attack_damage() const { return m_attack_damage; }
int Creature::get_gold() const { return m_gold; }

void Creature::reduce_health(int x) { m_health -= x; }
bool Creature::is_dead() const { return m_health <= 0; }
void Creature::add_gold(int x) { m_gold += x; }
