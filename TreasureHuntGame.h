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
// TreasureHuntGame.h
//
// TreasureHuntGame is the driver to play the game.
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt Game
// Author: Jocelyn Richardt
// Date: 4/24/2017
//
// ---------------------------------------------------------------------------
#ifndef TREASURE_HUNT_GAME_H
#define TREASURE_HUNT_GAME_H

#include <string>
#include <unordered_map>
#include <utility>

#include "Shipwreck.h"
#include "MoneyBag.h"

using namespace std;

class TreasureHunt
{

public:
  TreasureHunt() {};
  ~TreasureHunt() {};

  /**
   *  Entry point for playing the Treasure Hunt game
   */
  void playGame();

private:
  //one and only ship to search for now
  Shipwreck spanishGalleon_;

  //list of player and their MoneyBag holding collected coins.
  unordered_map<string, MoneyBag&> players_;


  //helper methods

  /**
   * Templated function that reads from cin based on the type specified.
   *    if the type does not match, it will ask up to 5 times for
   *    the user to enter the value.
   *
   *   Parameter:  input - parameter that is set inside the function to the value typed in
   *
   *   Return value:  bool - true if were able to get an input value of the correct type
   *                       - otherwise false
   */
  template <class TYPE>
  bool readFromStandardIOAndValidateInput(TYPE& input);

  /**
   *   Interface to ask user how many players up to 10 and
   *    query the player names so the player can be addressed
   *    by name for each turn.
   */
  void playerSetup();

  /**
   *   Logic for stepping through the player list to take turns 
   *   until a player wins. 
   */
  pair<string, MoneyBag&> takeTurns();


  /**
   *   Manage the user choice to dive on the shipwreck.
   */
  void diveProcessing(pair<string, MoneyBag&> player);


  /**
  *   Manage the user choice to appraise coins in his/her moneybag.
  */
  double appraiseProcessing(pair<string, MoneyBag&> player);


};


#endif
