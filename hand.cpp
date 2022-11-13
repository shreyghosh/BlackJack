#include "hand.h"

// Adds a card to the hand
void Hand::add(Card card)
{
    userHand.push_back(card);
}

// Obtains total value of the hand
// This is depending on value of each card
int Hand::getTotal() const
{
    int totalVal{0};
    bool noAce {true};

    // Determines if ace exists in hand or not
    for (int i{0}; i < userHand.size(); i++)
    {
        if (userHand.at(i).cardRank == Rank::Ace)
            noAce = false;
    }

    // Gets total of each card in hand and ads it to complete total
    for(int i{0}; i < userHand.size(); i++)
    {
        totalVal+= userHand[i].getValue();
    }
    // Intelligently determines whether it is better for ace to be 1 or 11 in the hand currently
    if (noAce == false && totalVal <= 11)
    {
        totalVal += 10;
    }
    return totalVal;
}

// Displays the hand
void Hand::printHand()
{
    // Displays all cards if face up
    if (userHand.at(0).isFaceUp() == true)
    {
        for(int i{0}; i < userHand.size(); i++)
        {
            switch(userHand[i].cardRank)
            {
              case Rank::Ace:
                std::cout << "A";
              break;
              case Rank::Two:
                std::cout << "2";
              break;
              case Rank::Three:
                std::cout << "3";
              break;
              case Rank::Four:
                std::cout << "4";
              break;
              case Rank::Five:
                std::cout << "5";
              break;
              case Rank::Six:
                std::cout << "6";
              break;
              case Rank::Seven:
                std::cout << "7";
              break;
              case Rank::Eight:
                std::cout << "8";
              break;
              case Rank::Nine:
                std::cout << "9";
              break;
              case Rank::Ten:
                std::cout << "10";
              break;
              case Rank::Jack:
                std::cout << "J";
              break;
              case Rank::Queen:
                std::cout << "Q";
              break;
              case Rank::King:
                std::cout << "K";
              break;
            }

            switch(userHand[i].cardSuit)
            {
              case Suit::Clubs:
                std::cout << "c    ";
              break;
              case Suit::Diamonds:
                std::cout << "d    ";
              break;
              case Suit::Hearts:
                std::cout << "h    ";
              break;
              case Suit::Spades:
                std::cout << "s    ";
              break;
            }
        }
    }
    // If first card is not face up, all but first card printed
    else
    {
        for(int i{0}; i < userHand.size(); i++)
        {
            if (i == 0)
            {
                std::cout << "XX    ";
            }
            else
            {
                switch(userHand[i].cardRank)
                {
                  case Rank::Ace:
                    std::cout << "A";
                  break;
                  case Rank::Two:
                    std::cout << "2";
                  break;
                  case Rank::Three:
                    std::cout << "3";
                  break;
                  case Rank::Four:
                    std::cout << "4";
                  break;
                  case Rank::Five:
                    std::cout << "5";
                  break;
                  case Rank::Six:
                    std::cout << "6";
                  break;
                  case Rank::Seven:
                    std::cout << "7";
                  break;
                  case Rank::Eight:
                    std::cout << "8";
                  break;
                  case Rank::Nine:
                    std::cout << "9";
                  break;
                  case Rank::Ten:
                    std::cout << "10";
                  break;
                  case Rank::Jack:
                    std::cout << "J";
                  break;
                  case Rank::Queen:
                    std::cout << "Q";
                  break;
                  case Rank::King:
                    std::cout << "K";
                  break;
                }

                switch(userHand[i].cardSuit)
                {
                  case Suit::Clubs:
                    std::cout << "c    ";
                  break;
                  case Suit::Diamonds:
                    std::cout << "d    ";
                  break;
                  case Suit::Hearts:
                    std::cout << "h    ";
                  break;
                  case Suit::Spades:
                    std::cout << "s    ";
                  break;
                }
            }
        }
    }
}

// Clears hand
void Hand::clear()
{
    for (int i{0}; i < userHand.size(); i++)
    {
        userHand.erase(userHand.begin() + i);
    }
}
