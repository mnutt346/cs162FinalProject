#include <string>
#include <iostream>
#include "oldCouch.hpp"
#include "space.hpp"

using std::cout;
using std::endl;
using std::string;

const string COUCH_MSG = "Looks like you took a nap on this abandoned, old couch...\n"
                         "And your phone is between the cushions!\n";

OldCouch::OldCouch() : Space(3)
{
    value = 'C';
    name = "oldCouch";
}

void OldCouch::printMessage()
{
    cout << COUCH_MSG << endl;
}