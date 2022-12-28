#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
#include "./GameUtility/Card.hpp"
#include "./GameUtility/Deck.hpp"
#include "./GameModes/Blackjack.hpp"

using namespace std;

int main(int argc, char **argv){
    using std::cout, std::cin, std::endl;
    int balance = 500;
    auto userInput = 0;

    while(userInput != 4){
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "* Welcome to The Bit Casino *" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

    cout << std::setw(29) << "balance: " << endl;
    cout << "Select a Game: ⬇" << endl;
    cout << "1. BlackJack ♠️" << endl;
    cout << "2. Slots 🎰" << endl;
    cout << "3. Roullette 🤞" << endl;
    cout << "4. Exit" << endl;
    cout << "(>";
    cin >> userInput;

    unique_ptr<Blackjack> bj;

    switch (userInput)
    {
    case 1:
        /* code */
        balance = bj->StartGame(balance);
        break;
    case 2:
        break;

    case 3:

        break;

    case 4: 
        break;

    default:
        cout << "Invalid Input " << userInput;
        break;
    }
    }
}