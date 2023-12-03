#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<iomanip>
#include<ctime> //seed for random num generator
#include<cstdlib>
#include<cstring>

const char spade[4] = "\xe2\x99\xa0";  //card suits unicode
const char club[4] = "\xe2\x99\xa3";
const char heart[4] = "\xe2\x99\xa5";
const char diamond[4] = "\xe2\x99\xa6";

    struct ACard  //struct for individual card
        {
            int num; //number on card  1 - A ,  2 - 10 , 11 - j , 12 - q , 13 - k 
            char suit[4]; 
        };

class Card //stores deck of card and multiuse function for diffrent card games
{
    private:

        ACard Cards[52];  //array - deck of 52 cards 
        int nextCard;    //return index for next available card 

    public:
        Card();  //constructor sets the 52 cards before shuffle 
        void shuffleCard(); //rand num generator shuffle cards 
        ACard getCard(); //getter

        //functions to display the cards output
        void CardAce(char suit[], int i); // ACE - 1
        void CardTwo(char suit[], int i);
        void CardThree(char suit[], int i);
        void CardFour(char suit[], int i);
        void CardFive(char suit[], int i);
        void CardSix(char suit[], int i);
        void CardSeven(char suit[], int i);
        void CardEight(char suit[], int i);
        void CardNine(char suit[], int i);
        void CardTen(char suit[], int i);
        void CardJack(char suit[], int i);
        void CardQueen(char suit[], int i);
        void CardKing(char suit[], int i);

        void printHand(ACard [] , int); //prints the hand 
        void printCard();
        void printArt();

        void sort(ACard[],  int size);    //sorting alg sort the user cards
};

#endif
