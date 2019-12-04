#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <algorithm>
#include "space.hpp"

/*
    Algorithm for finding a specified element within a vector from:
    https://www.techiedelight.com/check-vector-contains-given-element-cpp/
*/
struct compare
{
    int key;

    compare(int const &i) : key(i) {}

    bool operator()(int const &i)
    {
        return (i == key);
    }
};

class Player
{
private:
    std::vector<int> items;
    Space *currentSpace;

public:
    Player();
    Space *getSpace();
    void setSpace(Space *);
    void moveSpace(int);
    void addItem(int);
    bool allItemsFound();
};

#endif