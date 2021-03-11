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
// Reale.h
//
// Reale is a silver Spanish coin from 1715
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt Game
// Author: Jocelyn Richardt
// Date: 4/24/2017
//
// ---------------------------------------------------------------------------
#ifndef REALE_H
#define REALE_H

#include "Coin.h"
#include "Appraiser.h"

class Reale : public Coin
{

public:
	//constructor
	Reale() : Coin() {};
	~Reale() {};

  Reale(Coin& g) : Coin(g) {};

  //print coin info to standard out
	void print() {
		cout << "Reale " << uniqueId_ << ": Value=$" << std::fixed << std::setprecision(2) <<value_;
	}
};

#endif
