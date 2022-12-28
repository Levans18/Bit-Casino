#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "../GameUtility/Deck.hpp"

using namespace std;

class Blackjack {
    public:
        int StartGame(int startingBal);
        void Turn();
        void PrintBoard();
    private:
        int balance = 500;
        Deck deck;
};


#endif