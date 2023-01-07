#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include <vector>
#include "../GameUtility/Deck.hpp"

using namespace std;


void ClearCin();
class Blackjack {
    public:
        int StartGame(int &balance);
        int GetBet(int &balance, int &bet);
        int GetCount(vector<Card> &cards, bool hideHouse = false);
        void PlayBlackjack(int &balance, int &bet);
        int PlayerTurn(vector<Card> &pCards, vector<Card> &hCards, bool &hideHouse);
        int HouseTurn(vector<Card> &pCards, vector<Card> &hCards, bool &hideHouse);
        void HowToPlay();
        void PrintBoard(vector<Card> &pCards, vector<Card> &hCards, bool hideHouse);
        void PrintSplitBoard(int &balance, vector<Card> &pCards1, vector<Card> &pCards2, vector<Card> &hCards);
    private:
        Deck deck;
};


#endif