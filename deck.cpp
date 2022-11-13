#include "deck.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

// Function to generate deck of 52 cards
void Deck::populate()
{
    // Loops for 52 (cards)
    for (int i{1}; i <= 4; i++)
    {
        for(int j{1}; j <= 13; j++)
        {
            // Sets a card and pushes it back into the deck (iterates for all cards)
            Card CurrCard;
            CurrCard.cardSuit = static_cast<Suit>(i);
            CurrCard.cardRank = static_cast<Rank>(j);
            deckOfCards.push_back(CurrCard);
        }
    }
}

// Shuffles a organized deck of 52 cards
void Deck::shuffle()
{
    int swapOne, swapTwo;
    srand((unsigned) time(0));

    // Randomly swaps cards 50 times to randomize deck
    for (int i{0}; i < 50; i++)
          {
              swapOne = (int) ((rand() % 52) + 1);
              swapTwo = (int) ((rand() % 52) + 1);

              Card tempVar = deckOfCards[swapOne];
              deckOfCards[swapOne] = deckOfCards[swapTwo];
              deckOfCards[swapTwo] = tempVar;
          }
}

// Deals cards from deck to hand
void Deck::deal(Hand&hand)
{
    // Adds card to hand and removes it from deck
    hand.add(deckOfCards.back());
    deckOfCards.pop_back();
}

// Function to print a deck of 52 cards
void Deck::printDeck()
{
    // Prints entrie deck based on rank and suit
    for (int i = 0; i < 52; i++) {
            if (deckOfCards[i].cardRank == Rank::Two)
                std::cout << "2";
            else if (deckOfCards[i].cardRank == Rank::Three)
                std::cout << "3";
            else if (deckOfCards[i].cardRank == Rank::Four)
                std::cout << "4";
            else if (deckOfCards[i].cardRank == Rank::Five)
                std::cout << "5";
            else if (deckOfCards[i].cardRank == Rank::Six)
                std::cout << "6";
            else if (deckOfCards[i].cardRank == Rank::Seven)
                std::cout << "7";
            else if (deckOfCards[i].cardRank == Rank::Eight)
                std::cout << "8";
            else if (deckOfCards[i].cardRank == Rank::Nine)
                std::cout << "9";
            else if (deckOfCards[i].cardRank == Rank::Ten)
                std::cout << "10";
            else if (deckOfCards[i].cardRank == Rank::Jack)
                std::cout << "J";
            else if (deckOfCards[i].cardRank == Rank::Queen)
                std::cout << "Q";
            else if (deckOfCards[i].cardRank == Rank::King)
                std::cout << "K";
            else if (deckOfCards[i].cardRank == Rank::Ace)
                std::cout << "A";
            if (deckOfCards[i].cardSuit == Suit::Clubs)
                std::cout << "c\n";
            else if (deckOfCards[i].cardSuit == Suit::Diamonds)
                std::cout << "d\n";
            else if (deckOfCards[i].cardSuit == Suit::Hearts)
                std::cout << "h\n";
            else if (deckOfCards[i].cardSuit == Suit::Spades)
                std::cout << "s\n";
    }
}

// Function adds card to a generic player
void Deck::additionalCards(GenericPlayer &gp)
{
    // If the generic player is hitting then add card to their hand
    // Then remove that card from the deck
    if(gp.isHitting() == true)
    {
        gp.userHand.push_back(deckOfCards[0]);
        deckOfCards.erase(deckOfCards.begin());
    }
}

