/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;

int main()
{
   cout << "1" << endl;
   Point a(32.3, 44), b(1.3, 3.5);
   cout << "2" << endl;
   assert(a.distance(b) == b.distance(a));
   cout << "3" << endl;
   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   cout << "Before tom->shoot(sushi)" << endl;
   tom->shoot(sushi);
   cout << "After tom->shoot(sushi)" << endl;
   cout << tom->print() << endl;
   cout << "4" << endl;
   sushi->move(tom);
   cout << "5" << endl;
   sushi->slash(tom);
   cout << "6" << endl;
   Team team_A(tom);
   cout << "7" << endl;
   team_A.add(new YoungNinja("Yogi", Point(64, 57)));
   cout << "8" << endl;

   // Team b(tom); should throw tom is already in team a

   Team team_B(sushi);
   cout << "9" << endl;

   team_B.add(new TrainedNinja("Hikari", Point(12, 81)));
   cout << "10" << endl;

   while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   {
      team_A.attack(&team_B);
      team_B.attack(&team_A);
      team_A.print();
      team_B.print();
   }

   if (team_A.stillAlive() > 0)
      cout << "winner is team_A" << endl;
   else
      cout << "winner is team_B" << endl;

   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
}