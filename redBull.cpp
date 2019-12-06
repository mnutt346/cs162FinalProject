#include <string>
#include <iostream>
#include "redBull.hpp"
#include "space.hpp"
#include "asciiArt.hpp"

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
    printRedbull();
    cout << endl
         << REDBULL_MESSAGE << endl;
}