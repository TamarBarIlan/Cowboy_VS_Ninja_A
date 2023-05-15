#include "Ninja.hpp"

using namespace ariel;
using namespace std;


Ninja::Ninja(const Point& locationVal, int hitPointsVal, const std::string& nameVal, int speedVal) : Character(locationVal, hitPointsVal, nameVal) {}
void Ninja::move(Character* enemy) {}
void Ninja::slash(Character* enemy) {}
std::string Ninja::print() const 
{
    return "hi";
}
