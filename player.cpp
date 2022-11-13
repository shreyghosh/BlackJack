#include "player.h"
#include <iostream>

Player::~Player()
{

}

// Prints player has lost
void Player::lose() const
{
    std::cout << userName << " loses" << std::endl;
}

//prints player has won
void Player::win() const
{
    std::cout << userName << " wins" << std::endl;
}

// prints player has pushed
void Player::push() const
{
    std::cout << userName << " pushes" << std::endl;

}

// prints player is hitting
bool Player::isHitting() const
{
    std::cout << userName << " do you want a hit (y/n(any key)): ";
    char response;
    std::cin >> response;
    return (response =='y' || response == 'Y');
}
