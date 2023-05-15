#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy::Cowboy(const std::string& nameVal, const Point& locationVal) : Character(locationVal, 110, nameVal) {}
void Cowboy::shoot(Character* enemy) {}
bool Cowboy::hasBullets() const { return false; }
void Cowboy::reload() {}
std::string Cowboy::print() const {
    return "hi";
    // return "Cowboy: " + this->name + " at location " + std::to_string(this->location.getX()) + ", " + std::to_string(this->location.getY());
}
