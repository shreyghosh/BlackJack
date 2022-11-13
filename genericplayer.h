#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include <string>
#include <hand.h>
#include <iostream>


class GenericPlayer: public Hand
{
public:
    // Part of GenericPlayer Class which stores name of user
    std::string userName;

    // Function required in GenericPlayer
    GenericPlayer(const std::string&name = ""): userName(name) {}
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void bust() const;
};


#endif // GENERICPLAYER_H
