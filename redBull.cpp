#include <string>
#include <iostream>
#include "redBull.hpp"
#include "space.hpp"

using std::cout;
using std::endl;
using std::string;

const string REDBULL_MESSAGE = "You found a Red Bull! You've gained one move!";

RedBull::RedBull() : Space(10)
{
    value = 'R';
    name = "redbull";
}

void RedBull::printMessage()
{
    cout << REDBULL_MESSAGE << endl;
}