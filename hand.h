#ifndef HAND_H
#define HAND_H
#include <card.h>
#include <iostream>
#include <vector>

class Hand
{
public:
    // Part of Hand class - vector stores the users hand
    std::vector <Card> userHand;

    // Function needed in hand class
    void add(Card card);
    void clear();
    void printHand();
    int getTotal() const;
};

#endif // HAND_H
