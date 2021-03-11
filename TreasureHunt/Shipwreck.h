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
// Shipwreck.h
//
// Shipwreck - is a class that represents a ship the was wrecked off
//        the coast of Florida.  Modern day treasure hunters search these
//        wrecks to find coins from the 1715 Spanish Shipwrecks.
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt Game
// Author: Jocelyn Richardt
// Date: 4/19/2017
//
// ---------------------------------------------------------------------------
#ifndef SHIPWRECK_H
#define SHIPWRECK_H

#include <string>
#include <unordered_map>

using namespace std;

class Shipwreck
{
public:
	Shipwreck();
	~Shipwreck();

	//Function that represents the user diving into the shipwreck to find treasuer
	//  return parameters:  message & number of coins found
	//  input parameter: depth
	int dive(string& message, int depth);

private:
  //Helper function to find the correct percentage of coins from the available coins on the shipwreck
  //  returns number of coins found
	int findCoins(int depth);


private:
  //hash table to store where the coins are hidden with a key of the depth
  unordered_map<int,int> coinLocations_;
};

#endif
