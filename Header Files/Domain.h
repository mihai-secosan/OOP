#ifndef DOMAIN_H
#define DOMAIN_H

#include "MyExeptions.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>
#include <stdio.h>

class Disciplina
{
private:
	std::string denumire;
	int ore_pe_saptamana;
	std::string tip;
	std::string cadru_didactic;

public:
	Disciplina() noexcept;
	/*
		Creates a new Disciplina {"", 0, "", ""}
	*/

	Disciplina(const Disciplina& disc);
	/*
		Creates a copy of disc
	*/

	Disciplina(std::string _denumire, int _ore_pe_saptamana, std::string _tip, std::string _cadru_didactic);
	/*
		Creates a new Disciplina {_denumire, _ore_pe_saptamana, _tip, _cadru_didactic}
	*/

	std::string get_denumire() const;
	/*
		Returns denumire
	*/

	int get_ore() const noexcept;
	/*
		Returns ore_pe_saptamana
	*/

	std::string get_tip() const;
	/*
		Returns tip
	*/

	std::string get_cadru_didactic() const;
	/*
		Returns cadru_didactic
	*/

	int compare_denumire(const Disciplina& other) const;
	/*
		returns true if this->denumire > other.denumire
	*/

	int compare_ore(const Disciplina& other) const noexcept;
	/*
		returns true if this->ore > other.ore
	*/

	int compare_tip(const Disciplina& other) const;
	/*
		returns true if this->tip > other.tip
	*/

	int compare_cadru(const Disciplina& other) const;
	/*
		returns true if this->cadru_didactic > other.cadru_didactic
	*/

	//void become(const Disciplina& other);
	/*
		makes this a copy of other
	*/

	std::string to_string() const;
	/*
		Returns a std::string containing the information of the Disciplina
	*/
};

void test_domain();

#endif
