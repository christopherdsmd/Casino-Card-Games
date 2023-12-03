#include<iostream>
#include<iomanip>
#include"card.h"
#include<cstring>
using namespace std; 

//constructor
Card::Card() //set deck Cards[] to 0 - 13 and 1 -4 for suit for all 52 cards 
{
int setNum = 1;
int switchSuit = 1;
nextCard = 0;

//initalize all card deck 
for(int i = 0; i < 52; i++)
{
    if(setNum <= 13) {
    Cards[i].num = setNum;
        switch(switchSuit)
        {
            case 1:
            strcpy(Cards[i].suit, spade);
            break;
            case 2:
            strcpy(Cards[i].suit, club);
            break;
            case 3:
            strcpy(Cards[i].suit, heart);
            break;
            case 4:
            strcpy(Cards[i].suit, diamond);
            break;
            default: 
            cout << "Error setting suit" << endl;
            return;
            break;
        }
        setNum++;
        
} else {
    //reset to 1 loop again
        setNum = 1;
        switchSuit++;
        i--;
        }
}   
}


void Card::shuffleCard() 
{
 
    ACard shuffle[52];
    for(int i = 0; i < 52; i++) 
    {
        shuffle[i] = Cards[i];  //take values from caeds into shuffle deck
    }

    //shuffle deck
    for(int i = 51; i > 0; i--)
    {
        int r = rand() % (i + 1);

        //swap
        ACard temp = shuffle[i];
        shuffle[i] = shuffle[r];
        shuffle[r] = temp;
    }

    //put values from shuffled deck into Cards deck
    for(int i = 0; i < 52; i++) 
    {
        Cards[i] = shuffle[i];
    }

    this->nextCard = 0; //set next card to 0
}

ACard Card::getCard() 
{
        if(nextCard >= 51)
        {
            nextCard = 0;
            shuffleCard();
        }

        //reutrn next card value and update next card value
        ACard temp = Cards[nextCard];
        nextCard++;

        return temp;
}


void Card::printHand(ACard Hand[], int size) 
{

for(int i = 0; i < 11; i ++) 
{
    for(int j = 0; j < size; j++) 
    {
        switch(Hand[j].num) 
            {
                case 1:
                CardAce(Hand[j].suit, i);
                break;

                case 2:
                CardTwo(Hand[j].suit, i);
                break;

                case 3:
                CardThree(Hand[j].suit, i); 
                break;

                case 4:
                CardFour(Hand[j].suit,i);
                break;

                case 5:
                CardFive(Hand[j].suit,i);
                break;

                case 6:
                CardSix(Hand[j].suit,i);
                break;

                case 7:
                CardSeven(Hand[j].suit,i);
                break;

                case 8:
                CardEight(Hand[j].suit,i);
                break;

                case 9:
                CardNine(Hand[j].suit, i);
                break;

                case 10:
                CardTen(Hand[j].suit, i);
                break;

                case 11:
                CardJack(Hand[j].suit, i);
                break;

                case 12:
                CardQueen(Hand[j].suit, i);
                break;

                case 13:
                CardKing(Hand[j].suit, i);
                break;
            }
        }
        cout << endl;
    }   
}

void Card::printCard() {
    for (int i = 0; i < 52; i++) {
        cout << "[" << Cards[i].num << ", " << Cards[i].suit << "]"  << endl;
    }
}



//card print functions 
void Card::CardAce(char suit [], int i)
{

switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|A      |" ;
break;
case 2: 
cout << "|       |" ;
break;
case 3:
cout << "|       |";
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "|   "<<suit<<"   |"; 
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "|       |";
break;
case 9:
cout << "|      A|";
break;
case 10:
cout << "---------";
break;
}

} // ACE - 1 
void Card::CardTwo(char suit[], int i)
{
switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|2      |" ;
break;
case 2: 
cout << "|       |" ;
break;
case 3:
cout << "|   "<<suit<<"   |"; 
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "|       |"; 
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|   "<<suit<<"   |"; 
break;
case 8:
cout << "|       |";
break;
case 9:
cout << "|      2|";
break;
case 10:
cout << "---------";
break;
}
}

void Card::CardThree(char suit[] , int i) 
{
{
switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|3      |" ;
break;
case 2: 
cout << "|   "<<suit<<"   |";
break;
case 3:
cout << "|       |";
break;
case 4:
cout << "|       |"; 
break;
case 5: 
cout << "|   "<<suit<<"   |";
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "|   "<<suit<<"   |";
break;
case 9:
cout << "|      3|";
break;
case 10:
cout << "---------";
break;
}
}

}


void Card::CardFour(char suit [], int i) 
{
switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|4      |" ;
break;
case 2: 
cout << "| "<<suit<<"   "<<suit<<" |" ;
break;
case 3:
cout << "|       |"; 
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "|       |"; 
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 9:
cout << "|      4|";
break;
case 10:
cout << "---------";
break;
}
}

void Card::CardFive(char suit[], int i) 
{
switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|5      |" ;
break;
case 2: 
cout << "| "<<suit<<"   "<<suit<<" |" ;
break;
case 3:
cout << "|       |"; 
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "|   "<<suit<<"   |"; 
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 9:
cout << "|      5|";
break;
case 10:
cout << "---------";
break;
}    
}

void Card::CardSix(char suit[], int i) 
{
switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|6      |" ;
break;
case 2: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 3:
cout << "|       |"; 
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 9:
cout << "|      6|";
break;
case 10:
cout << "---------";
break; 
}
}

void Card::CardSeven(char suit[], int i)
{
switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|7      |" ;
break;
case 2: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 3:
cout << "|   "<<suit<<"   |"; 
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 9:
cout << "|      7|";
break;
case 10:
cout << "---------";
break; 
}
}

void Card::CardEight(char suit[], int i) 
{
switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|8      |" ;
break;
case 2: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 3:
cout << "|   "<<suit<<"   |"; 
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 6:
cout << "|       |";
break;
case 7:
cout << "|   "<<suit<<"   |"; 
break;
case 8:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 9:
cout << "|      8|";
break;
case 10:
cout << "---------";
break; 
    }
}



void Card::CardNine(char suit[] , int i) 
{
   switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|9      |" ;
break;
case 2: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 3:
cout << "|   "<<suit<<"   |"; 
break;
case 4:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 5: 
cout << "|       |";
break;
case 6:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 9:
cout << "|      9|";
break;
case 10:
cout << "---------";
break; 
    } 
}


void Card::CardTen(char suit[], int i) 
{
    switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|10     |" ;
break;
case 2: 
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 3:
cout << "|   "<<suit<<"   |"; 
break;
case 4:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 5: 
cout << "|       |";
break;
case 6:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 7:
cout << "|   "<<suit<<"   |"; 
break;
case 8:
cout << "| "<<suit<<"   "<<suit<<" |";
break;
case 9:
cout << "|     10|";
break;
case 10:
cout << "---------";
break; 
    }    
}

void Card::CardJack(char suit[], int i ) 
{
 switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|J      |" ;
break;
case 2: 
cout << "|       |" ;
break;
case 3:
cout << "|       |";
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "|   "<<suit<<"   |"; 
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "|       |";
break;
case 9:
cout << "|      J|";
break;
case 10:
cout << "---------";
break;
}   
}
void Card::CardQueen(char suit[], int i) 
{
    switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|Q      |" ;
break;
case 2: 
cout << "|       |" ;
break;
case 3:
cout << "|       |";
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "|   "<<suit<<"   |"; 
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "|       |";
break;
case 9:
cout << "|      Q|";
break;
case 10:
cout << "---------";
break;
}
}

void Card::CardKing(char suit[], int i) 
{
    switch(i) 
{
case 0:
cout << "---------" ;
break;
case 1: 
cout << "|K      |" ;
break;
case 2: 
cout << "|       |" ;
break;
case 3:
cout << "|       |";
break;
case 4:
cout << "|       |";
break;
case 5: 
cout << "|   "<<suit<<"   |"; 
break;
case 6: 
cout << "|       |";
break;
case 7:
cout << "|       |";
break;
case 8:
cout << "|       |";
break;
case 9:
cout << "|      K|";
break;
case 10:
cout << "---------";
break;
}
}

//sorting algorithm 
void Card::sort(ACard hand[], int size)
{
//bubble sort to sort poker game userhand 
    int i,j;
    for(i = 0; i < size -1; i++) 
    {
        for(j = 0; j < size-i-1; j++) 
        {
            if(hand[j].num  > hand[j+1].num) 
            {
                //swap
                int temp = hand[j].num;
                hand[j].num = hand[j+1].num;
                hand[j+1].num = temp;
            }
        }
    }
}

void Card::printArt() {
    std::cout << "       .-------.    ______" << std::endl;
    std::cout << "      /   o   /|   /\\     \\" << std::endl;
    std::cout << "     /_______/o|  /o \\  o  \\" << std::endl;
    std::cout << "     | o     | | /   o\\_____\\" << std::endl;
    std::cout << "     |   o   |o/ \\o   /o    /" << std::endl;
    std::cout << "     |     o |/   \\ o/  o  /" << std::endl;
    std::cout << "     '-------'     \\/____o/" << std::endl << std::endl;
}