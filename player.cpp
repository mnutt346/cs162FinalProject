#include <algorithm>
#include "player.hpp"

using std::any_of;

Player::Player()
{
}

Space *Player::getSpace()
{
    return currentSpace;
}

void Player::setSpace(Space *newSpace)
{
    currentSpace = newSpace;
}

void Player::addItem(int newItem)
{
    items.push_back(newItem);
}

bool Player::allItemsFound()
{
    // Determine if each item is in the player's items vector
    bool walletFound = any_of(items.begin(), items.end(), compare(1));
    bool keysFound = any_of(items.begin(), items.end(), compare(2));
    bool phoneFound = any_of(items.begin(), items.end(), compare(3));

    // If all items have been found:
    if (walletFound && keysFound && phoneFound)
    {
        return true;
    }

    return false;
}