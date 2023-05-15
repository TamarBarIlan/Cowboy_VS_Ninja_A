#include "Character.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

Character::Character(const std::string &name, Point &location, int hitPoints)
    : name(name), location(location), hitPoints(hitPoints)
{
}
bool Character::isAlive() const
{
        if (this->hitPoints > 0)
        {
                return true;
        }
        return false;
}
double Character::distance(const Character &other) const
{
        return 0.0;
}
void Character::hit(int damage)
{
}
std::string Character::getName() const
{
        return this->name;
}
Point Character::getLocation() const
{
        return this->location;
}
int Character::getHitPoints()
{
        return this->hitPoints;
}
