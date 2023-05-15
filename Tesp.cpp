#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Team.hpp"
#include "doctest.h"

#include <sstream>

using namespace std;
using namespace ariel;


TEST_SUITE("Test Point Class") {
    TEST_CASE("Test constructor") {
        Point p(2.0, 3.0);
        CHECK(p.getX() == 2.0);
        CHECK(p.getY() == 3.0);
    }

    TEST_CASE("Test distance method") {
        Point p1(0, 0);
        Point p2(3, 4);

        double dist = p1.distance(p2);
        CHECK(dist == 5.0);
    }

    TEST_CASE("Test distance with negative coordinates") {
        Point p1(-2, -2);
        Point p2(2, 2);

        double dist = p1.distance(p2);
        CHECK(dist == 5.657);
    }

    TEST_CASE("Test moveTowards method") {
        Point source(0, 0);
        Point destination(4, 4);
        double step = 2.0;

        Point result = source.moveTowards(source, destination, step);
        CHECK(result.distance(Point(2, 2)) == 0);
    }

    TEST_CASE("Test moveTowards method with negative coordinates") {
        Point source(0, 0);
        Point destination(-4, -4);
        double step = 2.0;

        Point result = source.moveTowards(source, destination, step);
        CHECK(result.distance(Point(-2, -2)) == 0);
    }

    TEST_CASE("Test moveTowards method beyond destination") {
        Point source(0, 0);
        Point destination(1, 1);
        double step = 2.0;

        Point result = source.moveTowards(source, destination, step);
        CHECK(result.distance(Point(1, 1)) == 0);
    }

    TEST_CASE("Test moveTowards method with zero step") {
        Point source(0, 0);
        Point destination(4, 4);
        double step = 0.0;

        Point result = source.moveTowards(source, destination, step);
        CHECK(result.distance(Point(0, 0)) == 0);
    }

    TEST_CASE("Test moveTowards method with large step") {
        Point source(0, 0);
        Point destination(4, 4);
        double step = 100.0;

        Point result = source.moveTowards(source, destination, step);
        CHECK(result.distance(Point(4, 4)) == 0);
    }

}

TEST_SUITE("Test Character Class")
{
    TEST_CASE("Test Character isAlive")
    {
        Character c(Point(1, 1), 100, "John");
        CHECK(c.isAlive() == true);
    }

    TEST_CASE("Test Character hit")
    {
        Character c(Point(1, 1), 100, "John");
        c.hit(50);
        CHECK(c.getHitPoints() == 50);
    }

    TEST_CASE("Test Character getName")
    {
        Character c("John", Point(1, 1), 100);
        CHECK(c.getName() == "John");
    }

    TEST_CASE("Test Character getLocation")
    {
        Character c("John", Point(1, 1), 100);
        CHECK(c.getLocation().distance(Point(1, 1)) == 0);
    }

    // ... Add more tests for Character class ...
}

TEST_SUITE("Test Cowboy Class")
{
    TEST_CASE("Test Cowboy shoot")
    {
        Cowboy c("John", Point(1, 1));
        Character enemy("Enemy", Point(2, 2), 100);
        c.shoot(&enemy);
        CHECK(enemy.getHitPoints() == 90);
    }

    TEST_CASE("Test Cowboy hasBullets")
    {
        Cowboy c("John", Point(1, 1));
        CHECK(c.hasBullets() == true);
    }

    TEST_CASE("Test Cowboy reload")
    {
        Cowboy c("John", Point(1, 1));
        for (int i = 0; i < 6; i++)
        {
            Character enemy("Enemy", Point(2, 2), 100);
            c.shoot(&enemy);
        }
        CHECK(c.hasBullets() == false);
        c.reload();
        CHECK(c.hasBullets() == true);
    }

    // ... Add more tests for Cowboy class ...
}

TEST_SUITE("Test Ninja Class")
{
    TEST_CASE("Test Ninja move")
    {
        YoungNinja n("John", Point(1, 1));
        Character enemy("Enemy", Point(2, 2), 100);
        n.move(&enemy);
        CHECK(n.getLocation().distance(enemy.getLocation()) < 1.414);
    }

    TEST_CASE("Test Ninja slash")
    {
        YoungNinja n("John", Point(1, 1));
        Character enemy("Enemy", Point(1.5, 1.5), 100);
        n.slash(&enemy);
        CHECK(enemy.getHitPoints() == 60);
    }

    // ... Add more tests for Ninja class ...
}

TEST_SUITE("Test Team Class")
{
    TEST_CASE("Test Team add")
    {
        Team t(new Cowboy("John", Point(1, 1)));
        CHECK(t.getMemberCount() == 1);
        t.add(new YoungNinja("Jane", Point(2, 2)));
        CHECK(t.getMemberCount() == 2);
    }

    TEST_CASE("Test Team attack")
    {
        Team t1(new Cowboy("John", Point(1, 1)));
        Team t2(new YoungNinja("Jane", Point(2, 2)));
        t1.attack(&t2);
        CHECK(t2.getMemberCount() == 1);
    }

    TEST_CASE("Test Team stillAlive")
    {
        Team t(new Cowboy("John", Point(1, 1)));
        CHECK(t.stillAlive() == true);
        t.getLeader()->hit(110);
        CHECK(t.stillAlive() == false);
    }

    TEST_CASE("Test Team print")
    {
        Team t(new Cowboy("John", Point(1, 1)));
        std::ostringstream out;
        t.print(out);
        CHECK(out.str() == "C John 110 (1, 1)\n");
    }
}

