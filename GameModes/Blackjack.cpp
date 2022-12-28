#include <string>
#include <iostream>
#include "Blackjack.hpp"

using namespace std;
using std::cout,std::cin, std::endl;
using std::string;

int Blackjack::StartGame(int startingBal){
    balance = startingBal;
    string userInput;
    bool exit = false;

    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cout << "**********  ******   **           **     ********  **   **         **     **     ********  **   **   ********** " << endl;
    cout << "* A    ♡ *  **   **  **          ****    **    **  ** **           **    ****    **    **  ** **     * A    ♡ * " << endl;
    cout << "*        *  *******  **         **  **   **        ****            **   **  **   **        ****      *        * " << endl;
    cout << "*        *  **    ** **        ********  **        ****            **  ********  **        ****      *        * " << endl;
    cout << "* ♡    A *  **   **  **        **    **  **    **  **  **    **    **  **    **  **    **  **  **    * ♡    A * " << endl;
    cout << "**********  ******   ********  **    **  ********  **    **  ********  **    **  ********  **    **  ********** " << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cin >> userInput;

    PrintBoard();

    return balance;
}

void Blackjack::PrintBoard(){
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                    balance:" << balance;
    cout << "                                                                                                               |";
}