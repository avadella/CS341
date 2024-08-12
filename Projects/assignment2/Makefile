Cards.exe: driver.o deck.o standardDeck.o card.o 
	g++ driver.cpp deck.o standardDeck.o card.o -o Cards.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
deck.o: deck.cpp
	g++ -c deck.cpp -o deck.o
	
standardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o standardDeck.o

card.o: card.cpp
	g++ -c card.cpp -o card.o
		
clean:
	rm *.o Cards.exe