//Assignment #1: Keepin' It Classy - Vadella
//Implementation of Car class
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella
#include <iostream>
#include "Car.h"

Car::Car() //Constructor #1
{
	
} 

Car::Car(std::string n, int s, int c, int l) //Constructor #2
{
	name_ = n;
	speed_ = s;
	control_ = c;
	lapNumber_ = l;
} 

Car::~Car() //Deconstructor
{
	
} 

//Setters
void Car::setName(std::string n)
{
	name_ = n;
} 

void Car::setSpeed(int s)
{
	speed_ = s;
} 

void Car::setControl(int c)
{
	control_ = c;
} 

void Car::setLapNumber(int l)
{
	lapNumber_ = l;
} 

//Getters
std::string Car::getName()
{
	return name_;
} 

int Car::getSpeed()
{
	return speed_;
} 

int Car::getControl()
{
	return control_;
} 

int Car::getLapNumber()
{
	return lapNumber_;
} 

//Tester that prints out each Car objects information.
void Car::printInfo()
{
	std::cout << name_ << " " << speed_ << " " << control_ << " " << lapNumber_ << std::endl;
} 

//Function to start/"simulate" the race. 
int Car::simulateRace()
{
	control_ = getControl();
	speed_ = getSpeed();
	int RandomNum = (rand() % 10) + 1;
	int RandomControl = 0;
	int lapsPerTurn = 0;
	
	if (control_ > 5)
	{
		RandomControl = control_/RandomNum;
		lapsPerTurn = RandomControl + speed_; 
		lapNumber_ = lapNumber_ + lapsPerTurn;
		//std::cout << control_ << " " << RandomNum << " " << RandomControl << " " << lapNumber_ << std::endl; (Tester line to check for issues)
		return lapNumber_;
	} 
	else 
	{
		lapNumber_ = lapNumber_ + speed_;
		//std::cout << control_ << " " << lapNumber_ << std::endl; (Tester line to check for issues)
		return lapNumber_;
	} 
} 