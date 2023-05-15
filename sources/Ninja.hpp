#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;
    public:
        Ninja(const std::string &name, Point &location, int hitPoints, int speed);
        void move(Character *enemy);
        void slash(Character *enemy);
        int getSpeed();
        std::string print() const override;
    };

}

#endif /* NINJA_HPP */