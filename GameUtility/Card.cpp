#include "Card.hpp"

using std::string;

Card::Card(const int &cValue, const int &cSuit) noexcept{
    value = cValues[cValue];
    suit = cSuits[cSuit];
}

const string Card::GetSuit() noexcept{
    return suit;
}

const string Card::GetValue() noexcept{
    return value;
}