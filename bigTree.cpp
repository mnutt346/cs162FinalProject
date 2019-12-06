#include <string>
#include <iostream>
#include "bigTree.hpp"
#include "space.hpp"
#include "asciiArt.hpp"

using std::cout;
using std::endl;
using std::string;

const string BIG_TREE_MSG = "Did you try to climb this tree?\n You find your keys hanging from a branch!\n";

BigTree::BigTree() : Space(2)
{
    value = 'B';
    name = "bigTree";
}

void BigTree::printMessage()
{
    printTree();
    cout << endl
         << BIG_TREE_MSG << endl;
}