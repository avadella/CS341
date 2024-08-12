//Assignment #2: Master-Card
//Driver File
//Honor Pledge: I pledge that I have neither given nor received any help on this assignment.
//avadella
//WARNING: ***Phase 5 incomplete, does not operate as intended***

#include <iostream>
#include "card.h"
#include "standardDeck.h"

//Helper Function #1
std::string topCardCheck(Deck & deck)
{
	Card topCard;
	Card * deckGetter = deck.getDeck();
	topCard = deckGetter[0];
	//std::cout << topCard.getFace() << " getting top player card" << std::endl;
	return topCard.getFace();
}  

//Helper Function #2
int alternatingPlay(StandardDeck & Player1Deck_, StandardDeck & Player2Deck_, StandardDeck & battleground_)
{
	bool player1War = false;
	bool player2War = false;
	
	int WhoWins = 0;
	
	//will get info currently stored in the deck, which right now is 0 b/c no values exists in deck so far
	Player1Deck_.getDeck(); 
	Player2Deck_.getDeck(); 
	
	//Troubleshooting: Checking how many cards are in each deck
	std::cout << "Player 1 Num Cards: " << Player1Deck_.getNumCards() << std::endl;
	std::cout << "Player 2 Num Cards: " << Player2Deck_.getNumCards() << std::endl;
	std::cout << "Battleground Num Cards: " << battleground_.getNumCards() << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	
	do
	{
		//Player 1 plays a card
		if(topCardCheck(battleground_) == topCardCheck(Player1Deck_))
		{
			player1War = true;
			//std::cout << "Player 1 won the war!" << std::endl;
			
			Player1Deck_.mergeDecks(battleground_, 0);
			//Player1Deck_.printDeck();
			Player1Deck_.shuffle();
			std::cout << "Player 1 Num Cards: " << Player1Deck_.getNumCards() << std::endl;
			std::cout << "Player 2 Num Cards: " << Player2Deck_.getNumCards() << std::endl;
			std::cout << "Battleground Num Cards: " << battleground_.getNumCards() << std::endl;
			std::cout << " " << std::endl;
		} 
		else 
		{
			battleground_.addCard(Player1Deck_.dealCard());
		} 
		
		//If Player 1 War is true
		if(player1War == true)
		{
			battleground_.addCard(Player1Deck_.dealCard());
			player1War = false;
		} 
		else
		{
			//nothing happens.
		}
	
		//Player 2 plays a card
		if(topCardCheck(battleground_) == topCardCheck(Player2Deck_))
		{
			player2War = true;
			//std::cout << "Player 2 won the war!" << std::endl;
			
			Player2Deck_.mergeDecks(battleground_, 0);
			//Player2Deck_.printDeck();
			Player2Deck_.shuffle();
			std::cout << "Player 1 Num Cards: " << Player1Deck_.getNumCards() << std::endl;
			std::cout << "Player 2 Num Cards: " << Player2Deck_.getNumCards() << std::endl;
			std::cout << "Battleground Num Cards: " << battleground_.getNumCards() << std::endl;
			std::cout << " " << std::endl;
		} 
		else 
		{
			battleground_.addCard(Player2Deck_.dealCard());
		}

		//If Player 2 War is false	
		if(player2War == false)
		{
			battleground_.addCard(Player2Deck_.dealCard());
			player2War = false;
		} 
		else
		{
			//nothing happens.
		} 	
		} while(Player1Deck_.getNumCards() > 0 && Player2Deck_.getNumCards() > 0);
	
	if(Player1Deck_.getNumCards() > 0)
	{
		WhoWins = 1;
	}
	else if (Player2Deck_.getNumCards() > 0)
	{
		WhoWins = 2;
	}
	
	std::cout << "Player 1 Num Cards: " << Player1Deck_.getNumCards() << std::endl;
	std::cout << "Player 2 Num Cards: " << Player2Deck_.getNumCards() << std::endl;
	std::cout << "Battleground Num Cards: " << battleground_.getNumCards() << std::endl;
	std::cout << " " << std::endl;
	
	return 0;
} 

int main()
{
	Deck * ptrDeck = new StandardDeck();
	Deck * ptrPlayer1 = new StandardDeck();
	Deck * ptrPlayer2 = new StandardDeck();
	Deck * ptrBattleground = new StandardDeck();
		
	//Troubleshooting: Testing StandardDeck 
	//ptrDeck->initializeDeck(); 
	//ptrDeck->printDeck();
	
	//std::cout << " " << std::endl;
	
	//Troubleshooting: Testing Shuffle function w/ a StandardDeck
	//ptrDeck->shuffle(); 
	//ptrDeck->printDeck();
	
	//std::cout << " " << std::endl;
	
	/*int player1Wins = 0;
	int player2Wins = 0;
	
	int averagePlayer1 = 0;
	int averagePlayer2 = 0;
	
    for (int i = 0; i < 50; i++)
    {
        ptrDeck->shuffle();
        ptrDeck->dealingHalf(*ptrPlayer1, *ptrPlayer2);
		
        int figuringWinner = alternatingPlay(*ptrPlayer1, *ptrPlayer2, *ptrBattleground);
		
        if (figuringWinner == 1)
        {
            player1Wins++;
        }
        else if (figuringWinner == 2)
        {
            player2Wins++;
        }
        else
        {
           //nothing happens.
        }
		
		averagePlayer1 = averagePlayer1 + ptrPlayer1->getNumCards();
		averagePlayer2 = averagePlayer2 + ptrPlayer2->getNumCards();

		ptrPlayer1->emptyDeck(*ptrPlayer1);
		ptrPlayer2->emptyDeck(*ptrPlayer2);
		ptrBattleground->emptyDeck(*ptrBattleground);
		
    }

	//Determining Game Winner
	if(player1Wins > player2Wins)
	{
		std::cout << "Player 1 was the champion with " << player1Wins << " victories versus Player 2." << std::endl;
	} 
	else if(player2Wins > player1Wins)
	{
		std::cout << "Player 2 was the champion with " << player2Wins << " victories versus Player 1." << std::endl;
	}
	else 
	{
		//nothing happens. 
	} 
	
	std::cout << "Player 1 average score: " << averagePlayer1/50 << std::endl;
	std::cout << "Player 2 average score: " << averagePlayer2/50 << std::endl;
	std::cout << " " << std::endl;*/
	
	delete ptrDeck;
	delete ptrPlayer1;
	delete ptrPlayer2;
	delete ptrBattleground;
	
	return 0;
} 