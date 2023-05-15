#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
    double x;
    double y;
public:
    Point(double x, double y);
    double distance(const Point &other) const;
    void print() const;
    Point moveTowards(const Point &source, const Point &destination, double distance);
    double getX();
    double getY();
};

#endif /* POINT_HPP */
