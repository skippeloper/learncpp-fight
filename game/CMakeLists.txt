cmake_minimum_required(VERSION 3.5.0)
project(game VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR})

add_library(game
    Game.cpp
    Game.hpp
    utils/Random.hpp
    entities/creature/Creature.cpp
    entities/creature/Creature.hpp
    entities/monster/Monster.cpp
    entities/monster/Monster.hpp
    entities/player/Player.cpp
    entities/player/Player.hpp
    items/potion/Potion.cpp
    items/potion/Potion.hpp
)
