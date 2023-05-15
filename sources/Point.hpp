#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
    Point(double xVal, double yVal);
    double distance(const Point &other) const;
    void print() const;
    Point moveTowards(const Point &source, const Point &destination, double distance);
};

#endif /* POINT_HPP */
