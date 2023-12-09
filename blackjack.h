#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "card.h"

class BlackJack: public Card    //inherit card class 
{
    private:
        double BJmoney;     //starting money value
        double BJbet;       //current BJ bet
        double currentBJmoney;  //current 
        bool insurance;         //check if insurance is applied
        bool dealerbj;          //true if blackjack - cards = 21
        bool playerbj;          //player bj true =  21 
        int MAXCARDS;           //max cards in deck (10)
        int dealerCounter;      //counter variables
        int playerCounter;

    public:    
        BlackJack();    //constructor set values to 0
        ACard BJdealerHand[10];     //dealer hand   
        ACard BJplayerHand[10];     //player hand - size 10 for max number of cards in hand

        double getBJMoney();        //get starting game money
        double getBJbet();          //get BJ round bet
        
        void setDealerCounter(int);     //setter dealer counter variable
        void setPlayerCounter(int);     //setter player ctr

        void setBJMoney(double);        //setter for bj money 
        void setBJbet(double);
        
        void checkInsurance();      //if dealer open hand is ace - sell player insurance

        //check blackjack 
        bool CheckdealerBJ();      //if the dealer has blackjack return true else false 
        bool CheckplayerBJ();       //check player blackjack 
        void checkWinner();           //check win conditions 
        void holdorhit();       //ask if player wants to hit - add another card or hold - keep cards against dealer

        void cleardecks();      //clean - reset decks back to default 
        double returnMoney();     //return bjMoney value to main 
};

#endif