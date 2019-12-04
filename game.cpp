#include <iostream>
#include <vector>
#include <string>
#include "game.hpp"
#include "menu.hpp"
#include "space.hpp"
#include "oldCouch.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

Game::Game()
{
    movesRemaining = MAX_STEPS;
    thingsFound = false;
}

void Game::playGame()
{

    cout << endl
         << "~*~*~* Where am I? *~*~*~" << endl
         << endl;
    cout << "You had a bit too much to drink last night (12 drinks is too many, right?)." << endl;
    cout << "You check your pockets for your phone, wallet, and keys..." << endl;
    cout << "They're missing!" << endl;

    vector<string> options{"Find your stuff!", "Accept your fate and sleep on a park bench."};

    int selection = multiOptionMenu(options);

    while (selection == 1)
    {
        cout << endl
             << "Alright, let's find your stuff!" << endl
             << "You have a total of 15 moves to find your thigs." << endl
             << "There are a few Red Bulls scattered around the area that can help keep you going." << endl
             << "If you can't find your phone, wallet, and keys by the end of the 15 moves," << endl
             << "the game will be over!" << endl
             << endl
             << "You can choose to move up, down, left, or right." << endl
             << "You will hopefully uncover whatever it is that you did last night as you move through the map."
             << "Good luck!" << endl
             << endl;

        // Set up the all the spaces
        initializeMap();
        // Set the player's current space to space1;
        player.setSpace(&space1);

        while (!thingsFound && movesRemaining > 0)
        {
            cout << endl
                 << "Moves remaining: " << movesRemaining << endl
                 << "Choose a direction in which to move:" << endl;
            vector<string> moveOptions{"Up", "Down", "Left", "Right"};

            int moveChoice = multiOptionMenu(moveOptions);

            while (!isValidMove(moveChoice))
            {
                cout << "You can't go that way. Pick another direction." << endl;
                moveChoice = multiOptionMenu(moveOptions);
            }

            handleMoveChoice(moveChoice);

            handleNewSpace();

            if (player.allItemsFound())
            {
                thingsFound = true;
            }

            movesRemaining--;
        }

        if (!thingsFound)
        {
            vector<string> replayOptions{"Try again to find all your things.", "Accept your fate and take a nap wherever you are."};
            selection = multiOptionMenu(replayOptions);
        }
        else
        {
            cout << "Congrats! You found all your things!" << endl;
            vector<string> successOptions{"Is that a keg over there? Let's do it again!", "Don't test your luck, and spend a quiet night at home."};
            selection = multiOptionMenu(successOptions);
        }
    }
    cout << "Exiting game..." << endl;
}

void Game::initializeMap()
{
    space1.setPerimeter(&space2, nullptr, nullptr, &space3);
    space2.setPerimeter(nullptr, &space1, nullptr, &target);
    space3.setPerimeter(&target, &bigTree, &space1, &space4);
    space4.setPerimeter(&space5, &space6, &space3, &oldCouch);
    space5.setPerimeter(nullptr, &space4, &target, nullptr);
    space6.setPerimeter(&space4, nullptr, &bigTree, nullptr);
    target.setPerimeter(nullptr, &space3, &space2, &space5);
    bigTree.setPerimeter(&space3, nullptr, nullptr, &space6);
    oldCouch.setPerimeter(nullptr, nullptr, &space4, nullptr);
}

bool Game::isValidMove(int moveChoice)
{
    Space *currentSpace = player.getSpace();
    if (moveChoice == 1 && (currentSpace->getUp() == nullptr))
    {
        return false;
    }
    else if (moveChoice == 2 && (currentSpace->getDown() == nullptr))
    {
        return false;
    }
    else if (moveChoice == 3 && (currentSpace->getLeft() == nullptr))
    {
        return false;
    }
    else if (moveChoice == 4 && (currentSpace->getRight() == nullptr))
    {
        return false;
    }
    return true;
}

void Game::handleMoveChoice(int moveChoice)
{
    Space *currentSpace = player.getSpace();
    Space *newSpace;

    if (moveChoice == 1)
    {
        newSpace = currentSpace->getUp();
        player.setSpace(newSpace);
    }
    else if (moveChoice == 2)
    {
        newSpace = currentSpace->getDown();
        player.setSpace(newSpace);
    }
    else if (moveChoice == 3)
    {
        newSpace = currentSpace->getLeft();
        player.setSpace(newSpace);
    }
    else if (moveChoice == 4)
    {
        newSpace = currentSpace->getRight();
        player.setSpace(newSpace);
    }
}

void Game::handleNewSpace()
{
    Space *newSpace = player.getSpace();

    cout << endl;

    // If the new space has been visited already, notify the player
    if (newSpace->getVisited())
    {
        cout << "Looks like you've already been here..." << endl;
    }
    // If the space has not already been visited:
    else
    {
        // Print the related message
        newSpace->printMessage();
        // If the space is a Target
        if (newSpace->getItem() == 1)
        {
            // Add the wallet to the player's items
            player.addItem(1);
        }
        // If the space is a BigTree
        else if (newSpace->getItem() == 2)
        {
            // Add the keys to the player's items
            player.addItem(2);
        }
        // If the space is the OldCouch
        else if (newSpace->getItem() == 3)
        {
            // Add the phone to the player's items
            player.addItem(3);
        }
        else if (newSpace->getItem() == 10)
        {
            movesRemaining++;
        }
        // Mark the space as visited
        newSpace->setVisited();
    }
    cout << endl;
}