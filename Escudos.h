#pragma once
#include "Coin.h"
#include "Appraiser.h"

class Escudos : public Coin
{

public:
	//constructor
	Escudos() : Coin() {};
	~Escudos() {};

	Escudos(Coin& g) : Coin(g) {};

	//print coin info to standard out
	void print() {
		cout << "Escudos " << uniqueId_ << ": Value=$" << std::fixed << std::setprecision(2) << value_;
	}
};

