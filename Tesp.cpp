#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Team.hpp"

#include "doctest.h"

#include <sstream>
#include <cmath>
// #include "catch.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test Point Class")
{

    // Test constructor using distance
    {
        Point p1(1, 2);
        Point p2(3.14, -2.5);
        Point p3(-10, 5);

        // Calculate the expected distances
        double dist1 = std::sqrt(std::pow(1 - 0, 2) + std::pow(2 - 0, 2));
        double dist2 = std::sqrt(std::pow(3.14 - 0, 2) + std::pow(-2.5 - 0, 2));
        double dist3 = std::sqrt(std::pow(-10 - 0, 2) + std::pow(5 - 0, 2));

        CHECK(p1.distance(Point(0, 0)) == doctest::Approx(dist1));
        CHECK(p2.distance(Point(0, 0)) == doctest::Approx(dist2));
        CHECK(p3.distance(Point(0, 0)) == doctest::Approx(dist3));
    }

    // Test moveTowards function
    {
        Point p(3, 4);
        Point destination(0, 0);
        double distance = 5;

        // Calculate the expected new position
        double newX = (distance / p.distance(destination)) * (destination.getX() - p.getX()) + p.getX();
        double newY = (distance / p.distance(destination)) * (destination.getY() - p.getY()) + p.getY();

        Point newPoint = p.moveTowards(p, destination, distance);

        CHECK(newPoint.getX() == doctest::Approx(newX));
        CHECK(newPoint.getY() == doctest::Approx(newY));
    }
}
TEST_CASE("Test Character Class")
{
    Character c1("John Doe", Point(0, 0), 100);
    Character c2("Jane Smith", Point(3, 4), 200);

    // Test default constructor
    REQUIRE(c1.getName() == "John Doe");
    REQUIRE(c1.getLocation().getX() == 0);
    REQUIRE(c1.getLocation().getY() == 0);
    REQUIRE(c1.getHitPoints() == 100);

    // Test isAlive function
    REQUIRE(c1.isAlive() == true);
    c1.hit(150);
    REQUIRE(c1.isAlive() == false);
}

// TEST_CASE("Test Cowboy Class")
// {
//     // Test default constructor
//     Cowboy cowboy("John Doe", Point(0, 0));
//     REQUIRE(cowboy.getName() == "John Doe");
//     // REQUIRE(cowboy.getLocation() == Point(0, 0));
//     REQUIRE(cowboy.getHitPoints() == 100);
//     REQUIRE(cowboy.getBullets() == 6);

//     // Test shoot function
//     Cowboy enemy("Enemy", Point(1, 1), 100);
//     cowboy.shoot(&enemy);
//     REQUIRE(enemy.getHitPoints() < 100);

//     // Test hasBullets function
//     REQUIRE(cowboy.hasBullets() == true);
//     for (int i = 0; i < 6; ++i)
//     {
//         cowboy.shoot(nullptr);
//     }
//     REQUIRE(cowboy.hasBullets() == false);

//     // Test reload function
//     for (int i = 0; i < 6; ++i)
//     {
//         cowboy.shoot(nullptr);
//     }
//     REQUIRE(cowboy.hasBullets() == false);
//     cowboy.reload();
//     REQUIRE(cowboy.hasBullets() == true);
//     REQUIRE(cowboy.getBullets() == 6);
// }

