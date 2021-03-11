#pragma once
#include "Coin.h"
#include "Appraiser.h"

class CentennialRoyal : public Coin
{

public:
	//constructor
	CentennialRoyal() : Coin() {};
	~CentennialRoyal() {};

	CentennialRoyal(Coin& g) : Coin(g) {};

	//print coin info to standard out
	void print() {
		cout << "CentennialRoyal " << uniqueId_ << ": Value=$" << std::fixed << std::setprecision(2) << value_;
	}
};

