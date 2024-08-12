//Assignment #2 - Master-Card
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella

#include "deck.h"

Deck::Deck(int deckSize) //Constructor
{
	deck_ = new Card[deckSize];
	numCards_ = 0;
	maxCards_ = deckSize;
} 

Deck::~Deck() //Destructor
{
	if(deck_ == nullptr)
	{
		delete [] deck_;
		deck_ = nullptr;
	} 
} 

bool Deck::isEmpty() //Returns True/False (1/0) whether or not the Deck is empty
{
	return numCards_ == 0;
} 

void Deck::emptyDeck(Deck & newDeck)
{
	for (int i = 0; i < maxCards_; i++)
	{
		newDeck.deck_[i] = Card(0,0);
		newDeck.numCards_ = 0;
	}
}
	
int Deck::getNumCards() //Returns the number of cards remaining in the deck
{
	return numCards_;
} 

void Deck::displayCard(int i) //Displays the i'th card in the Deck
{
	if(i >= 0 && i < numCards_)
	{
		Card cardNum = deck_[i];
		std::cout << i << "th Card: " + cardNum.Card::print() << std::endl;	
	}
	else
	{
		std::cout << "Error: Index out of range. Try again." << std::endl;
	} 
} 
	
void Deck::printDeck() //Prints the contents of the Deck, calls the print() method on each Card
{
	for (int cardPlace = 0; cardPlace < numCards_; cardPlace++)
	{
		Card cardAtPosition = deck_[cardPlace];
		std::cout << cardAtPosition.getFace() + " of " + cardAtPosition.getSuit() << std::endl;
	} 
} 

bool Deck::mergeDecks(Deck & mergingDeck, bool shuffle)
{
	Card * originDeck = deck_; //Holding the original deck 
	int merge = mergingDeck.getNumCards() + numCards_; //Checking how many cards are in new deck
	deck_ = new Card[merge]; //Make space for cards in new deck
	int counter = 0; 
	
	for (int i = 0; i < numCards_; i++) //Copying "original" cards into new deck
	{
		deck_[i] = originDeck[i];
		counter++; 
	} 
	
	for (int i = 0; i < mergingDeck.getNumCards(); i++) //Adding the merge cards
	{
		deck_[counter] = mergingDeck.deck_[i];
		counter++; 
	} 
	
	numCards_ = counter;
	emptyDeck(mergingDeck);
	
	if(shuffle) //If shuffle bool is true, call shuffle function from base class
	{
		this->shuffle();
	}
	
	delete [] originDeck;
	return 0;
} 

//Phase 3
bool Deck::addCard(Card c)
{
	if(numCards_ <= maxCards_)
	{
		deck_[numCards_] = c;
		numCards_++;
		return 1; 
	} 
	
	return 0;
}
		
void Deck::shuffle()
{
	srand(time(0));
	for(int i = 0; i < 3; i++)
	{
		for(int deckShuff = 0; deckShuff < numCards_; deckShuff++)
		{
			int randomShuff = (rand() % numCards_ - 1) + 1;
			Card ShuffleCard = deck_[randomShuff];
			Card DeckCard = deck_[deckShuff];
			
			deck_[randomShuff] = DeckCard;
			deck_[deckShuff] = ShuffleCard;
		} 
	} 
} 

//Phase 4
Card Deck::dealCard()
{
	Card cardDealt;
	cardDealt = deck_[numCards_ - 1];
	numCards_--;
	//std::cout << cardDealt.print() << std::endl;
	return cardDealt;
} 

//Helper Function #1
void Deck::dealingHalf(Deck & Player1Deck_, Deck & Player2Deck_)
{
	int player2Starting = 0;
	
	for(int i = 0; i < numCards_/2; i++)
	{
		Player1Deck_.deck_[i] = deck_[i];
	} 
	
	for(int i = numCards_/2; i < numCards_; i++)
	{
		Player2Deck_.deck_[player2Starting++] = deck_[i];
	} 
} 

//Helper Function #2
Card Deck::getCard(int index)
{
	if(index < numCards_)
	{
		return deck_[index];
	} 
	
	return Card(0,0); //Returning an empty card if index is out of range
} 

//Helper Function #3
//Properly not neccessary
Card * Deck::getDeck()
{
	return deck_;
} 