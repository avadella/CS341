//Dictionary Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "dictionary.h"

Dictionary::Dictionary() : lookupTable_(new int [DICTIONARY_SIZE]) //Constructor
{
	for (int i = 0; i < DICTIONARY_SIZE; i++)
	{
		Set numbers(1);
		char holder[1];

		holder[0] = i;
		numbers.initialize(holder, 1);
		//numbers.getData().print();
		lookupTable_[i] = numbers.getCardinality();
	}
}

Dictionary::Dictionary (const Dictionary & dict) : lookupTable_(nullptr) //Copy Constructor, Using Initalization List
{
	if(dict.lookupTable_)
	{
		lookupTable_ = new int(DICTIONARY_SIZE);
		for(int i = 0; i < DICTIONARY_SIZE; i++)
		{
			lookupTable_[i] = dict.lookupTable_[i];
		}
	}
}

Dictionary::~Dictionary() //Destructor
{
	if (lookupTable_ != nullptr)
	{
		delete [] lookupTable_;
	}
}

void Dictionary::initialize(char * word, int size)
{
	data_.initialize(word, size);
}

int Dictionary::rank_range(int start, int end, int bit)
{
	int rank = 0;
	int bitType;

	for(int i = start; i < end; i++)
	{
		bitType = data_.get(i);
		if(bitType == bit)
		{
			rank++;
		}
		else
		{
			//nothing happens.
		}
	}
	return rank;
}

int Dictionary::rank(int end, int bit)
{
	int rank = 0;
	int bitType = 0;
	end = (end/BIT_IN_BYTE) + 1;

	for(int i = 0; i < end; i++)
	{
		bitType = data_.get8(i * 8);
		//std::cout << data_.get8(i * 8)<< "	" << bitType << "	" << lookupTable_[bitType] << std::endl;
		
		if(bit == 1)
		{
			rank = rank + match(bitType);
		}
		else
		{
			rank = rank + abs((match(bitType)- BIT_IN_BYTE));
		}
	}
	
	return rank;
}

int Dictionary::select_range(int start, int end, int k, int bit)
{
	int positionOf = 0;
	int counter = 0;
	int bitType;

	for(int i = start; i < end; i++)
	{
		if(positionOf < k)
		{
			bitType = data_.get(i);
			if(bitType == bit)
			{
				counter++;
				positionOf++;
			}
			else
			{
				counter++;
				//nothing happens.
			}
		}
		else
		{
			return counter;
		}
	}
}

int Dictionary::match(int match) //Helper Function
{
	return lookupTable_[match];
}

int Dictionary::select(int k, int bit)
{
	int positionOf = 0;
	int counter = 0;
	int bitType;
	int bitPosHelp = 0;

	for(int i = 0; i < data_.length()/BIT_IN_BYTE; i++)
	{
		bitType = data_.get8(i * 8);
		if(counter + match(bitType) < k)
		{
			//not enough 1's in byte, then add 8 and move onto next byte
			counter = counter + match(bitType);
			positionOf = positionOf + BIT_IN_BYTE;
		}
		else if(counter == k)
		{
			return positionOf;
		}
		else
		{
			bitType = data_.get(((i - 1) * 8) + bitPosHelp);
			bitPosHelp++;
			if (bitType == bit)
			{
				counter++;
				positionOf++;
			}
			else
			{
				positionOf++;
			}
		}
	}
}

void Dictionary::printLookupTable(std::ostream & output)
{
	std::cout << "Printing Lookup Table..." << std::endl;
	for (int i = 0; i < DICTIONARY_SIZE; i++)
	{
		output << "lookupTable_[" << i << "]" << "\t" << lookupTable_[i] << std::endl;
	}
}