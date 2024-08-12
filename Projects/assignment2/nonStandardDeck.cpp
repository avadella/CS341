//Assignment #2 - Master-Card
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella

#include "nonStandardDeck.h"
#define DECK_SIZE 104

NonStandardDeck::NonStandardDeck() : Deck(DECK_SIZE) //Constructor
{
	
} 

NonStandardDeck::~NonStandardDeck() //Destructor
{
	
} 
		
void NonStandardDeck::initializeDeck()
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