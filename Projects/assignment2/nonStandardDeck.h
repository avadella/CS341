//Assignment #2 - Master-Card
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella

#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H

#include <iostream>
#include "card.h"
#include "deck.h"

class NonStandardDeck : public Deck
{
	public:
		NonStandardDeck(); /// Default constructor. 
		~NonStandardDeck(); /// Default destructor.
		void initializeDeck();
};
#endif