#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &location);
        TrainedNinja(const TrainedNinja &other); // Copy constructor
        TrainedNinja& operator=(const TrainedNinja &other); // Assignment operator
    };
}

#endif /* TRAINED_NINJA_HPP */
