#ifndef DECK_HPP
#define DECK_HPP
#include "Card.hpp"
#include <vector>
#include <utility>

using namespace std;
using std::vector;

class Deck {
    public:
        Deck();
        vector<Card> NewDeck();
        Card GetCard(int &&cardPos) noexcept;
        Card RemoveFirst();
        void ShuffleDeck() noexcept;
    private:
        vector<Card> cards;
};

#endif