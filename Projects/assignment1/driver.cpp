//Assignment #1: Keepin' It Classy - Vadella
//Driver file
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella
#include <iostream>
#include "Car.h"
#include <fstream>

int main ()
{
	//Variable Declarations
	std::string name;
	int speed;
	int control;
	int lapNumber = 0;
	int i = 0;
	int positionInArray = 0;
	
	srand(time(0));
	
	Car drivers[33];
	Car objectCar;

	//Open and read info from file, create Car objects, then close file. 
	std::ifstream driverInfo ("indy500.txt");
	if (driverInfo.is_open())
	{
		while(!driverInfo.eof())
		{
			driverInfo >> name;
			driverInfo >> speed;
			driverInfo >> control;
			
			//Tester to see if information from file is being read.
			//std::cout << name << " " << speed << " " << control << std::endl;
			
			objectCar = Car(name, speed, control, lapNumber);
			drivers[positionInArray++] = objectCar;
		} 
		
	driverInfo.close();
	
	} 
	
	//Tester to see if array information is going through the Car Class.
	/*for (int i = 0; i < 33; i++)
	{
		drivers[i].printInfo();
	}*/ 
	
	std::cout << " " << std::endl;
	std::cout << "***Welcome to the 2023 Indianapolis 500 Race!***" << std::endl;
	std::cout << " " << std::endl;
	
	//Do while using the simulateRace function. 
	do
	{
		if (i < 33)
		{
			lapNumber = drivers[i].simulateRace(); 
			drivers[i].setLapNumber(lapNumber);
		} 
		else 
		{
			std::cout << "***--> Racing... " << std::endl;
			i = 0;
		} 
	} while (drivers[i++].getLapNumber() <= 200);
	
	i--;
	
	std::cout << " " << std::endl;
	std::cout << "***" << drivers[i].getName() << " has won the 2023 Indianapolis 500!***" << std::endl;
	drivers[i].setLapNumber(200); //In case lapNumber went over 200, sets it back to 200 for final results.
	
	std::cout << " " << std::endl;
	std::cout << "Driver Name: Lap Number" << std::endl;
	std::cout << "***********************" << std::endl;
	
	for (i = 0; i < 33; i++)
	{
		std::cout << drivers[i].getName() << ": " << drivers[i].getLapNumber() << std::endl; 
	}
	
	std::cout << " " << std::endl;
	std::cout << "Thank you for using my race simulation program - goodbye!" << std::endl;
 
	return 0; 
} 