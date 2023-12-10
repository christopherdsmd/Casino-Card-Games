#include<iostream>
#include<iomanip>
#include<cstring>
#include"poker.h"

using namespace std; 

Poker::Poker() //initalize vars
{   
        double startingMoney = 0.00;   //starting money
        double userBet = 0.00;         //current user bet
        double currentBal = 0.00; //current    

         handSize =5;
}   

//gets use bet value , the bet checker param is passed copy of current game money credit used to make sure bets cannot be greater the game money
double Poker::getuserBet(double creditChecker)   //getter user bet for each round
{
    cout << "How much money would you like to bet" << endl;

    while(!(cin >> userBet) || userBet > creditChecker)    //error check, bet must be less than or equal to staring money
    {
        cout << "Invalid bet amount - must be less than or equal to credit value"  << endl;
        cin.clear();
        cin.ignore();
    }
    return userBet;
}




void Poker::holdRedraw(int size) 
{
      //make function for hold/redraw card
        //loop i elements (hand size)
        //if user enters 1 - hold, i++ (go to next card), card value does not change
        //if user enters 0 - redraw poker.pokerHand[i]  = deck.getCard();

        int userSelect = -1;
        int i = 0;

        while(i < size){
        int count = i+1;

        char cardVal;

        if(pokerHand[i].num == 1)   //ace 1 
        {
            cardVal = 'A';
        }

        if(pokerHand[i].num == 11) //jack 11
        {
            cardVal = 'J';
        }

        if(pokerHand[i].num == 12) //queen 12
        {
            cardVal = 'Q';
        }

        if(pokerHand[i].num == 13) // king 13
        {
            cardVal = 'K';
        }

        //print to user 
        if(pokerHand[i].num > 1 && pokerHand[i].num < 11) {     //if card is number card 1 -11 print number 
        cout << "Card " << count << " [" << pokerHand[i].num << pokerHand[i].suit << "]" << endl;
        } 

        else if (pokerHand[i].num == 1 || pokerHand[i].num >= 11)   //else A1 J11 Q12 K13
        {
            cout << "Card " << count << " [" << cardVal << pokerHand[i].suit << "]" << endl;
        }

        //menu option to user
        cout << "0: Redraw" << endl << "1: Hold" << endl << "2: Sort Hand" << endl;

        while(!(cin >> userSelect) || (userSelect != 1 && userSelect != 0 && userSelect != 2)) 
        {
            cout << "invalid selection, enter option 0, 1 or 2" << endl;
            cin.clear();
            cin.ignore();
        }
        //hold
        if(userSelect == 1) 
        {
            cout << "Hold" << endl;
            i++;
        } 
        //shuffle
        else if(userSelect == 0) 
        {
            shuffleCard();  //shuffle the cards
            pokerHand[i] = getCard();
            i++;
        } 
        //sort
        else if(userSelect == 2) 
        {
            cout << "Sort Hand" << endl;

            sort(pokerHand, handSize);
            printHand(pokerHand, handSize);
        }
    }
}





//works
bool Poker::checkRoyalStraightFlush()
{
sort(pokerHand, handSize); //sort cards
int rfcheck = 1;

        //and if cards all the same suit
    for(int i = 0; i < handSize -1; i++) 
    {
        if(strcmp(pokerHand[i].suit, pokerHand[i+1].suit) == 0)
            {
                rfcheck++;   
            } else {
                rfcheck =0;
            } 
            }
            //if cards are A , J , Q , K , 10 
            if(rfcheck == 5 && pokerHand[0].num == 1 && pokerHand[1].num == 10 && pokerHand[2].num == 11 && pokerHand[3].num == 12 && pokerHand[4].num == 13)
                {
                return true; 
                } else {
                return false;
            }      
}
        
//works
bool Poker::checkStraighFlush()
{
//sort array 
sort(pokerHand, handSize); 

for(int i =0; i < handSize-1; i++) {
    if(!(pokerHand[i].num +1 == pokerHand[i+1].num && strcmp(pokerHand[i].suit, pokerHand[i+1].suit) == 0))
    {
        return false;
    }
}
    return true;
}

//works
bool Poker::checkFourCard()
{
    for (int i = 0; i < 2; ++i) {
            int count = 1;
            for (int j = i + 1; j < 5; ++j) {
                if (pokerHand[i].num == pokerHand[j].num) {
                    count++;
                }
            }
            if (count >= 4) {
                return true; // If four cards have the same number, it's four of a kind
            }
        }

return false; //No four of a kind found
}

//works
bool Poker::checkFullHouse() {
    // Sort array
    sort(pokerHand, handSize);

    //Check if the first three cards are of the same rank and the last two are of the same rank
    if (pokerHand[0].num == pokerHand[1].num && pokerHand[1].num == pokerHand[2].num && pokerHand[3].num == pokerHand[4].num) {
        return true;
    }

    //Check if the first two cards are of the same rank and the last three are of the same rank
    if (pokerHand[0].num == pokerHand[1].num && pokerHand[2].num == pokerHand[3].num && pokerHand[3].num == pokerHand[4].num) {
        return true;
    }

    return false;
}


//works
bool Poker::checkFlush()
{
int flushCheck = 1;

for(int i = 0; i < handSize-1; i++) {
    
    if(strcmp(pokerHand[i].suit,pokerHand[i+1].suit) == 0)  //if the expression is true = 0
    {
        flushCheck++;
        if(flushCheck == 5)    
        {
            return true;
        }

        } else {
            flushCheck = 1;
        }
}
return false;
}

//works 
bool Poker::checkStraight()
{
//sort array 
sort(pokerHand, handSize); 

    int count = 1;

    for (int i = 0; i < handSize - 1; i++) {
        if (pokerHand[i].num == 1 && pokerHand[handSize - 1].num == 13) {
            count++;
            if (count == 5) {
                return true; // Ace-low straight found
            }
        } else if (pokerHand[i].num + 1 == pokerHand[i + 1].num) {
            count++;
            if (count >= 5) {
                return true; // Straight found
            }
        } else if (pokerHand[i].num != pokerHand[i + 1].num) {
            count = 1; // Reset count if there's a gap
        }
    }
    return false;
}
//works
bool Poker::checkTriple()
{
for (int i = 0; i < 3; ++i) {
            int count = 1;
            for (int j = i + 1; j < 5; ++j) {
                if (pokerHand[i].num == pokerHand[j].num) {
                    count++;
                }
            }
            if (count >= 3) {
                return true; // If three cards have the same number, it's three of a kind
            }
        }
    return false; // No three of a kind found
}

//works
bool Poker::checkTwoPair() {
    int pairCount = 0;
    bool pairFound = false;

    for (int i = 0; i < handSize-1; i++) {
        for (int j = i + 1; j < handSize; j++) {
            if (pokerHand[i].num == pokerHand[j].num) {
                pairCount++;
                if (pairCount == 2) {
                    pairFound = true;
                    break;  // No need to continue checking if two pairs are found
                }
            }
        }
        if (pairFound) {
            break;  // No need to continue checking if two pairs are found
        }
    }

    return pairFound;
}

//works - might cause only 4 cards to print after win
bool Poker::checkJackorBetter() {
    int pairCount = 0;
    bool pairFound = false;

    for (int i = 0; i <= 5; i++) {
        for (int j = i + 1; j <= 5; j++) {
            if (pokerHand[i].num == pokerHand[j].num && pokerHand[i].num >= 11 || pokerHand[i].num == 1) {
                pairCount++;
                if (pairCount == 1) {
                    pairFound = true;
                    break;  // No need to continue checking if two pairs are found
                }
            }
        }
        if (pairFound) {
            break;  // No need to continue checking if two pairs are found
        }
    }

    return pairFound;
}


double Poker::checkWins(int size) //function to check the winning suits for poker, if win multiply userbet value and add to currentBal
{
    //return in multiplier
    if(checkRoyalStraightFlush()) 
    {
        cout << "Royal Straight Flush x 20000" << endl;
        return 20000;
    }

    if(checkStraighFlush()) 
    {
        cout << "Straight Flush x 10000" << endl;
        return 10000;
    }

    if(checkFourCard()) 
    {
        cout << "Four Card x 1000" << endl;
        return 1000;
    }

    if(checkFullHouse()) 
    {
        cout << "Full House x 100" << endl;
        return 100;
    }

    if(checkFlush()) 
    {
        cout << "Flush x 10" << endl;
        return 10;
    }

    if(checkStraight()) 
    {
        cout << "Straight x 6" << endl;
        return 6;
    }

    if(checkTriple()) 
    {
        cout << "Triple x 4" << endl;
        return 4;
    }

    if(checkTwoPair()) 
    {
        cout << "Two Pair x 2" << endl;
        return 2;
    }

    if(checkJackorBetter()) 
    {
        cout << "Jack or Better x 1" << endl;
        return 1;
    }
    //lose 
    return -1;
}


void Poker::printTable() 
{
    cout << "\n\n" << spade << club << heart << diamond << " Winning Hands " << spade << club << heart << diamond << endl << endl;
    cout << "[A" << spade << "]" << "[J" << spade << "]" << "[K" << spade << "]" << "[Q" << spade << "]" "[10" << spade << "]" << endl ;
    cout << "Royal Straight Flush - bet x 20000" << endl << endl;

    cout << "[5" << spade << "]" << "[6" << spade << "]" << "[7" << spade << "]" << "[8" << spade << "]" "[9" << spade << "]" << endl;
    cout << "Straight Flush - bet x 10000" << endl<< endl;

    cout << "[A" << spade << "]" << "[A" << diamond << "]" << "[A" << heart << "]" << "[A" << club << "]" << endl;
    cout << "Four Card - bet x 1000" << endl<< endl;

    cout << "[K" << spade << "]" << "[K" << diamond << "]" << "[K" << heart << "]" << "[J" << spade << "]" << "[J" << diamond << "]" << endl;
    cout << "Full House - bet x 100" << endl<< endl;

    cout << "[3" << heart << "]" << "[9" << heart << "]" << "[7" << heart << "]" << "[5" << heart << "]" "[K" << heart << "]" << endl;
    cout << "Flush - bet x 10" << endl<< endl;

    cout << "[5" << heart << "]" << "[6" << diamond << "]" << "[7" << spade << "]" << "[8" << club << "]" "[9" << heart << "]" << endl;
    cout << "Straight - bet x 6" << endl<< endl;

    cout << "[A" << spade << "]" << "[A" << diamond << "]" << "[A" << heart << "]" << endl;
    cout << "Triple - bet x 4" << endl<< endl;

    cout << "[A" << spade << "]" << "[A" << diamond << "]" << "[K" << heart << "]" << "[K" << diamond << "]" << endl;
    cout << "Two Pair - bet x 2" << endl<< endl;


    cout << spade << club << heart << diamond << " Winning Hands " << spade << club << heart << diamond << endl<< endl;
}
