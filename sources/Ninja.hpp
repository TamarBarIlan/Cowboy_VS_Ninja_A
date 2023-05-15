#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    public:
        Ninja(const Point &locationVal, int hitPointsVal, const std::string &nameVal, int speedVal);
        void move(Character* enemy);
        void slash(Character* enemy);
    };

    

}

#endif /* NINJA_HPP */