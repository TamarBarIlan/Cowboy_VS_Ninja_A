#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"

namespace ariel
{
    class Character
    {
    public:
        Character(const Point &locationVal, int hitPointsVal, const std::string &nameVal);
        bool isAlive() const;
        double distance(const Character &other) const;
        void hit(int damage);
        std::string getName() const;
        Point getLocation() const;
        std::string print() const;
    };

}

#endif /* CHARACTER_HPP */