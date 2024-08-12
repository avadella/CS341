//Assignment #2 - Master-Card
//Implementation of Card class
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella

#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	
Card::Card() //Constructor #1
{
	
}

Card::Card(int s, int f) //Constructor #2
{
	suitVal_ = s;
	faceVal_ = f;	
} 
	
Card::~Card() //Destructor
{
	
} 

//Getters	
std::string Card::getSuit()
{
	return Card::SUIT[suitVal_];
}

std::string Card::getFace()
{
	return Card::FACE[faceVal_];
} 

std::string Card::print()
{
	return getFace() + " of " + getSuit();
}

void Card::initialize(int s, int f)
{
	suitVal_ = suitVal_;
	faceVal_ = faceVal_;
}				   