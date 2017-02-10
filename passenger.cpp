#include "Passenger.h"


// constructors
Passenger::Passenger()
{
	mIsChild = false;
	mIsMale = false;
	mSurvived = false;
	mFClass = false;
	mSClass = false;
	mTClass = false;
	mCrew = false;
}


Passenger::Passenger(bool isChild, bool isMale, bool survived, bool fClass, bool sClass, bool tClass, bool crew)
{
	mIsChild = isChild;
	mIsMale = isMale;
	mSurvived = survived;
	mFClass = fClass;
	mSClass = sClass;
	mTClass = tClass;
	mCrew = crew;
}


// getters
bool Passenger::getAge()
{
	return mIsChild;
}


bool Passenger::getGender()
{
	return mIsMale;
}


bool Passenger::getSurvived()
{
	return mSurvived;
}


bool Passenger::getFClass()
{
	return mFClass;
}


bool Passenger::getSClass()
{
	return mSClass;
}


bool Passenger::getTClass()
{
	return mTClass;
}


bool Passenger::getCrew()
{
	return mCrew;
}


// setters
void Passenger::setAge(bool isChild)
{
	mIsChild = isChild;
}


void Passenger::setGender(bool isMale)
{
	mIsMale = isMale;
}


void Passenger::setSurvived(bool survived)
{
	mSurvived = survived;
}


void Passenger::setClass(int ticketClass)
{
	if (ticketClass == 1)
	{
		mFClass = true;
		mSClass = false;
		mTClass = false;
	}
	else if (ticketClass == 2)
	{
		mFClass = false;
		mSClass = true;
		mTClass = false;
	}
	else if (ticketClass == 3)
	{
		mFClass = false;
		mSClass = false;
		mTClass = true;
	}
}




