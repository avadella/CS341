//Assignment #2 - Master-Card
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella

#include "standardDeck.h"
#define DECK_SIZE 52

StandardDeck::StandardDeck() : Deck(DECK_SIZE) //Constructor
{
	
} 

StandardDeck::~StandardDeck() //Destructor
{
	
} 
		
void StandardDeck::initializeDeck()
{
	for(int suitAmount = 1; suitAmount < 5; suitAmount++)
	{
		for(int faceAmount = 1; faceAmount < 14; faceAmount++)
		{
			Card newCard(suitAmount, faceAmount);
			deck_[numCards_] = newCard;
			numCards_++; 
		} 
	} 
}