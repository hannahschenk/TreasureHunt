// ---------------------------------------------------------------------------
//
//                   University of Wisconsin-Stout
//            Mathematics, Statistics & Computer Science
//                 CS-244 Data Structures – Fall 2016
//
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2016,2017
//
// Coin.cpp
//
// Coin - is a class that represents the different coins from the 1715 Spanish Shipwrecks that
//        can be found in the on the shipwrecks.  The coins are appraised based on its type,
//        weight and stamp clarity.
//
// Instructor: Jocelyn Richardt
// Assignment: TreasureHunt
// Author: Jocelyn Richardt
// Date: 4/24/2017
//
// ---------------------------------------------------------------------------
#include "stdafx.h"

#include "Coin.h"

int Coin::uniqueIdCounter_=100000;

//give each coin a unique id
Coin::Coin() {
  value_ = 0.0;
  uniqueId_ = uniqueIdCounter_++;
};

Coin::~Coin() {};

//copy constructor
Coin::Coin(const Coin& g) : value_(g.value_),uniqueId_(g.uniqueId_) {};

//comparisons
bool Coin::operator==(const Coin& g) {
	return (uniqueId_ == g.uniqueId_);
}

bool Coin::operator!=(const Coin& g) {
  //TODO
  return false;
}
bool Coin::operator<(const Coin& g) {
  //TODO
  return false;
}
bool Coin::operator<=(const Coin& g) {
  //TODO
  return false;
}
bool Coin::operator>(const Coin& g) {
  //TODO
  return false;
}
bool Coin::operator>=(const Coin& g) {
  //TODO
  return false;
}
