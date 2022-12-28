#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <map>
#include <vector>

using namespace std;
using std::string, std::vector;

static vector<string> cValues = {"ace","two","three","four","five","six","seven","eight","nine","ten","jack","queen","king"};
static vector<string> cSuits = {"hearts","diamonds","clubs", "spades"};

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