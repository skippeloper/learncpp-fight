#ifndef FIGHT_POTION_H
#define FIGHT_POTION_H
#include <array>
#include <iostream>

#include "../../utils/Random.hpp"

/**
 * Represents a potion.
 */
class Potion
{
public:
    /**
     * Represents all possible sizes of potions.
     */
    enum class Size
    {
        small,
        medium,
        large,
        max_sizes
    };

    /**
     * Represents all possible types of potions.
     */
    enum class Type
    {
        health,
        strength,
        poison,
        max_types
    };

    Potion(Size size, Type type);

    /**
     * Get a random potion.
     *
     * @return `Potion` with attributes randomised.
     */
    static Potion get_random_potion();

    Size get_size() const;
    Type get_type() const;

    /**
     * String representations of the `Size` enums.
     */
    static constexpr inline std::array<std::string_view, static_cast<int>(Size::max_sizes)> size_names{
        "small", "medium", "large"};

    /**
     * String representations of the `Type` enums.
     */
    static constexpr inline std::array<std::string_view, static_cast<int>(Type::max_types)> type_names{
        "health", "strength", "poison"};

    static_assert(std::size(size_names) == static_cast<int>(Size::max_sizes));
    static_assert(std::size(type_names) == static_cast<int>(Type::max_types));

    friend std::ostream& operator<<(std::ostream& out, Potion::Size size);
    friend std::ostream& operator<<(std::ostream& out, Potion::Type type);

protected:
    Size m_size{};
    Type m_type{};
};

std::ostream& operator<<(std::ostream& out, Potion::Size size);
std::ostream& operator<<(std::ostream& out, Potion::Type type);

#endif
