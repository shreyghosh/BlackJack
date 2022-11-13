#ifndef GAME_H
#define GAME_H
#include <hand.h>
#include <card.h>
#include <deck.h>
#include <genericplayer.h>
#include <player.h>
#include <house.h>
#include <vector>
#include <iostream>

class game
{
private:
    // Parts of gameclass
    // PlayerVec stores names of different players
    std::vector<Player> playerVec;
    // gameDeck is the deck used for the game (deals/ adds cards etc.)
    Deck gameDeck;
    // gameHouse is the house in game that plays against users
    house gameHouse;
public:
    //Function runs the game
    void play();
};

#endif // GAME_H
