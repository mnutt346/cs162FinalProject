#include <string>
#include <iostream>
#include "target.hpp"
#include "space.hpp"
#include "asciiArt.hpp"

using std::cout;
using std::endl;
using std::string;

const string TARGET_MESSAGE = "Apparently you stumbled into a Target last night...\n"
                              "After searching around, you find your wallet in the pocket of a mannequin!\n";

Target::Target() : Space(1)
{
    value = 'T';
    name = "target";
}

void Target::printMessage()
{
    printTarget();
    cout << endl
         << TARGET_MESSAGE << endl;
}