#ifndef POKER_H
#define POKER_H
#include "card.h"

class Poker: public Card    //inherit card class 
{
    private:
        double startingMoney;   //starting money
        double userBet;         //current user bet
        double currentBal; //current    
        int handSize;

    public:
        Poker();    //constructor - display poker starting text - set variables for game
        ACard pokerHand[5]; // 5 card hand for poker game 

        //getter 
        double getstartMon();
        double getuserBet();

        //setter
        void setStartMon(double x); //update starting money
        void holdRedraw(int size); //function for hold or redraw hand. param for itteration
        int handCheck(int size);    //function to check if user has winning hand and return multiplied bet
        void printTable();  //cout to user possible winning hands and the multiplier 

        double checkWins(int size);    //function to check the winning suits for poker, if win multiply userbet value and add to currentBal
        //win conditions
        bool checkRoyalStraightFlush();
        bool checkStraighFlush();
        bool checkFourCard();
        bool checkFullHouse();
        bool checkFlush();
        bool checkStraight();
        bool checkTriple();
        bool checkTwoPair();
        bool checkJackorBetter();
        bool checkOnePair();
};

#endif