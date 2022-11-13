#ifndef CARD_H
#define CARD_H
#include <iostream>

// Enumerations for Rank that shows card rank and suit that shows card suit
enum class Rank{Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
enum class Suit{Clubs = 1, Spades, Hearts, Diamonds};


class Card
{
public:
    // Two parts of card class storing rank and suit
    Rank cardRank;
    Suit cardSuit;

    //Functions required for card program
    bool upOrDown {true};
    bool isFaceUp() const;
    int getValue() const;
    void flip();
};

#endif // CARD_H
