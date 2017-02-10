#include "Passenger.h"
#include "functions.h"


void calcConfidence(vector<double>* association, vector<int>* vars, double minAssoc, vector<Passenger>* passengers)
{
	for (int i = 0; i < vars->size(); i++)
	{
		double confidence;
		int traitSeen = 0;
		int timesSeen = 0;
		//Child
		if (vars->at(i) == 1)
		{
			if (association->at(i) >= minAssoc)
			{
				for (int j = 0; j < passengers->size(); j++)
				{
					if (passengers->at(j).getAge() == true)
					{
						traitSeen++;
					}
					if (passengers->at(j).getAge() == true && passengers->at(j).getSurvived() == true)
					{
						timesSeen++;
					}
				}
				confidence = traitSeen / timesSeen;
				if (confidence >= .5)
				{
					cout << "Confidence of Child and Survived: " << confidence << endl;
				}
				else
				{
					cout << "Confidence of Adult and Survived: " << 1 - confidence << endl;
				}
			}
		}




		//Male	
		if (vars->at(i) == 2)
		{
			if (association->at(i) >= minAssoc)
			{
				for (int j = 0; j < passengers->size(); j++)
				{
					if (passengers->at(j).getGender() == true)
					{
						traitSeen++;
					}
					if (passengers->at(j).getGender() == true && passengers->at(j).getGender() == true)
					{
						timesSeen++;
					}
				}
				confidence = traitSeen / timesSeen;
				if (confidence >= .5)
				{
					cout << "Confidence of Male and Survived: " << confidence << endl;
				}
				else
				{
					cout << "Confidence of Female and Survived: " << 1 - confidence << endl;
				}
			}
		}




		//First Class
		if (vars->at(i) == 4)
		{
			if (association->at(i) >= minAssoc)
			{
				for (int j = 0; j < passengers->size(); j++)
				{
					if (passengers->at(j).getFClass() == true)
					{
						traitSeen++;
					}
					if (passengers->at(j).getFClass() == true && passengers->at(j).getFClass() == true)
					{
						timesSeen++;
					}
				}
				confidence = traitSeen / timesSeen;
				cout << "Confidence of First Class and Survived: " << confidence << endl;
			}
		}




		//Second Class
		if (vars->at(i) == 4)
		{
			if (association->at(i) >= minAssoc)
			{
				for (int j = 0; j < passengers->size(); j++)
				{
					if (passengers->at(j).getSClass() == true)
					{
						traitSeen++;
					}
					if (passengers->at(j).getSClass() == true && passengers->at(j).getSClass() == true)
					{
						timesSeen++;
					}
				}
				confidence = traitSeen / timesSeen;
				cout << "Confidence of Second Class and Survived: " << confidence << endl;
			}
		}




		//Third Class
		if (vars->at(i) == 4)
		{
			if (association->at(i) >= minAssoc)
			{
				for (int j = 0; j < passengers->size(); j++)
				{
					if (passengers->at(j).getTClass() == true)
					{
						traitSeen++;
					}
					if (passengers->at(j).getTClass() == true && passengers->at(j).getTClass() == true)
					{
						timesSeen++;
					}
				}
				confidence = traitSeen / timesSeen;
				cout << "Confidence of Third Class and Survived: " << confidence << endl;
			}
		}

	}
}


void calcConfidence(vector<double>* association, vector<vector<int>>* vars, double minAssoc, vector<Passenger>* passengers, int subSetSize)
{
	double confidence;
	bool subsetExists = true;
	int numTimesOfSubset = 0;
	int numTimesOfSurv = 0;

	for (int i = 0; i < vars->size(); i++)
	{
		for (int j = 0; j < vars->at(i).size(); ++j)
		{
			for (int k = 0; k < passengers->size(); ++k)
			{
				switch (vars->at(i)[j])
				{
				case 1:
					if (passengers->at(k).getAge() != true)
					{
						subsetExists = false;
					}
					break;
				case 2:
					if (passengers->at(k).getGender() != true)
					{
						subsetExists = false;
					}
					break;
				case 3:
					if (passengers->at(k).getSurvived() != true)
					{
						subsetExists = false;
					}
					else
					{
						++numTimesOfSurv;
					}
					break;
				case 4:
					if (passengers->at(k).getFClass() != true)
					{
						subsetExists = false;
					}
					break;
				case 5:
					if (passengers->at(k).getSClass() != true)
					{
						subsetExists = false;
					}
					break;
				case 6:
					if (passengers->at(k).getTClass() != true)
					{
						subsetExists = false;
					}
					break;
				case 7:
					if (passengers->at(k).getCrew() != true)
					{
						subsetExists = false;
					}
					break;
				}
				if (passengers->at(k).getSurvived() == true)
				{
					++numTimesOfSurv;
				}
			}
			if (subsetExists == true)
			{
				++numTimesOfSubset;
			}
		}
		confidence = numTimesOfSubset / numTimesOfSurv;
		cout << "Confidence for ";
		for (int z = 0; z < vars->at(i).size(); z++)
		{
			string varStr = convertIntToString(vars->at(i).at(z), i, passengers);
			cout << varStr << " ";
		}
		cout << ": " << confidence;
		subsetExists = false;




	}
}


string convertIntToString(int var, int arrPos, vector<Passenger>* passengers)
{
	if (var == 1)
	{
		if (passengers->at(arrPos).getAge() == true)
		{
			return "Child";
		}
		else
		{
			return "Adult";
		}
	}
	else if (var == 2)
	{
		if (passengers->at(arrPos).getGender() == true)
		{
			return "Male";
		}
		else
		{
			return "Female";
		}
	}




	else if (var == 4)
	{
		if (passengers->at(arrPos).getFClass() == true)
		{
			return "First Class";
		}
		else
		{
			return "Not First Class";
		}
	}
	else if (var == 5)
	{
		if (passengers->at(arrPos).getSClass() == true)
		{
			return "Second Class";
		}
		else
		{
			return "Not Second Class";
		}
	}
	else if (var == 6)
	{
		if (passengers->at(arrPos).getTClass() == true)
		{
			return "Third Class";
		}
		else
		{
			return "Not Third Class";
		}
	}
	else
	{
		return "Not valid input";
	}
}

void loadVectorWithCombo(int offset, int k, vector<int>* vars, vector<int>* curCombo, vector<vector<int>>* result, int numOfCombos)
{
		if (k == 0) {
			for (int x = 0; x < curCombo->size(); x++)
			{
				result->at(numOfCombos)[curCombo->at(x)];
			}
			return;
		}
		for (int i = offset; i <= vars->size() - k; ++i) {
			curCombo->push_back(vars->at(i));
			loadVectorWithCombo(i + 1, k - 1, vars, curCombo, result, numOfCombos);
			numOfCombos;
			curCombo->pop_back();
		}
}





void genAssociations(vector<Passenger>* passengers, int size, vector<double>* association, vector<int>* vars, int numVars)
{
	/**************************************************************************************************************************************************************************************
	* passengers = vector containing information on all passengers
	* size = number of passengers
	* associtaion = array to store associations. Each element corresponds with one variable (isMale, isChild, etc...). Each element counts the number of times that var was true.
	* vars = numbers corresponding to the variables to be checked (1 = isChild, 2 = isMale, etc...)
	* numVars = number of variables to be checked (size of association array)
	* subsetSize = number of variables in each subset
	**************************************************************************************************************************************************************************************/


	for (int i = 0; i < size; ++i) // search through the whole list of passengers
	{
		for (int j = 0; j < numVars; ++j) // search through the desired variables
		{
			// count how many times each variable appears and store in the association array
			switch (vars->at(j))
			{
			case 1:
				if (passengers->at(i).getAge() == true)
				{
					++association->at(j);
				}
				break;
			case 2:
				if (passengers->at(i).getGender() == true)
				{
					++association->at(j);
				}
				break;
			case 3:
				if (passengers->at(i).getSurvived() == true)
				{
					++association->at(j);
				}
				break;
			case 4:
				if (passengers->at(i).getFClass() == true)
				{
					++association->at(j);
				}
				break;
			case 5:
				if (passengers->at(i).getSClass() == true)
				{
					++association->at(j);
				}
				break;
			case 6:
				if (passengers->at(i).getTClass() == true)
				{
					++association->at(j);
				}
				break;
			case 7:
				if (passengers->at(i).getCrew() == true)
				{
					++association->at(j);
				}
			}
		}
	}

	// calculate the association percentage for each variable
	for (int k = 0; k < numVars; ++k)
	{
		association->at(k) /= size;
	}
}

void genAssociations(vector<Passenger>* passengers, int size, vector<double>* association, vector<vector<int>>* vars, int numCombos, int subsetSize)
{
	/**************************************************************************************************************************************************************************************
	* passengers = vector containing information on all passengers
	* size = number of passengers
	* associtaion = array to store associations. Each element corresponds with one variable (isMale, isChild, etc...). Each element counts the number of times that var was true.
	* vars = 2d vector of combinations of numbers corresponding to the variables to be checked
	* numVars = number of variables to be checked (size of association array)
	* subsetSize = number of variables in each subset
	**************************************************************************************************************************************************************************************/

				bool subsetExists = true; // switched to false if an element of the current subset is not found for a passenger

				for (int j = 0; j < size; ++j) // read through list of passengers
				{
					for (int k = 0; k < numCombos; ++k) // read through list of combinations
					{
						for (int x = 0; x < subsetSize; ++x) // read through elements of each subset
						{
							switch (vars->at(k)[x])
							{
							case 1:
								if (passengers->at(j).getAge() != true)
								{
									subsetExists = false;
								}
								break;
							case 2:
								if (passengers->at(j).getGender() != true)
								{
									subsetExists = false;
								}
								break;
							case 3:
								if (passengers->at(j).getSurvived() != true)
								{
									subsetExists = false;
								}
								break;
							case 4:
								if (passengers->at(j).getFClass() != true)
								{
									subsetExists = false;
								}
								break;
							case 5:
								if (passengers->at(j).getSClass() != true)
								{
									subsetExists = false;
								}
								break;
							case 6:
								if (passengers->at(j).getTClass() != true)
								{
									subsetExists = false;
								}
								break;
							case 7:
								if (passengers->at(j).getCrew() != true)
								{
									subsetExists = false;
								}
							}

							if (subsetExists == true)
							{
								++association->at(k);
							}
						}
					}
						subsetExists = true;
				}

	// calculate the association percentage for each variable
	for (int k = 0; k < numCombos; ++k)
	{
		association->at(k) /= size;
	}
}

vector<Passenger>* loadFile()
{
	vector<Passenger>* data = new vector<Passenger>;
	ifstream file("titanic.csv"); //file layout: Class,Sex,Age,Survived
	bool fclass;
	bool sclass;
	bool tclass;
	bool crew;
	bool ismale;
	bool ischild;
	bool surv;
	string tmp;




	getline(file, tmp); //read first line of file and position stream at first line of data
	while (file.good())
	{
		fclass = false;
		sclass = false;
		tclass = false;
		crew = false;
		getline(file, tmp, ','); // read a string until next comma
		if (tmp == "1st")
		{
			fclass = true;
		}
		else if (tmp == "2nd")
		{
			sclass = true;
		}
		else if (tmp == "3rd")
		{
			tclass = true;
		}
		else if (tmp == "Crew")
		{
			crew = true;
		}
		getline(file, tmp, ',');
		if (tmp == "Male")
		{
			ismale = true;
		}
		else
		{
			ismale = false;
		}
		getline(file, tmp, ',');
		if (tmp == "Child")
		{
			ischild = true;
		}
		else
		{
			ischild = false;
		}
		getline(file, tmp, '\n');
		if (tmp == "Yes")
		{
			surv = true;
		}
		else
		{
			surv = false;
		}
		Passenger newpass(ischild, ismale, surv, fclass, sclass, tclass, crew);
		data->push_back(newpass);


	}


	return data;
}


vector<int>* removePassengers(vector<double>* association, vector<int>* vars, double minAssoc, bool& removed)
{
	vector<int>* newVec = new vector<int>;


	for (int i = 0; i < vars->size(); i++)
	{
		if (association->at(i) >= minAssoc)
		{
			newVec->push_back(vars->at(i));
		}
		else
		{
			removed = true;
		}
	}




	return newVec;
}


vector<vector<int>>* removePasengers(vector<double>* association, vector<vector<int>>* vars, double minAssoc, int subSetSize, int numSubSets, bool& removed)
{
	vector<vector<int>>* newVec = new vector<vector<int>>;


	for (int i = 0; i < numSubSets; i++)
	{
		if (association->at(i) >= minAssoc)
		{
			newVec->push_back(vars->at(i));
		}
		else
		{
			removed = true;
		}
	}
	return newVec;
}




