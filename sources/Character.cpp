#include "Character.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

Character::Character(const Point &locationVal, int hitPointsVal, const std::string &nameVal) {}
bool Character::isAlive() const { return false; }
double Character::distance(const Character &other) const { return 0.0; }
void Character::hit(int damage) {}
std::string Character::getName() const { return "hi"; }
Point Character::getLocation() const { return Point(0, 0); }
// std::string Character::print() const
// {
//     return NULL;
// }