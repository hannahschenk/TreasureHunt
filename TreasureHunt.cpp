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
// Main.cpp
//
// Main - Console program to launch the TreauseHuntGame
//
// Instructor: Jocelyn Richardt
// Assignment: Treasure Hunt Game
// Author: Jocelyn Richardt
// Date: 4/19/2017
//
// ---------------------------------------------------------------------------
#include "stdafx.h"
#include "TreasureHuntGame.h"
#include <random>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	TreasureHunt theGame;
	theGame.playGame();
	return 0;
}



