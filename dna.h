#pragma once
#include "ndna.h"

class DNA //podwójna niæ DNA
{
	nicDNA ndna1;
	nicDNA ndna2;

public:
	DNA(); //0.5p
	DNA(nicDNA ndna); //1.0p

	char operator()(int i, int j) const; //0.5p

	DNA klon(DNA& zywnosc); //1.5p 

	friend std::ostream& operator<<(std::ostream& out, const DNA& dna); //0.5p
};