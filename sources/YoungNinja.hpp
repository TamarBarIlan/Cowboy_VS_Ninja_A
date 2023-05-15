#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, Point &location);
    };

}

#endif /* YOUNG_NINJA_HPP */