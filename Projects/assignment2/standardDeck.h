//Assignment #2 - Master-Card
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include <iostream>
#include "card.h"
#include "deck.h"

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck : public Deck
{
	public:
		StandardDeck(); /// Default constructor. 
		~StandardDeck(); /// Default destructor.
		void initializeDeck();
};
#endif