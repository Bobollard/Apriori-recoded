/**********************************************************************************************************************************
Authors: Ryan Bollard, Shawn Fortin
Class: CSI-281-03
Assignment: Apriori
Date Assigned: 11/15/2016
Due Date: 11/229/2016 9:30 AM
Description: Implementation of Apriori
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
-Communicate a copy of this assignment to a plagiarism checking service(which may then
retain a copy of this assignment on its database for the purpose of future plagiarism checking)
**********************************************************************************************************************************/




#include "functions.h"
#include "Passenger.h"
#include <iostream>
using namespace std;








int main()
{
	// bool to determine if variables were removed (to check if further runs are necessary)
	bool removed = false;


	// current subset size, will start at two (first run does not use this variable) and increase each time the functions are called
	int subsetSize = 2;


	// minimum association value
	double minAssociation = 0.4;


	// number of times associations have been generated
	int round = 0;


	// vector to hold all passengers
	vector<Passenger>* passengers = loadFile();
	cout << "size of passenger vector: " << passengers->size() << endl;


	cout << "Minimum association: " << minAssociation << endl << endl;


	// vector to hold the variables being analysed
	vector<int>* vars = new vector<int>;
	// fill the vector with numbers to represent all the variables possible
	for (int i = 0; i < 7; ++i)
	{
		vars->push_back(i + 1);
	}
	// print a list of the traits
	cout << "list of variables being analysed: ";
	for (int x = 0; x < vars->size(); ++x)
	{
		cout << vars->at(x) << " ";
	}
	cout << endl;


	cout << "Key:\n"
		<< "1: isChild\n"
		<< "2: isMale\n"
		<< "3: survived\n"
		<< "4: first class\n"
		<< "5: second class\n"
		<< "6: third class\n"
		<< "7: crew\n\n";




	// vector to store associations
	vector<double>* associations = new vector<double>(7);
	// fill the vector with zeroes
	for (int j = 0; j < associations->size(); ++j)
	{
		associations->at(j) = 0;
	}


	// generate associations for the first run
	genAssociations(passengers, passengers->size(), associations, vars, vars->size());
	++round;


	cout << "After Round " << round << ":\n";








	// remove variables if necessary
	vars = removePassengers(associations, vars, minAssociation, removed);








	// print a list of the remaining variables
	cout << "Remaining variables: ";
	for (int x = 0; x < vars->size(); ++x)
	{
		cout << vars->at(x) << " ";
	}
	cout << endl << endl;








	calcConfidence(associations, vars, minAssociation, passengers);








	vector<vector<int>>* varSubsets = new vector<vector<int>>;
	varSubsets->reserve(720); //Reserved size to max amt. of combos possible








							  // continue the above process for as long as necessary
	while (removed == true && vars->size() >= 1)
	{
		removed = false;
		if (subsetSize == 1)
		{
			genAssociations(passengers, passengers->size(), associations, vars, vars->size());


			++round;


			cout << "After Round " << round << ":\n";


			// print a list of the remaining variables
			cout << "Remaining variables: ";
			for (int x = 0; x < vars->size(); ++x)
			{
				cout << vars->at(x) << " ";
			}
			cout << endl << endl;
		}
		else
		{
			genAssociations(passengers, passengers->size(), associations, varSubsets, varSubsets->size(), subsetSize);


			++round;


			cout << "After Round " << round << ":\n";


			// print a list of the remaining variables
			cout << "Remaining variables: ";
			for (int x = 0; x < vars->size(); ++x)
			{
				cout << vars->at(x) << " ";
			}
			cout << endl << endl;
		}
		varSubsets = removePasengers(associations, varSubsets, minAssociation, subsetSize, varSubsets->size(), removed);
		++subsetSize;
	}






	cout << "Press enter to continue...";
	cin.get();
	return 0;
}




