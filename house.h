#ifndef HOUSE_H
#define HOUSE_H
#include <genericplayer.h>


class house: public GenericPlayer
{
public:
    // Part of house class - stores the hand of the house
    Hand houseHand;

    // Functions needed in house class
    virtual bool isHitting() const;
};

#endif // HOUSE_H
