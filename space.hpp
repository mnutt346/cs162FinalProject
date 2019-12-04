#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

class Space
{
protected:
    Space *up;
    Space *down;
    Space *left;
    Space *right;
    int item;
    bool visited;
    char value;
    std::string name;

public:
    Space();
    Space(int);
    Space *getUp();
    Space *getDown();
    Space *getLeft();
    Space *getRight();
    void setPerimeter(Space *, Space *, Space *, Space *);
    bool getVisited();
    void setVisited();
    int getItem();
    void setItem(int);
    char getValue();
    void setValue();
    virtual void printMessage();
};

#endif