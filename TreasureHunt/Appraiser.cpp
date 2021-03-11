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
// Appraiser.cpp
//
// Appraiser identifies unknown coins and assigns them a unique identifier
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt
// Author: Jocelyn Richardt
// Date: 4/19/2017
//
// ---------------------------------------------------------------------------
#include "stdafx.h"

#include <random>

#include "Appraiser.h"
#include "MoneyBag.h"

// appraise a single coin
double Appraiser::appraiseCoin(Coin** aCoin) {

  // TODO set up random with 3% for TricentennialRoyal; 30% Escudos; 67% Reale

  //TODO add code to construct a TricentennialRoyal from an unknown Coin
  //  make sure it keeps the same uniqueId_
  //  make sure to not leak memory
  //  set the value from 100,000 to 500,000 dollars


  //TODO add code to construct a Escudos from an unknown Coin
  //  make sure it keeps the same uniqueId_
  //  make sure to not leak memory
  //  set the value from 50,000 to 100,000 dollars

  //only identifies the silver Reale
  Coin* temp = new Reale(**aCoin);
  delete *aCoin;
  *aCoin = temp;
  (*aCoin)->appraise((rand()% 5 + 5) * 100);  //500 to 1,000 dollars

  return (*aCoin)->getValue();

};

//appraise unappraise coins from the MoneyBag
double Appraiser::appraise(MoneyBag& bag)
{
	Coin* aCoin = bag.remove();
   //nothing to remove
 	if (!aCoin) {
      cout << "There are no coins to appraise."<<endl;;
      return 0.0;
  }

	do {
      double value = appraiseCoin(&aCoin);
      bag.putInBag(aCoin);
      //take out the next coin to appraise
      aCoin = bag.remove();
 	}	while (aCoin->getValue()<=0.0);

   if (aCoin) {
      //if the coin has been appraised, take is as payment
      cout << "Payment of "<<aCoin->getValue() << " has been taken."<<endl;;
   }

	return bag.calculateValue();
}

