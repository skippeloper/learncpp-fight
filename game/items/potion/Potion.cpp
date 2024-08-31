#include "Potion.hpp"

Potion::Potion(Size size, Type type) : m_size{size}, m_type{type} {}

Potion::Size Potion::get_size() const { return m_size; }
Potion::Type Potion::get_type() const { return m_type; }

Potion Potion::get_random_potion()
{
    Size size{static_cast<Size>(Random::get(0, static_cast<int>(Size::max_sizes) - 1))};
    Type type{static_cast<Type>(Random::get(0, static_cast<int>(Type::max_types) - 1))};

    return Potion{size, type};
}

std::ostream& operator<<(std::ostream& out, Potion::Size size)
{
    out << Potion::size_names[static_cast<int>(size)];
    return out;
}

std::ostream& operator<<(std::ostream& out, Potion::Type type)
{
    out << Potion::type_names[static_cast<int>(type)];
    return out;
}
