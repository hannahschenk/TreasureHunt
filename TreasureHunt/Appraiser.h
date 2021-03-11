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
// Appraiser.h
//
// Appraiser identifies unknown coins and assigns them a unique identifier
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt
// Author: Jocelyn Richardt
// Date: 4/19/2017
//
// ---------------------------------------------------------------------------
#ifndef APPRAISER_H
#define APPRAISER_H

#include <string>

#include "MoneyBag.h"
#include "Coin.h"
#include "Reale.h"

//Singleton to appraise the coins
class Appraiser
{

private:
	//do not allow Appraiser to be constructed
	Appraiser() {};

public:
	~Appraiser() {};

  /**
   *  appraise
   *      parameter: MoneyBag reference
   *
   *      return: a double with the value of the sum of all the coins in the bag.
   *
   *      description: a coin is taken from the bag, then appraised and returned until
   *                     the appraiser finds an already appraised coin which he takes as payment.
   */
  static double appraise(MoneyBag& bag);


private:
  //helper to appraise each coin

   /*
    *  appraiseCoin
    *  parameter: pointer to a pointer to a coin
    *
    *  return: a double with the value and set the pointer to the coin to the new coin.
    *
    *   description: a single coin is constructed as a particular coin based on a percentage
    *                then assign a random value based on the coin type.
    */
  static double appraiseCoin(Coin** aCoin);

};

#endif
