// ---------------------------------------------------------------------------
//
//                   University of Wisconsin-Stout
//            Mathematics, Statistics & Computer Science
//                 CS-244 Data Structures - Fall 2016
//
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2017
//
// Coin.h
//
// Coin - is a class that represents the different coins from the 1715 Spanish Shipwrecks that
//        can be found in the on the shipwrecks.  The coins are appraised based on its type,
//        weight and stamp clarity.
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt Game
// Author: Jocelyn Richardt
// Date: 4/19/2017
//
// ---------------------------------------------------------------------------
#ifndef COIN_H
#define COIN_H

#include <string>
#include <iostream>
#include <iomanip>


using namespace std;

class Coin
{

public:
  //constructor
	Coin();
	//destructor
	~Coin();
	//copy constructor
	Coin(const Coin& g);


protected:

	int uniqueId_;  //unique id assigned to the coin
	double value_;  //value set by the appraiser

	static int uniqueIdCounter_;




public:

  //allow the value of the coin to be set.
  void appraise(double appraisedValue) { this->value_ = appraisedValue; }

  //getter for the coin value
	double getValue() { return this->value_; }

	//Write coin info to standard out 
	void print() {
		cout << "Unknown " << uniqueId_ << ": Value=$" << std::fixed << std::setprecision(2) <<value_;
	}

	//assigment
	virtual void operator=(const Coin& g)
	{
		uniqueId_ = g.uniqueId_;
		value_ = g.value_;
	}

	//compare operators
	bool operator==(const Coin& g);
	bool operator!=(const Coin& g);
	bool operator<(const Coin& g);
	bool operator<=(const Coin& g);
	bool operator>(const Coin& g);
	bool operator>=(const Coin& g);

};
#endif
