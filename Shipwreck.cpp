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
// Shipwreck.cpp
//
// Shipwreck is one of the Spanish Galleons that was carrying gold and silver coins back to spain
//  when a storm wrecked and sank several of the ships.
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt Game
// Author: Jocelyn Richardt
// Date: 4/19/2017
//
// ---------------------------------------------------------------------------
#include "stdafx.h"

#include "Shipwreck.h"

#include <string>
#include <random>
#include <iostream>

Shipwreck::Shipwreck()
{
  //If I were really creating this game, I'd want to load this info from a file and make it
  // unique for different shipwrecks

  coinLocations_.insert(make_pair(60,2));   //pair is (depth in feet, # of coins)
  coinLocations_.insert(make_pair(70,25));
  coinLocations_.insert(make_pair(80,50));
  coinLocations_.insert(make_pair(100,25));
  coinLocations_.insert(make_pair(120,50));
  coinLocations_.insert(make_pair(130,75));
}


Shipwreck::~Shipwreck()
{
}

int Shipwreck::findCoins(int depth){
    int availableCoins = coinLocations_[depth];
    int foundCoins = 0;
    if (availableCoins == 1) {
      foundCoins = 1;
    } else {
      //can find up to 50% of the coins on a dive unless only one coin left
      double percentOfCoinsFound = ((rand() % 5) + 1)/10.0;
      //cout<<"percentOfCoinsFound = "<<percentOfCoinsFound;
      //cout<<"availableCoins = "<<availableCoins;

      //determine how many of the available coins were found this time
      foundCoins = availableCoins * percentOfCoinsFound;
      //cout<<"foundCoins = "<<foundCoins;
    }

    //remove those foundCoins from the shipwreck
    coinLocations_[depth] = availableCoins - foundCoins;

    return foundCoins;
}

int Shipwreck::dive(string & message, int depth)
{
  //check the depth to find the correct hash key.
  //if this were a real game, I'd manage messages from a file and have more options.
  if (depth < 50) {
    message ="You didn't even descend far enough to find the shipwreck.";
    return 0;
  } else if (depth < 60) {
    message = "You searched the crows nest.";
    return findCoins(60);
  } else if (depth < 70){
    message = "You searched the deck.";
    return findCoins(70);
  } else if (depth < 80){
    if (rand() % 3 == 2) {  //1 in 3 chance
      message = "You barely escaped a trap in the Captain's Quarters.";
      return 0;
    }
    message = "You searched Captain's Quarters.";

    return findCoins(80);
  } else if (depth < 100){
    if (rand()% 3 == 2) {  //1 in 3 chance
      message = "You were chased out of the ship by a shark.";
      return 0;
    }
    message = "You searched the broken hull.";
    return findCoins(100);
  } else if (depth < 120){
    if (rand()% 3 == 2) {  //1 in 3 chance
      message = "You got narc'd and gave your coins to a resting sea turtle.";
      return 0;
    }
    message = "You searched the broken hull.";
    return findCoins(120);
  } else if (depth < 130){
    if (rand()% 3 < 2) {  //2 in 3 chance
      message = "You got narc'd, dropped you coins, and sang a lullaby to resting sea turtle.";
      return 0;
    }
    message = "You searched the ocean floor.";
    return findCoins(130);
  } else {
     message = "You tried to go down into the abyss, but were luckily rescued by a divemaster.";
    return 0;
  }

	return 0;
}
