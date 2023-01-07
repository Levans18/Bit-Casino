#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Blackjack.hpp"

#define PLAYERWIN 0
#define HOUSEWIN 1
#define TIE 2
#define BLACKJACK 3
#define FIVEDEALT 4
#define BUST 5

using namespace std;
using std::cout,std::cin, std::endl;
using std::string;


void ClearCin(){
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

int Blackjack::StartGame(int &balance){
    int userInput, bet;
    bool exit = false;

    while(userInput != 4){
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "**********  ******   **           **     ********  **   **         **     **     ********  **   **   ********** " << endl;
        cout << "* A    ♡ *  **   **  **          ****    **    **  ** **           **    ****    **    **  ** **     * A    ♡ * " << endl;
        cout << "*        *  *******  **         **  **   **        ****            **   **  **   **        ****      *        * " << endl;
        cout << "*        *  **    ** **        ********  **        ****            **  ********  **        ****      *        * " << endl;
        cout << "* ♡    A *  **   **  **        **    **  **    **  **  **    **    **  **    **  **    **  **  **    * ♡    A * " << endl;
        cout << "**********  ******   ********  **    **  ********  **    **  ********  **    **  ********  **    **  ********** " << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << std::setw(79) << "| 1. Play | 2. Practice | 3. How To Play | 4. Exit | "<< std::setw(32 - std::to_string(balance).size()) << "Balance: $" << balance << endl;
        cout << "(> ";

        cin >> userInput;
        switch (userInput)
        {
        case 1:
            /* code */
            system("clear");
            GetBet(balance, bet);
            if(bet != 0){
                PlayBlackjack(balance, bet);
            }
            ClearCin();
            break;
        case 2:
            bet = 0;
            PlayBlackjack(balance, bet);
            break;
        case 3:
            HowToPlay();
            break;
        case 4:
            break;
        default:
            ClearCin();
            cout << "Invalid Input " << endl;
            system("clear");
            break;
        }
    }

    return balance;
}

int Blackjack::GetBet(int &balance, int &bet){
    bool validInput = false;

    while(!validInput){
        cout << "How much would you like to bet? (" << balance << " available | 0 to quit)" << endl;
        cout << "(> " ;
        if(cin >> bet){
            if(bet >= 0 && bet <= balance){
                validInput = true;
            }else{
                ClearCin();
                cout << "Invalid Amount Enter an Integer from 0 - " << balance << endl;
            }
        }else{
            ClearCin();
            cout << "Invalid Amount Enter an Integer from 0 - " << balance << endl;
        }
    }
    system("clear");
    return bet;
}

void PrintTopNBottom(vector<Card> &cards){
    for(int i = 0; i < 5; i++){
        if(i < cards.size()){
            cout << " -------- ";
        }else{
            cout << "          ";
        }
    }
    cout << " |";

}


void Blackjack::PrintBoard(vector<Card> &pCards, vector<Card> &hCards, bool hideHouse){
    cout << " ---------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Player                                             | House                                              |" << endl;
    /* Top of Cards */
    cout << "| ";
    PrintTopNBottom(pCards);
    cout << " ";
    PrintTopNBottom(hCards);
    cout << endl;
    /* Letter First Portion */
    cout << "| ";
    /*Player*/
    for(int i = 0; i < 5; i++){
        if(i < pCards.size()){
            cout << "| ";
            if(pCards[i].GetValue().size() > 1){
                cout << pCards[i].GetValue();
            }else{
                cout << pCards[i].GetValue(); 
                cout << " ";
            }
            cout << "   ";
            cout << pCards[i].GetSuit();
            cout << " |";
        }else{
            cout << "          ";
        }
    }
    cout << " | ";
    /*House*/
    for(int j = 0; j < 5; j++){
        if(j < hCards.size()){
            if(j == 1 && hideHouse){
                cout << "|        |";
            }else{
                cout << "| ";
                if(hCards[j].GetValue().size() > 1){
                    cout << hCards[j].GetValue();
                }else{
                    cout << hCards[j].GetValue(); 
                    cout << " ";
                }
                cout << "   ";
                cout << hCards[j].GetSuit(); 
                cout << " |";
            }
        }else{
            cout << "          ";
        }
    }
    cout << " |" << endl;
    /* Middle Parts of Cards */
    for(int i = 0; i < 2; i++){
        cout << "| ";
        for(int j = 0; j < 5; j++){
            if(j < pCards.size()){
                cout << "|        |";
            }else{
                cout << "          ";
            }
        }
        cout << " | ";
        for(int k = 0; k < 5; k++){
            if(k < hCards.size()){
                cout << "|        |";
            }else{
                cout << "          ";
            }
        }
        cout << " |" << endl;
    }
    /* Second Letter Portion */
    cout << "| ";
    /*Player*/
    for(int i = 0; i < 5; i++){
        if(i < pCards.size()){
            cout << "| ";
            cout << pCards[i].GetSuit();
            cout << "   ";
            if(pCards[i].GetValue().size() > 1){
                cout << pCards[i].GetValue();
            }else{
                cout << " ";
                cout << pCards[i].GetValue(); 
            }
            cout << " |";
        }else{
            cout << "          ";
        }
    }
    cout << " | ";
    /*House*/
    for(int j = 0; j < 5; j++){
        if(j < hCards.size()){
            if(j == 1 && hideHouse){
                cout << "|        |";
            }else{
                cout << "| ";
                cout << hCards[j].GetSuit();
                cout << "   ";
                if(hCards[j].GetValue().size() > 1){
                    cout << hCards[j].GetValue();
                }else{
                    cout << " ";
                    cout << hCards[j].GetValue(); 
                }
                cout << " |";
            }
        }else{
            cout << "          ";
        }
    }
    cout << " |" << endl;
    /* Bottom of Cards */
    cout << "| ";
    for(int i = 0; i < 5; i++){
        if(i < pCards.size()){
            cout << " -------- ";
        }else{
            cout << "          ";
        }
    }
    cout << " | ";
    for(int j = 0; j < 5; j++){
        if(j < hCards.size()){
            cout << " -------- ";
        }else{
            cout << "          ";
        }
    }
    cout << " |" << endl;
    /*Count*/
    if(GetCount(pCards)/10 > 0){
        cout << "|                                          Count: " << GetCount(pCards, false) << " ";
    }else{
        cout << "|                                           Count: " << GetCount(pCards, false) << " ";
    }

    if(GetCount(hCards)/10 > 0){
        cout << "|                                          Count: " << GetCount(hCards, hideHouse) << " ";
    }else{
        cout << "|                                           Count: " << GetCount(hCards, hideHouse) << " ";
    }

    cout << "|" << endl;

    cout << " ---------------------------------------------------------------------------------------------------------" << endl;
}

void Blackjack::PrintSplitBoard(int &balance, vector<Card> &pCards1, vector<Card> &pCards2, vector<Card> &hCards){

    cout << " ------------------------------------------------------ " << endl;
    cout << "| House                                                |" << endl;
    cout << "|  --------  --------  --------  --------  --------    |" << endl;
    cout << "| | A    ♡ ||        ||        ||        ||        |   |" << endl;
    cout << "| |        ||        ||        ||        ||        |   |" << endl;
    cout << "| |        ||        ||        ||        ||        |   |" << endl;
    cout << "| | ♡    A ||        ||        ||        ||        |   |" << endl;
    cout << "|  --------  --------  --------  --------  --------    |" << endl;
    cout << "|                                              Count:  |" << endl;
    cout << " ------------------------------------------------------ " << endl;
    cout << " ------------------------------------------------------ " << endl;
    cout << "| Player                                               |" << endl;
    cout << "|  --------  --------  --------  --------  --------    |" << endl;
    cout << "| | A    ♡ ||        ||        ||        ||        |   |" << endl;
    cout << "| |        ||        ||        ||        ||        |   |" << endl;
    cout << "| |        ||        ||        ||        ||        |   |" << endl;
    cout << "| | ♡    A ||        ||        ||        ||        |   |" << endl;
    cout << "|  --------  --------  --------  --------  --------    |" << endl;
    cout << "|                                              Count:  |" << endl;
    cout << " ------------------------------------------------------ " << endl;
}

int Blackjack::PlayerTurn(vector<Card> &pCards, vector<Card> &hCards, bool &hideHouse){
    string playerMove = "";
    while(playerMove != "s" && playerMove != "S"){
        system("clear");
        PrintBoard(pCards, hCards, hideHouse);
        if(GetCount(pCards) > 21){
            return BUST;
        }else if(pCards.size() == 5){
            return FIVEDEALT;
        }else if(GetCount(pCards) == 21){
            return BLACKJACK;
        }
        else{
            cout << "(H/h to Hit | S/s to Stand)> ";
            cin >> playerMove;
            if(playerMove == "h" || playerMove == "H"){
                pCards.push_back(deck.RemoveFirst());
            }
        }
    }
    system("clear");
    return 0;
}

int Blackjack::HouseTurn(vector<Card> &pCards, vector<Card> &hCards, bool &hideHouse){
    while(true){
        system("clear");
        PrintBoard(pCards, hCards, hideHouse);
        if(GetCount(hCards) > 21){
            return BUST;
        }else if(GetCount(hCards) >= 17){
            if(GetCount(pCards) > GetCount(hCards)){
                return PLAYERWIN;
            }else if(GetCount(pCards) < GetCount(hCards)){
                return HOUSEWIN;
            }else{
                return TIE;
            }
        }
        std::__libcpp_thread_sleep_for(1s);
        hCards.push_back(deck.RemoveFirst());
    }
}


void Blackjack::PlayBlackjack(int &balance, int &bet){
    int playerResult = 0;
    bool gameFinished = false;
    bool hideHouse = true;
    string move, toMainMenu;
    deck.ShuffleDeck();
    vector<Card> pCards = {deck.RemoveFirst(), deck.RemoveFirst()};
    vector<Card> hCards = {deck.RemoveFirst(), deck.RemoveFirst()};
    playerResult = PlayerTurn(pCards, hCards, hideHouse);
    if(playerResult == BUST){
        balance = balance - bet;
        cout << "Loss: You Busted :( (Player Count > 21)" << endl;

    }else if(playerResult == FIVEDEALT){
        balance = balance + bet;
        cout << "Win! (5 Cards dealt before 21)" << endl;

    }else if(playerResult == BLACKJACK){
        balance = balance + bet * 1.25;
        cout << "Blackjack! (Count is 21 | 1.25x payout)" << endl;

    }else{
        hideHouse = false;
        playerResult = HouseTurn(pCards, hCards, hideHouse);
        if(playerResult == BUST){
            balance = balance + bet;
            cout << "House Bust! (1x payout)" << endl;

        }else if(playerResult == PLAYERWIN){
            balance = balance + bet;
            cout << "You Win! (1x payout)" << endl;

        }else if(playerResult == HOUSEWIN){
            balance = balance - bet;
            cout << "You Lost (1x loss)" << endl;

        }else {
            cout << "You Tied :^() (no change)" << endl;
        }
    }
    if(balance == 0){
        cout << "You Ran out of money $100 lifeline added" << endl;
        balance += 100;
    }
    cout << "Enter any input to continue ..." << endl;
    cin >> toMainMenu;
    system("clear");
 }

int Blackjack::GetCount(vector<Card> &cards, bool hideHouse){
    int count = 0;
    for(int i = 0; i < cards.size(); i++){
        if(!hideHouse || i != 1){
            string val = cards[i].GetValue();
            if(val == "10" || val == "J" || val == "Q" || val == "K"){
                count += 10;
            }else if(val != "A"){
                count += std::stoi(val);
            }
        }
    }
    for(int j = 0; j < cards.size(); j++){
        if(!hideHouse || j != 1){
            string val = cards[j].GetValue();
            if(val == "A"){
               if(count > 10){
                count += 1;
               }else{
                count += 11;
               }
            }
        }
    }
    return count;
}
void Blackjack::HowToPlay(){

}