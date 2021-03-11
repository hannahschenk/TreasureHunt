// ---------------------------------------------------------------------------
//
//                   University of Wisconsin-Stout
//            Mathematics, Statistics & Computer Science
//                 CS-244 Data Structures - Fall 2016
//
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2016
//
// MoneyBag.h
//
// Moneybag that stores the found coins
//
// Instructor: Jocelyn Richardt
// Assignment: Treausre Hunt Game
// Author: Jocelyn Richardt
// Date: 4/23/2016
//
// ---------------------------------------------------------------------------
#ifndef MONEY_BAG_H
#define MONEY_BAG_H

#include "Coin.h"

class MoneyBag
{


public:
	MoneyBag(){};
	~MoneyBag(){};

	void putInBag(Coin* g) {
		//TODO put in a CoinTree
	};


	void print() {
		//TODO traverse the CoinTree to print it out
		cout<<"TODO..not implemented yet."<<endl;
	};


	double calculateValue()
	{
		//TODO traverse the CoinTree to sum up the values
		return 0.0;
	}

	Coin* remove() {
	  //TODO remove the lowest value coin from the CoinTree
    return NULL;
	}

private:

};


#endif
