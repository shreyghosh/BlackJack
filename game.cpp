#include "game.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Function which runs the game
void game::play()
{
    // Variables needed to run game
    int numPlayers;
    string playerName;
    bool CorrectEntry{true};

    cout << "Welcome to the Virtual BlackJack Player!" << endl;

    // Do while loop to ask how many players playing
    // Checks for invalid numerical inputs
    do
    {

        cout <<"How many players? (1-7): " << endl;
        cin >> numPlayers;

        if (numPlayers <= 0 || numPlayers > 7)
        {
            cout << "Invalid number of players entered! Please enter between 1 and 7 players." << endl;
            CorrectEntry = false;
        }
        else
        {
            CorrectEntry = true;
        }
    }
    while (CorrectEntry == false);

    // Asks user to enter names of players
    // Creates Player for each player and pushes them into playerVec
    for (int i{0}; i < numPlayers; i++)
    {
        cout << "Enter Player Name: " << endl;
        cin >> playerName;
        playerVec.push_back(Player(playerName));

    }

    cout << endl;

    // Populates and shuffles deck
    gameDeck.populate();
    gameDeck.shuffle();

    // Deals 2 cards to each player and house
    for (int i {0}; i<2; i++)
    {
        for (auto& player : playerVec)
        {
            gameDeck.deal(player);
        }
        gameDeck.deal(gameHouse);
    }

    // Prints player name and value of hand
    for (auto& player : playerVec)
    {
        cout << player.userName << ": ";
        player.printHand();
        cout << "(" << player.getTotal() << ")";
        cout << endl;
    }

    // Flips first card of the house
    gameHouse.userHand.at(0).flip();

    // Prints house hand
    cout << "House: ";
    gameHouse.printHand();
    cout << endl;
    cout << endl;

    // Flips back first card of house
    gameHouse.userHand.at(0).flip();

    // Checks that no players have busted after initial deal
    // Removes them from playerVec if they have
    for (int i{0}; i < playerVec.size(); i++)
    {
        if (playerVec.at(i).isBusted() == true)
        {
            playerVec.at(i).bust();
            playerVec.erase(playerVec.begin()+ i);
            i--;
        }
    }

    // Asks eack player if they would like to hit or not
    // Then, prints their hand and total
    // Does so until player stops hitting or they bust
    for (int i{0}; i < playerVec.size(); i++)
    {
        bool hitOrNot;
        hitOrNot = playerVec.at(i).isHitting();
        while (hitOrNot == true)
        {
            gameDeck.deal(playerVec.at(i));
            cout << playerVec.at(i).userName << ": ";
            playerVec.at(i).printHand();
            cout << "(" << playerVec.at(i).getTotal() << ")";
            cout << endl;
            if (playerVec.at(i).isBusted() == true)
            {
                playerVec.at(i).bust();
                playerVec.erase(playerVec.begin()+ i);
                i--;
                hitOrNot = false;

            }
            else
            {
               hitOrNot = playerVec.at(i).isHitting();
            }
        }
    }

    // Deals house another card if its total is less than 16
    if (gameHouse.getTotal() <= 16)
    {
        gameDeck.deal(gameHouse);
    }

    cout << endl;

    // Prints house cards and total
    cout << "House: ";
    gameHouse.printHand();
    cout << "(" << gameHouse.getTotal() << ")";
    cout << endl;

    // If players left and house busts, all other players win
    if (playerVec.size() != 0)
    {
        if (gameHouse.getTotal() > 21)
        {
            for (int i{0}; i < playerVec.size(); i++)
            {
                playerVec.at(i).win();
            }
        }
        // Otherwise, compares players total to house total
        // Players with greater total than house win
        // less total than house lose
        // same total as house push
        else
        {
            for (int i{0}; i < playerVec.size(); i++)
            {
                if(playerVec.at(i).getTotal() > gameHouse.getTotal())
                {
                    playerVec.at(i).win();
                }
                else if (playerVec.at(i).getTotal() < gameHouse.getTotal())
                {
                    playerVec.at(i).lose();
                }
                else if (playerVec.at(i).getTotal() == gameHouse.getTotal())
                {
                    playerVec.at(i).push();
                }
            }
        }
    }

    // Clears all vectors for next game
    playerVec.clear();
    gameHouse.clear();
    gameHouse.userHand.clear();
}
