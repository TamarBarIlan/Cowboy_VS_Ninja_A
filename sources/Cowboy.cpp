#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy::Cowboy(const std::string &name, Point &location) : Character(name, location, 110), bullets(6) {}
void Cowboy::shoot(Character *enemy)
{
}
bool Cowboy::hasBullets() const
{
    if (this->bullets > 0)
    {
        return true;
    }
    return false;
}
void Cowboy::reload()
{
}
int Cowboy::getBullets()
{
    return this->bullets;
}
std::string Cowboy::print() const
{
    return "hi";
    // return "Cowboy: " + this->name + " at location " + std::to_string(this->location.getX()) + ", " + std::to_string(this->location.getY());
}
