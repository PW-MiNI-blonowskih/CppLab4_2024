#pragma once
#include <iostream>

enum class nukleozyd { A /*Adenina*/, G /*Guanina*/, C /*Cytozyna*/, T /*Tymina*/ };

class nicDNA //pojedyncza niæ DNA
{
	nukleozyd* nDNA;
	int ilosc_nukleozydow;

public:
	/* Etap 1 */
	nicDNA(int ilosc = 0, const char* nukleozydy = nullptr); //1.0p
	nicDNA(int ilosc, nukleozyd nuk); //0.5p
	~nicDNA(); //0.5p

	char operator()(int i) const; //0.5p

	friend std::ostream& operator<<(std::ostream& out, const nicDNA& ndna); //0.5p

	/* Etap 2 */
	nicDNA(const nicDNA& ndna); //0.5p

	nukleozyd& operator[](int i); //0.5p

	void dolacz(nicDNA& ndna); //1.5p
	int dlugosc() const { return ilosc_nukleozydow; }

	friend nicDNA operator+(const nicDNA& d1, const nicDNA& d2); //0.5p
};