#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, Point &location);
    };
}

#endif /* TRAINED_NINJA_HPP */