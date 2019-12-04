#ifndef TARGET_HPP
#define TARGET_HPP

#include "space.hpp"

class Target : public Space
{
public:
    Target();
    virtual void printMessage();
};

#endif