#include "genericplayer.h"

// Determines if player busts or not
bool GenericPlayer::isBusted() const
{
    bool bustOrNot;

    // If player hand exceeds 21 they bust
    if (getTotal() > 21)
    {
        bustOrNot = true;
    }
    else
    {
        bustOrNot = false;
    }

    return bustOrNot;
}

// Prints if player has busted or not
void GenericPlayer::bust() const
{
    std::cout << userName << " busted" << std::endl;
}
