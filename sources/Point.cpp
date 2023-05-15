#include "Point.hpp"
#include <iostream>
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {}
double Point::distance(const Point &other) const { return 0; }
void Point::print() const {}
Point Point::moveTowards(const Point &source, const Point &destination, double distance) { return Point(0, 0); }
double Point::getX()
{
    return this->x;
}
double Point::getY()
{
    return this->y;
}