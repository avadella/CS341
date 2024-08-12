//Assignment #3: P'Bit'ty
//Driver File
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "bitarray.h"
#include "dictionary.h"
#include <fstream>

int main()
{
	//Phase 1
	//std::cout << " " << std::endl;
	//BitArray newBit(4);
	//std::cout << "Number of Bits: " << newBit.length() << std::endl;
	//std::cout << newBit.get(5) << std::endl;

	//Phase 2 
	//newBit.initialize("test", 4);
	//newBit.print();
	
	//std::cout << newBit.get8(30) << std::endl;
	
	/*std::cout << "0th Bit Set: " << newBit.get(0) << std::endl;
	std::cout << "10th Bit Set: " << newBit.get(10) << std::endl;
	
	std::cout << " " << std::endl;
	
	std::cout << "Setting 0th position to 1..." << std::endl;
	newBit.set(0, 1);
	newBit.print();
	
	std::cout << "Setting 10th position to 0..." << std::endl;
	newBit.set(10, 0);
	newBit.print();
	
	std::cout << " " << std::endl;
	
	std::cout << "Complement: " << std::endl;
	newBit.complement();
	newBit.print();
	
	std::cout << "Flip: " << std::endl;
	newBit.flip(0);
	newBit.print();
	
	std::cout << " " << std::endl;
	
	std::cout << "Clear BitArray: " << std::endl;
	newBit.clear();
	newBit.print();*/
	
	//Phase 3
	//std::cout << " " << std::endl;
	
	//Initialize Set A and Set B
	/*Set A(4);
	A.initialize("Anna", 4);
	Set A2(4);
	A2.initialize("Anna", 4);
	Set B(4);
	B.initialize("Noah", 4);
	
	(A.getData()).print();
	(B.getData()).print();
	
	std::cout << " " << std::endl;*/
	
	//std::cout << A.getData().length() << std::endl; //Checking length of one set
	
	//Get Cardinality of Set A and Set B
	/*std::cout << "Cardinality of A: " << A.getCardinality() << std::endl;
	std::cout << "Cardinality of B: " << B.getCardinality() << std::endl;*/
	
	//std::cout << " " << std::endl;
	
	//Get Union between Set A and Set B
	/*std::cout << "Set Union (A U B): " << std::endl;
	A.setUnion(B);
	(A.getData()).print();
	
	std::cout << " " << std::endl;
	
	//Get Intersection between Set A and Set B
	std::cout << "Set Intersection (A X B): " << std::endl;
	A2.setIntersection(B);
	(A2.getData()).print();*/
	
	/*Phase 4
	Dictionary newDict;
	newDict.initialize("test", 4);
	
	//Rank and Rank Range
	std::cout << "Rank: " << newDict.rank(31, 1) << std::endl;
	std::cout << "Rank Range (15-31): " << newDict.rank_range(15, 31, 1) << std::endl;
	
	//Select and Select Range
	std::cout << "Select (5,1): " << newDict.select(5, 1) << std::endl;
	std::cout << "Select Range (0, 15, 2, 1): " << newDict.select_range(0, 15, 2, 1) << std::endl;*/
	
	std::cout << " " << std::endl;
	
	//Phase 5
	std::ofstream file("table.txt");

	Dictionary newDictionary;
	newDictionary.initialize("test", 4);
	
	std::cout << "Rank: " << newDictionary.rank(31, 1) << std::endl;
	std::cout << "Rank Range (15 - 31): " << newDictionary.rank_range(15, 31) << std::endl;
	std::cout << "Select(5,1):  " << newDictionary.select(5, 1) << std::endl;
	std::cout << "Select Range(0, 15, 2, 1): " << newDictionary.select_range(0, 15, 2, 1) << std::endl;

	newDictionary.printLookupTable(file);
	file.close();
	
	return 0;
} 

//Notes for Bit Array Assignment:
//A byte is 8 bits!
//256 binary combinations of 8 bits!
//Vectors are the same as a dynamic array! (just a container, can grow and elements can be any type)
//Set refers to setting the bit value at the given index to 1, so unset means its 0
//Lookup table is used to map input values to output values
//Bitwise exclusive or: either or but not both
//One's complement: flips the bits of something
//Dictionary Class:
	//Rank tells you how many 1s there are in the range [i, j)
	//Select finds the bit position of the kth 1 in the range [i, j)
//A bit vector is basically just an array of bits; a vector in which each element is a bit (0 or 1)
//A bit array is an array that compactly stores bits; an array filled with bit vectors, basically
//It is not possible to read and write to the bits in a bit vector individually at the machine code level,
	//so to read an individual bit from a bit bector, need to read the byte it's contained in
//Const keyword specifies that a variable's value is constant and the compiler prevents modification to it
//Initialization lists:
	//Allow someone to choose which constructor is called and what arguments that constructor receives
	//If you have a reference or a const field, or if one of the classes used does not have a default
		//constructor, must use an initialization list!
	//Use an initialization list for:
		//initialization of non-static const data members (no memory allocated separately for const!)
		//When constructor's parameter name is same as data member
		//For initialization of base class members
		//For initialization of member objects which do not have a default constructor
		//For initialization of reference members
		//For performance reasons
//Inline keywords tells compiler to substitute code within the function definition for every instance of 
	//a function call; using inline can make program faster b/c they eliminate the overhead of function calls 
	//When to use inline:
		//Very small functions are good for inline b/c faster code and smaller executables!
		//If a function is small and called very often
//"Mask" is a bit pattern used to isolate or manipulate specific bits in a binary value
//Bitwise shift operators:
	//Right-shift operator, >>
		//Takes two nums, right shifts the bits of the first operand and the second operand decides
			//the number of places to shift
				//Ex: a>>b is equivalent to diving a with 2^b
	//Left-shift operator, <<
		//Takes two nums, left shifts the bits of the first operand and the second operand decides	
			//the number of places to shift
//Unsigned char is an interger in the interval of 0 to 255
	//Signed will be an 8-bit two's complement num ranged from -128 to 127 (can contain negatives!)