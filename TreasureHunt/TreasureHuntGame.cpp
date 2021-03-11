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
// TreasureHuntGame.cpp
//
// Game to find spanish coins from 1715 in order to become a millionaire.
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt Game
// Author: Jocelyn Richardt
// Date: 4/19/2017
//
// ---------------------------------------------------------------------------
#include "stdafx.h"

#include <limits>

#include "TreasureHuntGame.h"
#include "Appraiser.h"
#include "Coin.h"

using namespace std;

//input validation
template <class TYPE>
bool TreasureHunt::readFromStandardIOAndValidateInput(TYPE& input) {
  //executes loop if the input fails (e.g., no characters were read)
  int maxInvalidInput = 5;
  while (!(std::cin >> input) && maxInvalidInput) {
    std::cin.clear(); //clear bad input flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
    std::cout << "Invalid input; please re-enter.\n";
    maxInvalidInput--;
  }
  if (maxInvalidInput == 0) {
    std::cout << "Please learn your numbers from your letters and try again later.\n";
    return false;
  }
  return true;
};

//game setup
void TreasureHunt::playerSetup() {
  cout << "How many players want to dive for treasure?" << endl;
  int nbrOfPlayers = 0;

  //read the number of players
  readFromStandardIOAndValidateInput<int>(nbrOfPlayers);
  while (nbrOfPlayers < 1 || nbrOfPlayers > 10) {
    cout << "There must be at least one player, but not more than 10.";
    cout << "How many players want to dive for treasure?" << endl;
    readFromStandardIOAndValidateInput<int>(nbrOfPlayers);
  }

  //create a MoneyBag for each player
  string playerName;
  MoneyBag* playersBags = new MoneyBag[nbrOfPlayers];
  for (int i = 1; i <= nbrOfPlayers; i++) {
    cout << "Enter the name of player #" << i << endl;
    readFromStandardIOAndValidateInput<string>(playerName);

    //use a pair to hold the player name and the MoneyBag.
    players_.insert(pair<string, MoneyBag&>(playerName, playersBags[i - 1]));
  }
};

//dive choice processing
void TreasureHunt::diveProcessing(pair<string, MoneyBag&> player) {

  //Find out how deep the player will dive for this search
  cout << player.first << ", how deep will you dive?" << endl;
  cout << "Enter an integer in feet:" << endl;
  int divingDepth;
  readFromStandardIOAndValidateInput<int>(divingDepth);

  //Dive on the only boat available in this game to find coins.
  string diveResultMessage;
  int nbrCoins = spanishGalleon_.dive(diveResultMessage, divingDepth);

  //Tell the user the result of the dive
  cout << diveResultMessage << endl;
  if (nbrCoins > 0) {
    cout << "You found a " << nbrCoins << " coins and them into your bag." << endl;
    cout << "However, they are worthless until appraised." << endl << endl;

    //put the unknown coins in the bag
    for (int i = 0; i < nbrCoins; i++) {
      (player.second).putInBag(new Coin());
    }
  }
};

//appraise choice processing
double TreasureHunt::appraiseProcessing(pair<string, MoneyBag&> player) {

  //Appraise the coins
  cout << "You have chosen to appraise your coins." << endl;
  double moneyBagValue = Appraiser::appraise(player.second);
  (player.second).print();

  //inform the user of the result of the appraisal
  cout << "You have $" << moneyBagValue << " in your money bag" << endl;
  return moneyBagValue;
}

//turn taking processing
pair<string, MoneyBag&> TreasureHunt::takeTurns() {

  //intro
  cout << "Are you ready to dive for treasure on the " << endl;
  cout << "Spanish Galleon Shipwrecked in 1715?" << endl;
  cout << "The first player to a million wins!" << endl << endl;
  cout << endl << endl;


  //each player takes a turn until there is a winner
  bool noWinnerYet = true;
  while (noWinnerYet) {

    //walk through the player list in order
    for (pair<string, MoneyBag&> player : players_) {
      cout << player.first << ", ";
      cout << "do you want to dive for treasure or appraise your bag of coins?" << endl;
      cout << " Enter 'd' to dive or 'a' to appraise." << endl << endl;

      //get the users option to dive or appraise
      string choice;
      readFromStandardIOAndValidateInput<string>(choice);

      //User wants to dive
      if (tolower(choice[0]) == 'd') {
        diveProcessing(player);

        //user wants to appraise
      } else if (tolower(choice[0]) == 'a') {
        double value = appraiseProcessing(player);
        if (value >= 1000000.0) {
          //stop taking turns and return the winner
          return player;
        }
      } else {
        cout << "That is not a valid choice.  You lost your turn!";
      }
    }
  }
}


//runs the game.
void TreasureHunt::playGame() {
  //setup the players to start the game
  playerSetup();
  cout << endl;

  //list the names of the players
  for (pair<string, MoneyBag&> player : players_) {
    cout << player.first << "! ";
  }

  //take turns which returns the winner
  pair<string, MoneyBag&> winner = takeTurns();
  cout << "Congratulations " << winner.first << "!  You are the champion!";

}

