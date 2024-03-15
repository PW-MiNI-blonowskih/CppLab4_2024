#include "ndna.h"

nicDNA::nicDNA(int ilosc, const char* nukleozydy) : ilosc_nukleozydow{ ilosc } {
	if (ilosc == 0 && nukleozydy == nullptr) {
		nDNA = nullptr;
		return;
	}
	
	nDNA = new (std::nothrow) nukleozyd[ilosc];
	if (nDNA == nullptr) return;

	if (nukleozydy == nullptr) {
		for (int i = 0; i < ilosc; ++i) {
			nDNA[i] = nukleozyd::A;
		}
	}
	else {
		for (int i = 0; i < ilosc; ++i) {
			switch (nukleozydy[i]) {
			case 'A': nDNA[i] = nukleozyd::A; break;
			case 'G': nDNA[i] = nukleozyd::G; break;
			case 'C': nDNA[i] = nukleozyd::C; break;
			case 'T': nDNA[i] = nukleozyd::T; break;
			default:
				std::cout << "switch error" << std::endl;
				break;
			}
		}
	}
}

nicDNA::nicDNA(int ilosc, nukleozyd nuk) : ilosc_nukleozydow{ ilosc } {
	nDNA = new (std::nothrow) nukleozyd[ilosc];
	if (nDNA == nullptr) return;

	for (int i = 0; i < ilosc; ++i) {
		nDNA[i] = nuk;
	}
}

nicDNA::~nicDNA() {
	delete[] nDNA;
}

char nicDNA::operator()(int i) const {
	switch (nDNA[i])
	{
	case nukleozyd::A: return 'A'; break;
	case nukleozyd::G: return 'G'; break;
	case nukleozyd::C: return 'C'; break;
	case nukleozyd::T: return 'T'; break;
	default:
		break;
	}
}

std::ostream& operator<<(std::ostream& out, const nicDNA& ndna) {
	out << "___" << std::endl;
	for (int i = 0; i < ndna.ilosc_nukleozydow; ++i) {
		out << "|" << ndna(i) << "-" << std::endl;
	}
	out << "___" << std::endl;
	return out;
}

nukleozyd& nicDNA::operator[] (int i) {
	return nDNA[i];
}

nicDNA operator+(const nicDNA& d1, const nicDNA& d2) {
	nicDNA d3;
	int nowa_ilosc = d1.ilosc_nukleozydow + d2.ilosc_nukleozydow;
	d3.ilosc_nukleozydow = nowa_ilosc;
	
	d3.nDNA = new (std::nothrow) nukleozyd[nowa_ilosc];

	int i = 0;
	if (d3.nDNA != nullptr) {
		for (; i < d1.ilosc_nukleozydow; ++i) {
			d3.nDNA[i] = d1.nDNA[i];
		}
		for (; i < nowa_ilosc; ++i) {
			d3.nDNA[i] = d2.nDNA[i - d1.ilosc_nukleozydow];
		}
	}

	return d3;
}

nicDNA::nicDNA(const nicDNA& ndna) :ilosc_nukleozydow{ ndna.ilosc_nukleozydow } {
	nDNA = new (std::nothrow) nukleozyd[ndna.ilosc_nukleozydow];
	if (nDNA == nullptr) return;

	for (int i = 0; i < ndna.ilosc_nukleozydow; ++i) {
		nDNA[i] = ndna.nDNA[i];
	}
}

void nicDNA::dolacz(nicDNA& ndna) {
	nicDNA temp(*this + ndna);
	(*this).ilosc_nukleozydow = temp.ilosc_nukleozydow;
	delete[](*this).nDNA;
	(*this).nDNA = new (std::nothrow) nukleozyd[temp.ilosc_nukleozydow];
	for (int i = 0; i < temp.ilosc_nukleozydow; ++i) {
		(*this).nDNA[i] = temp.nDNA[i];
	}

	ndna.ilosc_nukleozydow = 0;
	ndna.nDNA = nullptr;
}