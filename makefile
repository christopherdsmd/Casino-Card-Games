all: card

card: cardMain.o card.o poker.o blackjack.o
	g++ cardMain.o card.o -o card

cardMain.o: cardMain.cpp card.h poker.h
	g++ -c cardMain.cpp
 
blackjack.o: blackjack.cpp card.h blackjack.h
	g++ -c blackjack.cpp

poker.o: poker.cpp card.h poker.h
	g++ -c poker.cpp

card.o: card.cpp card.h poker.h
	g++ -c card.cpp
	
clean:
	rm -rf *.o card