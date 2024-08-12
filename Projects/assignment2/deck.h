//Assignment #2 - Master-Card
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "card.h"

class Deck
{
	public:
		Deck(int deckSize); /// Default constructor. 
		~Deck(); /// Default destructor.

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		virtual bool isEmpty();

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();	
		
		//Phase 3
		bool addCard(Card c);
		void shuffle();
		bool mergeDecks(Deck & mergingDeck, bool shuffle);
		virtual void initializeDeck() = 0;
		
		//Phase 4
		Card dealCard();
		void dealingHalf(Deck & Player1Deck_, Deck & Player2Deck_);
		void emptyDeck(Deck & newDeck);
		Card getCard(int index);
		Card * getDeck();
		
	protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// Stores the number of Cards currently in the deck.
		int maxCards_; //How big is the deck?
};
#endif