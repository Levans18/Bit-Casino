#include "Deck.hpp"
#include <vector>
#include <algorithm>
#include <random>

#define NUM_VALUES 13
#define NUM_SUITS 4

using namespace std;
using std::vector;


Deck::Deck(){
    cards = NewDeck();
}

vector<Card> Deck::NewDeck(){
    vector<Card> newCards;
    for(int i = 0; i < NUM_VALUES; i++){
        for(int j = 0; j < NUM_SUITS; j++){
            newCards.push_back(Card(i, j));
        }
    }
    return newCards;
}

Card Deck::GetCard(int &&cardPos) noexcept{
    return cards[cardPos];
}

void Deck::ShuffleDeck() noexcept{
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(cards), std::end(cards), rng);
}