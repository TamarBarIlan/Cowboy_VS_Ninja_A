#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy::Cowboy(const std::string& nameVal, const Point& locationVal) : Character(locationVal, 110, nameVal) {}
void Cowboy::shoot(Character* enemy) {}
bool Cowboy::hasBullets() const { return false; }
void Cowboy::reload() {}