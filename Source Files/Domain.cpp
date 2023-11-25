#include "../Header Files/Domain.h"

#include <algorithm>

Disciplina::Disciplina() noexcept
{
	this->denumire.clear();
	this->ore_pe_saptamana = 0;
	this->tip.clear();
	this->cadru_didactic.clear();
}

Disciplina::Disciplina(const Disciplina& disc)
{
	//std::cout << "S-A EFECTUAT O COPIERE A UNEI DISCIPLINE!!!" << disc.to_string() << "\n";

	denumire = disc.denumire;
	ore_pe_saptamana = disc.ore_pe_saptamana;
	tip = disc.tip;
	cadru_didactic = disc.cadru_didactic;
}

Disciplina::Disciplina(std::string _denumire, int _ore_pe_saptamana, std::string _tip, std::string _cadru_didactic)
{
	this->denumire = _denumire;
	this->ore_pe_saptamana = _ore_pe_saptamana;
	this->tip = _tip;
	this->cadru_didactic = _cadru_didactic;
}

std::string Disciplina::get_denumire() const
{
	std::string _denumire = denumire;
	return _denumire;
}

int Disciplina::get_ore() const noexcept
{
	const int _ore = ore_pe_saptamana;
	return _ore;
}

std::string Disciplina::get_tip() const
{
	std::string _tip = tip;
	return _tip;
}

std::string Disciplina::get_cadru_didactic() const
{
	std::string _cadru_didactic = cadru_didactic;
	return _cadru_didactic;
}

int Disciplina::compare_denumire(const Disciplina& other) const
{
	if (this->get_denumire() > other.get_denumire())
	{
		return 1;
	}
	if (this->get_denumire() == other.get_denumire())
	{
		return 0;
	}
	return -1;
}

int Disciplina::compare_ore(const Disciplina& other) const noexcept
{
	if (this->get_ore() > other.get_ore())
	{
		return 1;
	}
	if (this->get_ore() == other.get_ore())
	{
		return 0;
	}
	return -1;
}

int Disciplina::compare_tip(const Disciplina& other) const
{
	if (this->get_tip() > other.get_tip())
	{
		return 1;
	}
	if (this->get_tip() == other.get_tip())
	{
		return 0;
	}
	return -1;
}

int Disciplina::compare_cadru(const Disciplina& other) const
{
	if (this->get_cadru_didactic() > other.get_cadru_didactic())
	{
		return 1;
	}
	if (this->get_cadru_didactic() == other.get_cadru_didactic())
	{
		return 0;
	}
	return -1;
}

/*
void Disciplina::become(const Disciplina& other)
{
	this->cadru_didactic = other.cadru_didactic;
	this->denumire = other.denumire;
	this->ore_pe_saptamana = other.ore_pe_saptamana;
	this->tip = other.tip;
}
*/

std::string Disciplina::to_string() const
{
	std::string d = denumire;
	std::string t = tip;
	std::string c = cadru_didactic;
	std::replace(d.begin(), d.end(), ' ', '_');
	std::replace(t.begin(), t.end(), ' ', '_');
	std::replace(c.begin(), c.end(), ' ', '_');
	return d + " " + std::to_string(ore_pe_saptamana) + " " + t + " " + c;
}

void test_domain()
{
	Disciplina disc1 = Disciplina();
	Disciplina disc2 = Disciplina("Mate", 5, "Stiinta exacta", "Pop Alin");
	Disciplina disc3 = Disciplina(disc2);
	assert(0 == disc2.compare_denumire(disc3));
}
