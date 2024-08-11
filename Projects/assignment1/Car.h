//Assignment #1: Keepin' It Classy - Vadella
//Declaration of Car Class
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella
#include <string>

class Car 
{
	public:
		Car();
		Car(std::string n, int s, int c, int l);
		~Car();
	
		void printInfo(); //Tester for printing information.
		
		int simulateRace();
		
		//Setters 
		void setName(std::string n);
		void setSpeed(int s);
		void setControl(int c);
		void setLapNumber(int l); 

		//Getters 
		std::string getName();
		int getSpeed();
		int getControl();
		int getLapNumber();
	
	private:
		std::string name_;
		int speed_;
		int control_;
		int lapNumber_;
};