#ifndef DECK_H
#define DECK_H
#include <card.h>
#include <hand.h>
#include <player.h>
#include <genericplayer.h>
#include <vector>
#include <iostream>

class Deck:public Hand
{

public:
    // Part of deck class - vector storing deck cards
    std::vector <Card> deckOfCards;

    // Functions needed for deck class
    void populate();
    void shuffle();
    void printDeck();
    void deal(Hand&hand);
    void additionalCards(GenericPlayer &gp);

};

#endif // DECK_H
