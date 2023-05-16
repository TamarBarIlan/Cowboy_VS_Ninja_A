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
TEST_CASE("Test Cowboy Class")
{
    // Test constructor
    {
        Point p(1, 2);
        ariel::Cowboy cowboy("John", p);
        CHECK(cowboy.getName() == "John");
        CHECK(cowboy.getLocation().getX() == 1);
        CHECK(cowboy.getLocation().getY() == 2);
    }

    // Test copy constructor
    {
        Point p(1, 2);
        ariel::Cowboy cowboy1("John", p);
        ariel::Cowboy cowboy2 = cowboy1; // Using the copy constructor
        CHECK(cowboy2.getName() == "John");
        CHECK(cowboy2.getLocation().getX() == 1);
        CHECK(cowboy2.getLocation().getY() == 2);
    }

    // Test operator=
    {
        Point p1(1, 2);
        Point p2(3, 4);
        ariel::Cowboy cowboy1("John", p1);
        ariel::Cowboy cowboy2("Doe", p2);
        cowboy2 = cowboy1;
        CHECK(cowboy2.getName() == "John");
        CHECK(cowboy2.getLocation().getX() == 1);
        CHECK(cowboy2.getLocation().getY() == 2);
    }

    // Test reload,hasBullets inimethod
    {
        Point p(1, 2);
        ariel::Cowboy cowboy("John", p);
        CHECK(cowboy.hasBullets() == true);
        CHECK(cowboy.getBullets() == 6);

        Point p1(0, 0);
        ariel::Cowboy enemy("enemy", p1);
        cowboy.shoot(&enemy); // Assuming this reduces the number of bullets
        cowboy.reload();
        CHECK(cowboy.getBullets() == 11);
    }
}
TEST_CASE("Test Ninja Classes")
{
    // Test constructor
    {
        Point p(1, 2);
        ariel::Ninja ninja("John", p, 100, 10);
        CHECK(ninja.getName() == "John");
        CHECK(ninja.getLocation().getX() == 1);
        CHECK(ninja.getLocation().getY() == 2);
        CHECK(ninja.getSpeed() == 10);
    }

    // Test YoungNinja constructor
    {
        Point p(1, 2);
        ariel::YoungNinja youngNinja("John", p);
        CHECK(youngNinja.getName() == "John");
        CHECK(youngNinja.getLocation().getX() == 1);
        CHECK(youngNinja.getLocation().getY() == 2);
        CHECK(youngNinja.getSpeed() == 14); 
    }

    // Test TrainedNinja constructor
    {
        Point p(1, 2);
        ariel::TrainedNinja trainedNinja("John", p);
        CHECK(trainedNinja.getName() == "John");
        CHECK(trainedNinja.getLocation().getX() == 1);
        CHECK(trainedNinja.getLocation().getY() == 2);
        CHECK(trainedNinja.getSpeed() == 12);
    }

    // Test OldNinja constructor
    {
        Point p(1, 2);
        ariel::OldNinja oldNinja("John", p);
        CHECK(oldNinja.getName() == "John");
        CHECK(oldNinja.getLocation().getX() == 1);
        CHECK(oldNinja.getLocation().getY() == 2);
        CHECK(oldNinja.getSpeed() == 8);
    }
}