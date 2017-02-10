#ifndef PASSENGER_H
#define PASSENGER_H


#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


class Passenger
{
	bool mIsChild;
	bool mIsMale;
	bool mSurvived;
	bool mFClass;
	bool mSClass;
	bool mTClass;
	bool mCrew;
public:
	// constructors
	Passenger();
	Passenger(bool isChild, bool isMale, bool survived, bool fClass, bool sClass, bool tClass, bool mCrew);

	// getters
	bool getAge();
	bool getGender();
	bool getSurvived();
	bool getFClass();
	bool getSClass();
	bool getTClass();
	bool getCrew();


	// setters
	void setAge(bool isChild);
	void setGender(bool isMale);
	void setSurvived(bool survived);
	void setClass(int ticketClass);
};


#endif




