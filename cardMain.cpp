//programmer: Christopher Desmond
//project - Casino Card Game with Inheritance, Poker & Black Jack Games 
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"card.h"
#include"poker.h"
#include"poker.cpp"
#include"blackjack.h"
#include"blackjack.cpp"
using namespace std; 

int main () {
srand(time(0));    //seed for rand

Poker poker;        //object for poker 
BlackJack bj;       //object for black jack 

//menu var
int userValue = -1;

//poker variables
const int handSize = 5;     //hand size for poker

double gameMoneyPoker = -1;  //balance for each individual game
double usrBet = -1;            //holds user bet value 
double betMultiply = -1;        //winning hands multipler for bet

//blackjack variables
const int MAXCARDS = 10;

double gameMoneyBJ = -1;  //balance for each individual game
double BJbet = -1;          //holds user BLACK JACK GAME bet value 
double betMultiplyBJ = -1;      //BJ Game winning hands multipler for bet

cout << spade << club << heart << diamond << " Welcome to Casino Card Games! " << spade << club << heart << diamond << endl;
poker.printArt();

//ask for game money here 
    while(userValue != 3) //game menu
    {
    cout << spade << club << heart << diamond << " Card Games Menu " << spade << club << heart << diamond << endl;
    cout << "1: 5 Card Poker" << endl;
    cout << "2: Black Jack" << endl;
    cout << "3: Exit Program" << endl << endl;

    while(!(cin >> userValue))      //error check 
    {   
        cin.clear();
        cin.ignore();
    }

    char playAgain = 'y';
    char BJplayAgain = 'y';

    switch(userValue)
    {
    case 1: //poker game
        cout << endl << spade << club << heart << diamond << " Five Card Poker!  " << spade << club << heart << diamond  << endl;     

        //get starting money for each game
        gameMoneyPoker = poker.getstartMon(); 
        poker.setStartMon(gameMoneyPoker);

        //game loop
        while(playAgain == 'y') {
          betMultiply = -1;       //reset bet multiplier

            cout << "$" << fixed << setprecision(2) << gameMoneyPoker << " - Credit" <<  endl;    //print remaning credit 
            //get bet for each round 
                    
            poker.setStartMon(gameMoneyPoker);  //update class staring money
            usrBet = poker.getuserBet();    
            gameMoneyPoker = gameMoneyPoker - usrBet;    //update staring money

            cout << "$" << fixed << setprecision(2) << gameMoneyPoker << " - Credit" <<  endl;    //print remaning credit 
            cout << "$" << fixed << setprecision(2) << usrBet << " - Current Bet" <<  endl;    //print remaning credit 

            //Game start
            poker.shuffleCard(); //shuffling deck   //inheritance

            //poker hand fill with 5 shuffled cards cards 0 - 4 used for game 
            for(int i = handSize-1; i >= 0; i--)
            {
                poker.pokerHand[i] = poker.getCard(); //inheritance
            }
            
            //print users hand 
            poker.printTable(); //print possible winning hands to user 

            cout << "Your Hand" << endl;
            poker.printHand(poker.pokerHand, handSize); //inheritance

            poker.shuffleCard();
            poker.holdRedraw(handSize);    //hand size 5  - function ask user to hold or redraw each card

            poker.sort(poker.pokerHand, handSize);
            poker.printHand(poker.pokerHand, handSize); //print again //inheritance
            
            //check winning hands 
            betMultiply = poker.checkWins(handSize); 
            
            //win multiply
            if(betMultiply != -1) 
            {
                gameMoneyPoker = gameMoneyPoker + usrBet; // return the inital bet 
                usrBet = usrBet * betMultiply;  //multiply the bet 
                gameMoneyPoker = gameMoneyPoker + usrBet;
                poker.setStartMon(gameMoneyPoker);  //update class staring money
                cout << "You Won! " << "$" << fixed << setprecision(2) << usrBet << "- added to credit" <<  endl;    //print remaning credit   << usrBet;        
            } else 
            {
                cout << "You Lose" << endl; 
            }

            poker.setStartMon(gameMoneyPoker);  //update class staring money

            //game over
            cout << "Game over - returning to menu" << endl;

            //ask to play again
            cout << "Would you like to play again?" << endl << endl;
            cout << "Y - Play again" << endl;
            cout << "N - Quit" << endl;
            
            while(!(cin >> playAgain)) 
                {
                    cin.clear();
                    cin.ignore();
                }                
                //cash out 
            }
        break;

    case 2:     //black jack
    cout << endl << spade << club << heart << diamond << " Black Jack! " << spade << club << heart << diamond  << endl;

    //get starting money for each game from user
    gameMoneyBJ = bj.getBJMoney();
    bj.setBJMoney(gameMoneyBJ); //set the money

    //game loop
    while(BJplayAgain == 'y') 
    {
        cout << "$" << fixed << setprecision(2) << gameMoneyBJ << " - Credit" <<  endl;    //print remaning credit 

        //get round bet
        bj.setBJMoney(gameMoneyBJ);  //update class staring money
        BJbet = bj.getBJbet();    
        
        //bet DOES NOT SUBTRACT FROM GAMEMONEYBJ
        cout << "$" << fixed << setprecision(2) << gameMoneyBJ << " - Credit" << endl;    //print remaning credit 
        cout << "$" << fixed << setprecision(2) << BJbet << " - Current Bet" << endl << endl;    //print remaning credit 

        //game start 
        bj.shuffleCard(); //inheritance      //shuffle the cards     
            //deal dealer and player 2 cards 
            //set dealer hand 
            for(int i = 1; i >= 0; i--)
            {
                bj.BJdealerHand[i] = bj.getCard();      //inheritance
            }

            //set player hand 2 cards
            for(int i = 1; i >= 0; i--)
            {
                bj.BJplayerHand[i] = bj.getCard();      //inheritance
            }        

            //show only 1 card of dealer
            cout << "Dealer Open Card" << endl;
            bj.printHand(bj.BJdealerHand, 1);       //inheritance

            //player hand - print both cards
            cout << "Your Hand" << endl;
            bj.printHand(bj.BJplayerHand, 2);       //inheritance

            bj.checkInsurance();    //check insurance and sell to player if dealer open card is ace
            bj.holdorhit();          //ask player to hold or hit deck
        
            //END OF ROUND 
            //print all dealer hands 
                cout << "Your Hand" << endl;
                bj.printHand(bj.BJplayerHand, MAXCARDS);    //inheritance    //MAXCARDS = 10

                cout << "Dealer Hand" << endl;
                bj.printHand(bj.BJdealerHand, MAXCARDS);//inheritance

                bj.checkWinner();   //check winning conditions 

                gameMoneyBJ = bj.returnMoney(); //return the class money value
                cout << "$" << fixed << setprecision(2) << gameMoneyBJ << " - Credit" << endl;    //print remaning credit

        //game over
        cout << "Game over - returning to menu" << endl;
        bj.cleardecks();        //clean program 

        //ask to play again loop
        cout << "Would you like to play again?" << endl << endl;
        cout << "Y - Play again" << endl;
        cout << "N - Quit" << endl;
            
        while(!(cin >> BJplayAgain)) 
        {
            cin.clear();
            cin.ignore();
        }

        //cash out
    }

    break;
    case 3: //exit program
        cout << "Exiting Program - Thanks for playing" << endl;
        exit(0);

        //print Credit - Cash out

        break;

    default:
        cout << "invalid selection, select a valid menu option" << endl;
        break;
        }
    }
    return 0;
}
