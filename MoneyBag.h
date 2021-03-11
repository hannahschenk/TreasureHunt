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
#include "CoinTree.h"

class MoneyBag
{

private:
	CoinTree tree;

public:
	MoneyBag(){};
	~MoneyBag(){};

	void putInBag(Coin* g) {
		tree.insert(g);
	};


	void print() {
		tree.inorderTraversal();
	};


	double calculateValue()
	{
		return tree.sumTraversal();
	}

	Coin* remove() {
		return tree.removeLowestValue();
	}

private:

};


#endif
