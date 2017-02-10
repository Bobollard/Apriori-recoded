#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Passenger.h"


void calcConfidence(vector<double>* association, vector<int>* vars, double minAssoc, vector<Passenger>* passengers);


string convertIntToString(int var, int arrPos, vector<Passenger>* passengers);

void loadVectorWithCombo(int offset, int k, vector<int>* vars, vector<int>* curCombo, vector<vector<int>>* result, int numOfCombos);  //Generate all potential combinations of passenger traits
/*Function IS RECURSIVE
offset should be zero when function is called, it is incremented by one to move the starting point of iteration through vector of traits
k is the size of the combinations of traits we are testing
vars vector is the integer representation of all potential traits a passenger amy have (1 through 6)
curCombo is the vector which will hold each combo through k iterations of this function (resets when k = 0), meaning curcombo will be size three if k = 3
result is the pointer to the 2d vector of combos of traits result will need to have its first dimension's size reserved to a value greater than the maximum amount of combos (720)
numOfCombos is a counter for the first dimension of result and should begin at zero*/

void genAssociations(vector<Passenger>* passengers, int size, vector<double>* association, vector<int>* vars, int numVars);

void genAssociations(vector<Passenger>* passengers, int size, vector<double>* association, vector<vector<int>>* vars, int numCombos, int subsetSize);

vector<Passenger>* loadFile();

vector<int>* removePassengers(vector<double>* association, vector<int>* vars, double minAssoc, bool& removed);

vector<vector<int>>* removePasengers(vector<double>* association, vector<vector<int>>* vars, double minAssoc, int subSetSize, int numSubSets, bool& removed);


#endif




