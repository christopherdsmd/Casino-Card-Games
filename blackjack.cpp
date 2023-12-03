#include<iostream>
#include<iomanip>
#include<cstring>
#include"blackjack.h"   //include black jack header file
using namespace std;

BlackJack::BlackJack() 
{
    BJmoney = 0.00;   //starting money
    BJbet = 0.00;         //current user bet
    MAXCARDS = 10;

    playerbj = false;       
    dealerbj = false;

    insurance = false;    //insurance from check insurance
}

double BlackJack::getBJMoney()
{
  cout << "Enter amount of money to play" << endl;
    while(!(cin >> BJmoney))  //error check
    {
        cin.clear();
        cin.ignore();
    }
    return BJmoney;
}

void BlackJack::setBJMoney(double val)
{
    BJmoney = val;
}

double BlackJack::getBJbet()
{
   cout << "How much money would you like to bet" << endl;

    while(!(cin >> BJbet) || BJbet > BJmoney)    //error check, bet must be less than or equal to staring money
    {
        cout << "Invalid bet amount - must be less than or equal to credit value"  << endl;
        cin.clear();
        cin.ignore();
    }
    return BJbet;
}

void BlackJack::checkInsurance() 
{
    char userChoice = 'x';

    if(BJdealerHand[0].num == 1)    //if the open hand is ace
    {
        cout << "Would you like to buy Insurance: " << endl << "Cost - $" << BJbet/2 << endl;
        cout << "Y: Purchase" << endl;
        cout << "N: No" << endl; 

        while(!(cin >> userChoice)) 
        {
         cin.clear();
         cin.ignore();
        }

        if(userChoice == 'y' ||userChoice == 'Y')
        {
            cout << "insurance purchased." << endl; 
            BJbet = BJbet/2;                //decrease the bet
            cout << "$" << fixed << setprecision(2) << BJbet << " - Current Bet" << endl << endl;    //print remaning credit 
            insurance = true;       //activate insurance 
        }        
    }

    setBJbet(BJbet);
}

//add card values for dealer - draw new card if first 2 cards are < 16 - if counter = 21 return true - blackjack
bool BlackJack::CheckdealerBJ() 
{
    //check first 2 cards - dealer always given 2 cards
    int initialCounterAce1 = 0;   // Ace = 1 
    int initialCounterAce11 = 0;  // Ace = 11

    //used to check if counter < 16 and dealer needs to draw another card - same logic
    int currentCounterAce1 = 0;   // Ace = 1 
    int currentCounterAce11 = 0;  // Ace = 11

    // Calculate the initial total value of the first two cards
    for (int j = 0; j < 2; ++j) {
        if (BJdealerHand[j].num == 1) {
                initialCounterAce1 += 1;        //ace value = 1
                initialCounterAce11 += 11;      //ace value = 11
            } else if (BJdealerHand[j].num >= 2 && BJdealerHand[j].num <= 10) {
                initialCounterAce1 += BJdealerHand[j].num;          //add card values for cards 2 -10
                initialCounterAce11 += BJdealerHand[j].num;
            } else if (BJdealerHand[j].num >= 11) {
                initialCounterAce1 += 10;   //face cards
                initialCounterAce11 += 10;
            }
    }

    currentCounterAce1 = initialCounterAce1;        //set counter to contain values of first 2 cards
    currentCounterAce11 = initialCounterAce11;

    // Draw cards for the dealer if the total is less than 16
    int cardCount = 2;  //starting counter at 2 - array element 3 (after first 2 initial cards)

    while((currentCounterAce1 < 16 && currentCounterAce11 != 21) && cardCount < MAXCARDS) {
        BJdealerHand[cardCount] = getCard();    //if dealer counter < 16 next element in array is given a new card value 

            //same logic as before for adding cards
        // Update counters based on the newly drawn card
        if (BJdealerHand[cardCount].num == 1) {
            // Check if treating the Ace as 11 would not exceed 21
                currentCounterAce1 += 1;
                currentCounterAce11 += 11;
        } else if (BJdealerHand[cardCount].num>= 2 && BJdealerHand[cardCount].num<= 10) {
            currentCounterAce1 +=BJdealerHand[cardCount].num;
            currentCounterAce11 += BJdealerHand[cardCount].num;
        } else if (BJdealerHand[cardCount].num >= 11 && BJdealerHand[cardCount].num < 15) {
            currentCounterAce1 += 10;
            currentCounterAce11 += 10;
        }
        //cout << "Dealer draws a card" << endl;
        ++cardCount;    //increase card count for loop
    }

    // Determine the maximum value for the counter thats also less than 21
    int maxvalue = (currentCounterAce11 < 21) ? max(currentCounterAce1, currentCounterAce11) : currentCounterAce1;
    setDealerCounter(maxvalue); //set the max value under 21 to dealer counter
    //cout << "dealer max value" << maxvalue << endl;

    // Check for dealer blackjack
    if (currentCounterAce1 == 21 || currentCounterAce11 == 21) {
        return true;    
    }

    // No dealer blackjack case 
    return false; 
}


//add card values for player - if counter = 21 return true - blackjack
bool BlackJack::CheckplayerBJ() 
{   //check if player has blackjack
    if (playerCounter == 21 ) {
        return true; // Player blackjack
    }

    // No player blackjack case 
    return false; 
}

void BlackJack::checkWinner()   //rewards - return bet value multiplier 
{
    //both player and dealer blackjack
    if (dealerbj && playerbj) {
        if (insurance)  {   
        //if insurance was purchased - insurance == true 
        //bet was halfed in checkinsurance()
        cout << "Insurance returned - $" << BJbet << endl;  //return bet that was subtracted in half from insurance
        BJmoney += BJbet;    //update starting money
        setBJbet(BJbet);
        setBJMoney(BJmoney);  //update class starting money
        } else {
        cout << "Push - Dealer and Player have Black Jack" << endl; 
        cout << "You Lost - $" << BJbet << endl; 
        BJmoney -= BJbet;   //subtract the bet
        setBJbet(BJbet);
        setBJMoney(BJmoney);  //update class starting money
        return; //lost subtract bet value from gamemoney pool
    }
    }

   if(dealerbj && !playerbj) //if dealer has black jack and player doesnt
        {
            cout << "Dealer has Black Jack - You Lose" << endl; 
                if (insurance)  {   
                     //if insurance was purchased - insurance == true 
                    //bet was halfed in checkinsurance()
                    cout << "Insurance returned - $" << BJbet << endl;  //return bet that was subtracted in half from insurance
                    BJmoney += BJbet;    //update starting money
                    setBJbet(BJbet);
                    setBJMoney(BJmoney);  //update class starting money
                    } else {
                    cout << "You Lost - $" << BJbet << endl; 
                    BJmoney -= BJbet;   //subtract the bet
                    setBJbet(BJbet);
                    setBJMoney(BJmoney);  //update class starting money
                    }
            return;
        }
        
        //if player has blackjack dealer does not
    if (playerbj && !dealerbj) {  
            cout << "You have Black Jack " << endl;
            BJbet *= 1.5;
            cout << "You Won - $" << BJbet << endl;

            //update winning bet value 
            BJmoney += BJbet;
            setBJbet(BJbet);
            setBJMoney(BJmoney);  //update class starting money
            return;
        } 

    if(dealerCounter > 21 && playerCounter > 21) 
    {
           cout << "Push - Player and Dealer went over 21 " << endl;
            cout << "Bet returned - $" << BJbet << endl; 
            //update winning bet value 
            setBJbet(BJbet);
            setBJMoney(BJmoney);  //update class starting money
            return;
    }

    if (dealerCounter > 21) {   
        cout << "Dealer Bust - went over 21 \n You Win" << endl;
        BJbet = BJbet * 2;
        //you won 
        cout << "You Won - $" << BJbet << endl;
    
            //update winning bet value 
            BJmoney += BJbet;
            setBJbet(BJbet);
            setBJMoney(BJmoney);  //update class starting money
    
        return;
    }

    // No dealer blackjack or bust case
    if (playerCounter > 21) {
            cout << "Bust - You went over 21 \n You Lose" << endl;
            cout << "You Lost - $" << BJbet << endl; 

                            if (insurance)  {   
                     //if insurance was purchased - insurance == true 
                    //bet was halfed in checkinsurance()
                    cout << "Insurance returned - $" << BJbet << endl;  //return bet that was subtracted in half from insurance
                    BJmoney += BJbet;    //update starting money
                    setBJbet(BJbet);
                    setBJMoney(BJmoney);  //update class starting money
                    } else {


            BJmoney -= BJbet;   //subtract the bet
            setBJbet(BJbet);
            setBJMoney(BJmoney);  //update class starting money
            return;
                }
        } 
     
        if (playerCounter == dealerCounter) {
            cout << "Push - You tied with the dealer " << endl;
            cout << "Bet returned - $" << BJbet << endl; 
            //update winning bet value 
            setBJbet(BJbet);
            setBJMoney(BJmoney);  //update class starting money
            return;
        }

        //if player has > dealer and is < 21
        if (playerCounter > dealerCounter && playerCounter < 21) {
            cout << "You Won - $" << BJbet << endl;

            //update winning bet value 
            BJmoney += BJbet;
            setBJbet(BJbet);
            setBJMoney(BJmoney);  //update class starting money
            return;
        } 

        if(dealerCounter > playerCounter && dealerCounter < 21) {
            cout << "Dealer Wins - You Lose" << endl;
            cout << "You Lost - $" << BJbet << endl; 
                     if (insurance)  {   
                     //if insurance was purchased - insurance == true 
                    //bet was halfed in checkinsurance()
                    cout << "Insurance returned - $" << BJbet << endl;  //return bet that was subtracted in half from insurance
                    BJmoney += BJbet;    //update starting money
                    setBJMoney(BJmoney);  //update class starting money
                    } else {
            BJmoney -= BJbet;   //subtract the bet
            setBJbet(BJbet);
            setBJMoney(BJmoney);  //update class starting money
            return;
        }
    }
}


//same logic for finding player counter value, ask player if they want to 'hit' - draws new card into deck
void BlackJack::holdorhit()
{
    int counter1 = 0; // Ace = 1
    int counter2 = 0; // Ace = 11
    int Cardcount = 2;

    int i = 0;

//works
    while (BJplayerHand[i].num != 0 && counter1 < 21)
    {
        // Ace can be used as 1 or 11
        if (BJplayerHand[i].num == 1)
        {
            counter1 += 1;
            counter2 += 11;
        }
        // Range for number cards
        else if (BJplayerHand[i].num > 1 && BJplayerHand[i].num < 11)
        {
            counter1 += BJplayerHand[i].num;
            counter2 += BJplayerHand[i].num;
        }
        // Face cards = 10
        else if (BJplayerHand[i].num >= 11)
        {
            counter1 += 10;
            counter2 += 10;
        }

        i++;
    }

    int userpick = -1;
        while (userpick != 2 && (counter1 < 21 || counter2 < 21))
        {
        cout << "Would you like to Hit or Hold" << endl;
        cout << "1: Hit" << endl;
        cout << "2: Hold" << endl;

        while (!(cin >> userpick))
        {
            cin.clear();
            cin.ignore();
        }

        switch (userpick)
        {
        case 1: // Hit  - draw new card add value to counter
        {
            cout << "Hit" << endl;
            // Get a new card and update the player's hand
            shuffleCard();
            BJplayerHand[Cardcount] = getCard(); // Update correct index
            
            // Update counters based on the new card
            if (BJplayerHand[Cardcount].num == 1) // Use correct index
            {
                counter1 += 1;
                counter2 += 11;
            }
            else if (BJplayerHand[Cardcount].num > 1 && BJplayerHand[Cardcount].num < 11) // Use correct index
            {
                counter1 += BJplayerHand[Cardcount].num;
                counter2 += BJplayerHand[Cardcount].num;
            }
            else if (BJplayerHand[Cardcount].num >= 11) // Use correct index
            {
                counter1 += 10;
                counter2 += 10;
            }

            // Find the max value under 21
            int maxvalue = (counter2 <= 21) ? max(counter1, counter2) : counter1;
            setPlayerCounter(maxvalue); // Set the max value under 21 to player counter
            //cout << "player max value - hit " << maxvalue << endl;

            cout << "Your Hand" << endl;
            printHand(BJplayerHand, Cardcount+1); // Print deck
            Cardcount++; // Increment Cardcount only once
            break;
        }

        case 2: // Hold - do nothing
            cout << "Hold" << endl;
            int maxvalue = (counter2 <= 21) ? max(counter1, counter2) : counter1;
            setPlayerCounter(maxvalue); // Set the max value under 21 to player counter

            //cout << "player max value - hold " << maxvalue << endl;
            break;
        }
        dealerbj = CheckdealerBJ();
        playerbj = CheckplayerBJ();
    }

}

void BlackJack::setDealerCounter(int x)     //setter funcion for dealer counter
{
     dealerCounter = x;
}

void BlackJack::setPlayerCounter(int x) //setter funcion for player counter
{
    playerCounter = x;
}

void BlackJack::cleardecks() {  //clean decks and counters - reset for each round 
    char x = ' ';
    char *blank = &x;
    
    // Reset player's hand
    for (int i = 0; i < MAXCARDS; ++i) {
        BJplayerHand[i].num = 0;
        strcpy(BJplayerHand[i].suit, blank);
    }

    // Reset dealer's hand
    for (int i = 0; i < MAXCARDS; ++i) {
        BJdealerHand[i].num = 0;
        strcpy(BJdealerHand[i].suit, blank);
    }

    //reset counter values to 0
    setPlayerCounter(0);
    setDealerCounter(0);
}

double BlackJack::returnMoney() 
{
    return BJmoney;
}

void BlackJack::setBJbet(double x) 
{
    BJbet = x;
}