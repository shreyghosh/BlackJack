#ifndef PLAYER_H
#define PLAYER_H
#include <genericplayer.h>
#include <vector>


class Player: public GenericPlayer
{
public:
    // Part of player class - hand that stores specific players hand
    Hand playerHand;

    // Functions required in player class
    Player(const std::string& name= "") : GenericPlayer(name) {}
    virtual ~Player();
    virtual bool isHitting() const override;
    void win() const;
    void lose() const;
    void push() const;

};

#endif // PLAYER_H
