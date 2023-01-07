#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <map>
#include <vector>

using namespace std;
using std::string, std::vector;

static vector<string> cValues = {"A","2","3","4","5","6","7","8","9","10","J","K","Q"};
static vector<string> cSuits = {"♡","♢","♧","♤"};

class Card {
    public:
        Card(const int &cValue, const int &cSuit) noexcept;
        const string GetValue() noexcept;
        const string GetSuit() noexcept;
    private:
        string value;
        string suit;
};

#endif