#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    public:
        Cowboy(const std::string &nameVal, const Point &locationVal);
        void shoot(Character* enemy);
        bool hasBullets() const;
        void reload();
        std::string print() const override;

    };

}

#endif /* COWBOY_HPP */