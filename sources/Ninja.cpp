#include "Ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(const std::string &name, Point &location, int hitPoints, int speed) : Character(name, location, hitPoints), speed(0) {}
void Ninja::move(Character *enemy)
{
}
void Ninja::slash(Character *enemy)
{
}
int Ninja::getSpeed()
{
    return this->speed;
}
std::string Ninja::print() const
{
    return "hi";
}
