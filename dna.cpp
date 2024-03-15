#include "dna.h"

DNA::DNA() {
	ndna1 = nicDNA();
	ndna2 = nicDNA();
}

DNA::DNA(nicDNA ndna) : ndna1{ nicDNA(ndna) }, ndna2{ nicDNA(ndna.dlugosc()) } {
	for (int i = 0; i < ndna.dlugosc(); ++i) {
		switch (ndna(i))
		{
		case 'A': ndna2[i] = nukleozyd::T; break;
		case 'T': ndna2[i] = nukleozyd::A; break;
		case 'G': ndna2[i] = nukleozyd::C; break;
		case 'C': ndna2[i] = nukleozyd::G; break;
		default:
			break;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const DNA& dna) {
	out << "______" << std::endl;
	for (int i = 0; i < dna.ndna1.dlugosc(); ++i) {
		out << "|" << dna.ndna1(i) << "--" << dna.ndna2(i) << "|" << std::endl;
	}
	out << "______" << std::endl;

	return out;
}

char DNA::operator()(int i, int j) const {
	switch (i)
	{
	case 1: return ndna1(j); break;
	case 2: return ndna2(j); break;
	default:
		break;
	}
}

DNA DNA::klon(DNA& zywnosc) {
	if ((*this).ndna1.dlugosc() > zywnosc.ndna1.dlugosc()) {
		return DNA();
	}

	int ilosci1[4] = { 0,0,0,0 }; //A,C,T,S
	int ilosci2[4] = { 0,0,0,0 }; //A,C,T,S

	for (int i = 0; i < (*this).ndna1.dlugosc(); ++i) {
		switch ((*this).ndna1(i))
		{
		case 'A': ilosci1[0] += 1;  break;
		case 'C': ilosci1[1] += 1;  break;
		case 'T': ilosci1[2] += 1;  break;
		case 'S': ilosci1[3] += 1;  break;
		default:
			break;
		}
	}

	for (int i = 0; i < zywnosc.ndna1.dlugosc(); ++i) {
		switch (zywnosc.ndna1(i))
		{
		case 'A': ilosci2[0] += 1;  break;
		case 'C': ilosci2[1] += 1;  break;
		case 'T': ilosci2[2] += 1;  break;
		case 'S': ilosci2[3] += 1;  break;
		default:
			break;
		}
	}

	if (ilosci1[0] <= ilosci2[0] &&
		ilosci1[1] <= ilosci2[1] &&
		ilosci1[2] <= ilosci2[2] &&
		ilosci1[3] <= ilosci2[3]) {
		return *this;
	}

	return DNA();
}

