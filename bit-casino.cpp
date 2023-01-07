#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <utility>
#include "./GameUtility/Card.hpp"
#include "./GameUtility/Deck.hpp"
#include "./GameModes/Blackjack.hpp"

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

int main(int argc, char **argv){
    bool validInput = false;
    using std::cout, std::cin, std::endl;
    int balance = 1000;
    auto userInput = 0;

    while(userInput != 4){
        system("clear");
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "* Welcome to The Bit Casino *" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

        cout << std::setw(26) << "balance: " << balance << endl;
        cout << "Select a Game: ⬇" << endl;
        cout << "1. BlackJack ♠️" << endl;
        cout << "2. Slots 🎰" << endl;
        cout << "3. Roullette 🤞" << endl;
        cout << "4. Exit" << endl;
        cout << "(> ";

        unique_ptr<Blackjack> bj = make_unique<Blackjack>();
        cin >> userInput;
        validInput = true;
        switch (userInput)
        {
        case 1:
            /* code */
            system("clear");
            balance = bj->StartGame(balance);
            validInput = true;
            ClearCin();
            break;
        case 2:
            ClearCin();

            break;

        case 3:
            ClearCin();

            break;

        case 4: 
            ClearCin();

            break;

        default:
            validInput = false;
            ClearCin();
            cout << "Please Enter a Number (1-4)" << endl;
            std::__libcpp_thread_sleep_for(1s);
            break;
        }
    }
}