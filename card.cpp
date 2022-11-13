#include "card.h"

// Function that returns the direction that the card is facing (up or down)
bool Card::isFaceUp() const
{
    return upOrDown;
}

// Function to get value of card
int Card::getValue() const
{
    int cardVal{0};

    // Switch statement decided value of card based upon rank
    switch (cardRank)
    {
        case Rank::Two:
            cardVal = 2;
        break;

        case Rank::Three:
            cardVal = 3;
        break;

        case Rank::Four:
            cardVal = 4;
        break;

        case Rank::Five:
            cardVal = 5;
        break;

        case Rank::Six:
            cardVal = 6;
        break;

        case Rank::Seven:
            cardVal = 7;
        break;

        case Rank::Eight:
            cardVal = 8;
        break;

        case Rank::Nine:
            cardVal = 9;
        break;

        case Rank::Ten:
            cardVal = 10;
        break;

        case Rank::Jack:
            cardVal = 11;
        break;

        case Rank::Queen:
            cardVal = 12;
        break;

        case Rank::King:
            cardVal = 13;
        break;

        case Rank::Ace:
            cardVal = 1;
        break;
    }

    return cardVal;
}

// Flips card direction
void Card::flip()
{
    // Flips down to up
    if (upOrDown == false)
    {
        upOrDown = true;
    }
    // Flips up to down
    else
    {
        upOrDown = false;
    }
}
