/*
	@NAME:		John Russell, 2798357
	@DATE:		14 February 2017
	@FILE:		main.cpp
	@PURPOSE:	handles user input and interaction with closed
			hashtable class
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

#include "ClosedHashtable.h"

void printMenu()
{
	std::cout<<"\nPlease choose a command: \n"
			<<"1) Insert\n"
			<<"2) Delete\n"
			<<"3) Print\n"
			<<"4) Exit\n\n";
}

int main()
{
	//declare variables
	bool use_quad_probing;
	bool continue_program = true;
	int user_input;
	ClosedHashtable* my_hashtable;

	std::string file_input;
	std::ifstream data_file("data.txt");


	//Preliminary user interaction
	std::cout<<"Please choose one of the following hash methods: \n"
			<<"1) Quadratic\n"
			<<"2) Double Hashing\n"
			<<"3) Exit\n\n";

	std::cin >> user_input;
	
	switch(user_input) {
		case 1:
			use_quad_probing = true;
			break;
		case 2:
			use_quad_probing = false;
			break;
		case 3:
			std::cout<<"Have a nice day.";
			return(0);
			break;
		default:
			std::cout<<"Invalid input, shutting down.";
			return(0);
			break;
	}

	//Read from data file
	try
	{
		if(data_file.is_open())
		{
			getline(data_file, file_input);
			//make table
			my_hashtable = new ClosedHashtable(std::stoi(file_input),use_quad_probing);
			while(getline(data_file, file_input))
			{
				my_hashtable->insert(std::stoi(file_input));
			}
		}
		else
		{
			std::cout<<"Could not read from file.\n\n";
			return(-1);
		}
	}
	catch(std::runtime_error& e)
	{
		std::cout<<"Error occurred while reading file.\n";
		std::cout<<"Error is: "<<e.what()<<"\n";
		return(-1);
	}

	//begin regular user interaction

	while(continue_program)
	{
		printMenu();
		std::cin >> user_input;
		switch(user_input) {
			case 1:
				std::cout<<"Please give a value to insert: ";
				std::cin>>user_input;
				my_hashtable->insert(user_input);
				break;
			case 2:
				std::cout<<"Please give the value to delete: ";
				std::cin>>user_input;
				my_hashtable->remove(user_input);
				break;
			case 3:
				my_hashtable->print();
				break;
			case 4:
				std::cout<<"Have a nice day.\n";
				continue_program=false;
				break;
			default:
				std::cout<<"Invalid input.\n\n";
				break;
		}
	}


	delete(my_hashtable);
	return(0);


}
