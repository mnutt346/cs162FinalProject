#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "space.hpp"
#include "redBull.hpp"
#include "player.hpp"
#include "target.hpp"
#include "bigTree.hpp"
#include "oldCouch.hpp"

class Game
{
private:
    const int MAX_STEPS = 15;
    int movesRemaining;
    bool thingsFound;
    Space space1;
    RedBull space2;
    Space space3;
    Space space4;
    RedBull space5;
    RedBull space6;
    Target target;
    BigTree bigTree;
    OldCouch oldCouch;
    Player player;
    void handleNewSpace();
    void initializeMap();
    void handleMoveChoice(int);
    bool isValidMove(int);

public:
    Game();
    void playGame();
};

#endif