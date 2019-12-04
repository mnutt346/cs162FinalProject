#include <iostream>
#include "space.hpp"

using std::cout;
using std::endl;

Space::Space()
{
    item = 0;
    visited = false;
    value = '#';
    name = "space";
}

Space::Space(int itemNum)
{
    item = itemNum;
    visited = false;
    value = '#';
    name = "space";
}

Space *Space::getUp()
{
    return this->up;
}

Space *Space::getDown()
{
    return this->down;
}

Space *Space::getLeft()
{
    return this->left;
}

Space *Space::getRight()
{
    return this->right;
}

char Space::getValue()
{
    return this->value;
}

void Space::setValue()
{
    this->value = ' ';
}

bool Space::getVisited()
{
    return this->visited;
}

void Space::setVisited()
{
    visited = true;
}

int Space::getItem()
{
    return this->item;
}

void Space::setPerimeter(Space *upPtr, Space *dwn, Space *lft, Space *rt)
{
    up = upPtr;
    down = dwn;
    left = lft;
    right = rt;
}

void Space::printMessage()
{

    cout << "There doesn't seem to be anything here..." << endl
         << "Keep searching." << endl;
}
