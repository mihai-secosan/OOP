#include "../Header Files/Repo.h"

#include <sstream>
#include <random>

Repo::Repo() noexcept
{
	this->lista_de_discipline.clear();

	this->Comparatori[0][0] = &Repo::comparator_denumire_crescator;
	this->Comparatori[0][1] = &Repo::comparator_denumire_descrescator;
	this->Comparatori[1][0] = &Repo::comparator_ore_crescator;
	this->Comparatori[1][1] = &Repo::comparator_ore_descrescator;
	this->Comparatori[2][0] = &Repo::comparator_tip_crescator;
	this->Comparatori[2][1] = &Repo::comparator_tip_descrescator;
	this->Comparatori[3][0] = &Repo::comparator_cadru_crescator;
	this->Comparatori[3][1] = &Repo::comparator_cadru_descrescator;
}

/*
Repo::Repo(const Repo& _repo)
{
	this->lista_de_discipline.clear();

	this->Comparatori[0][0] = &Repo::comparator_denumire_crescator;
	this->Comparatori[0][1] = &Repo::comparator_denumire_descrescator;
	this->Comparatori[1][0] = &Repo::comparator_ore_crescator;
	this->Comparatori[1][1] = &Repo::comparator_ore_descrescator;
	this->Comparatori[2][0] = &Repo::comparator_tip_crescator;
	this->Comparatori[2][1] = &Repo::comparator_tip_descrescator;
	this->Comparatori[3][0] = &Repo::comparator_cadru_crescator;
	this->Comparatori[3][1] = &Repo::comparator_cadru_descrescator;

	const size_t size = _repo.lista_de_discipline.size();
	for (int i = 0; i < size; i++)
	{
		this->AdaugaDisciplina(_repo.lista_de_discipline.at(i));
	}
}
*/

bool Repo::comparator_denumire_crescator(const Disciplina& disc1, const Disciplina& disc2)
{
	if (disc1.compare_denumire(disc2) > 0)
	{
		return true;
	}
	return false;
}

bool Repo::comparator_denumire_descrescator(const Disciplina& disc1, const Disciplina& disc2)
{
	if (disc1.compare_denumire(disc2) < 0)
	{
		return true;
	}
	return false;
}

bool Repo::comparator_ore_crescator(const Disciplina& disc1, const Disciplina& disc2) noexcept
{
	if (disc1.compare_ore(disc2) > 0)
	{
		return true;
	}
	return false;
}

bool Repo::comparator_ore_descrescator(const Disciplina& disc1, const Disciplina& disc2) noexcept
{
	if (disc1.compare_ore(disc2) < 0)
	{
		return true;
	}
	return false;
}

bool Repo::comparator_tip_crescator(const Disciplina& disc1, const Disciplina& disc2)
{
	if (disc1.compare_tip(disc2) > 0)
	{
		return true;
	}
	return false;
}

bool Repo::comparator_tip_descrescator(const Disciplina& disc1, const Disciplina& disc2)
{
	if (disc1.compare_tip(disc2) < 0)
	{
		return true;
	}
	return false;
}

bool Repo::comparator_cadru_crescator(const Disciplina& disc1, const Disciplina& disc2)
{
	if (disc1.compare_cadru(disc2) > 0)
	{
		return true;
	}
	return false;
}

bool Repo::comparator_cadru_descrescator(const Disciplina& disc1, const Disciplina& disc2)
{
	if (disc1.compare_cadru(disc2) < 0)
	{
		return true;
	}
	return false;
}

bool Repo::AdaugaDisciplina(const Disciplina& disc)
{
	if (this->CautaDisciplina(disc.get_denumire()))
	{
		return false;
	}
	this->lista_de_discipline.push_back(disc);
	return true;
}

Disciplina Repo::at(int i)
{
	return lista_de_discipline.at(i);
}

Disciplina Repo::StergeDisciplina(const std::string& _denumire)
{
	const size_t size = this->lista_de_discipline.size();
	for (int i = 0; i < size; i++)
	{
		if (this->lista_de_discipline.at(i).get_denumire() == _denumire)
		{
			Disciplina disc = this->lista_de_discipline.at(i);
			this->lista_de_discipline.erase(this->lista_de_discipline.begin() + i);
			return disc;
		}
	}
	return Disciplina();
}

bool Repo::CautaDisciplina(const std::string& _denumire)
{
	//const size_t size = this->lista_de_discipline.size();
	auto it = std::find_if(this->lista_de_discipline.begin(), this->lista_de_discipline.end(), [_denumire](const Disciplina& disc) { return disc.get_denumire() == _denumire; });
	if (it != this->lista_de_discipline.end()) {
		return true; // return pointer to found object
	}
	return false;
}

size_t Repo::GetSize() noexcept
{
	return lista_de_discipline.size();
}

/*
void Repo::swap(Disciplina first, Disciplina second)
{
	Disciplina aux = first;
	first = second;
	second = aux;
}
*/

void Repo::sort(int criteriu, int ordine)//FunctionPointer comparator)
{
	bool sorted = false;
	size_t size = this->GetSize();
	//bool (Repo:: * comparatori[4][2])(const Disciplina&, const Disciplina&) = { {&Repo::comparator_denumire_crescator, &Repo::comparator_denumire_descrescator}, {&Repo::comparator_ore_crescator, &Repo::comparator_ore_descrescator}, {&Repo::comparator_tip_crescator, &Repo::comparator_tip_descrescator}, {&Repo::comparator_cadru_crescator, &Repo::comparator_cadru_descrescator}};
	while (!sorted)
	{
		sorted = true;
		size--;
		for (int i = 0; i < size; i++)
		{
			const int j = i + 1;
			bool condition = false;
			if (criteriu == 0 && ordine == 0)
			{
				condition = (this->*Comparatori[0][0])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (criteriu == 0 && ordine == 1)
			{
				condition = (this->*Comparatori[0][1])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (criteriu == 1 && ordine == 0)
			{
				condition = (this->*Comparatori[1][0])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (criteriu == 1 && ordine == 1)
			{
				condition = (this->*Comparatori[1][1])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (criteriu == 2 && ordine == 0)
			{
				condition = (this->*Comparatori[2][0])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (criteriu == 2 && ordine == 1)
			{
				condition = (this->*Comparatori[2][1])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (criteriu == 3 && ordine == 0)
			{
				condition = (this->*Comparatori[3][0])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (criteriu == 3 && ordine == 1)
			{
				condition = (this->*Comparatori[3][1])(this->lista_de_discipline.at(i), this->lista_de_discipline.at(j));
			}
			if (condition)
			{
				//swap(this->lista_de_discipline.at(i), this->lista_de_discipline.at(i + 1));

				std::iter_swap(this->lista_de_discipline.begin() + i, this->lista_de_discipline.begin() + i + 1);

				sorted = false;
			}
		}
	}
}

std::string Repo::to_string()
{
	std::string str = "";

	const size_t size = this->GetSize();
	for (int i = 0; i < size; i ++)
	{
		str += std::to_string(i + 1) + "). " + lista_de_discipline.at(i).to_string() + "\n";
	}
	return str;
}

std::string Repo::filter(int filter_type, int nr_min_ore, int nr_max_ore, std::string cadru_didactic)
{
	std::string str = "";

	//const size_t size = this->GetSize();
	int i = 1;
	for (Disciplina disc : this->lista_de_discipline)
	{
		if (filter_type == 1 && (disc.get_ore() > nr_max_ore || disc.get_ore() < nr_min_ore))
		{
			continue;
		}
		if (filter_type == 2 && disc.get_cadru_didactic() != cadru_didactic)
		{
			continue;
		}
		str += std::to_string(i) + "). " + disc.to_string() + "\n";
		i++;
	}
	return str;
}

std::map<std::string, int> Repo::getNrOfEachType()
{
	std::map<std::string, int> nrOfEachType;
	for (Disciplina disc : lista_de_discipline)
	{
		if (nrOfEachType.count(disc.get_tip()) == 0)
		{
			nrOfEachType[disc.get_tip()] = 1;
		}
		else
		{
			nrOfEachType[disc.get_tip()]++;
		}
	}
	return nrOfEachType;
}


void RepoFisier::backup(std::string filePath)
{
	std::ofstream f(filePath);
	f << to_string();
	f.close();
}

void RepoFisier::revert_from_backup(std::string filePath)
{
	lista_de_discipline.clear();
	std::ifstream f(filePath);

	std::string line;

	while (std::getline(f, line))
	{
		std::istringstream iss(line);
		std::string ignore, word1, word2, word3;
		int number;

		iss >> ignore >> word1 >> number >> word2 >> word3;

		std::replace(word1.begin(), word1.end(), '_', ' ');
		std::replace(word2.begin(), word2.end(), '_', ' ');
		std::replace(word3.begin(), word3.end(), '_', ' ');

		AdaugaDisciplina(Disciplina(word1, number, word2, word3));
	}

	f.close();
}

bool RepoFisier::AdaugaDisciplina(const Disciplina& disc)
{
	if (this->CautaDisciplina(disc.get_denumire()))
	{
		return false;
	}
	this->lista_de_discipline.push_back(disc);
	std::string filePath = "../Resource Files/Repo.txt";
	backup(filePath);
	return true;
}

Disciplina RepoFisier::StergeDisciplina(const std::string& _denumire)
{
	const size_t size = this->lista_de_discipline.size();
	for (int i = 0; i < size; i++)
	{
		if (this->lista_de_discipline.at(i).get_denumire() == _denumire)
		{
			Disciplina disc = this->lista_de_discipline.at(i);
			this->lista_de_discipline.erase(this->lista_de_discipline.begin() + i);
			std::string filePath = "../Resource Files/Repo.txt";
			backup(filePath);
			return disc;
		}
	}
	return Disciplina();
}


RepoLab::RepoLab(double exeption_probability)
{
	ExeptionProbability = exeption_probability;
}

double getRandomFloat() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 1.0);
	return dis(gen);
}

bool RepoLab::AdaugaDisciplina(const Disciplina& disc)
{
	if (getRandomFloat() < ExeptionProbability)
	{
		throw DontWorryItIsJustAnExeption("RepoLab threw exeption during AdaugaDisciplina\n");
	}
	if (CautaDisciplina(disc.get_denumire()))
	{
		return false;
	}
	catalog.insert(std::make_pair(disc.get_denumire(), disc));
	return true;
}

Disciplina RepoLab::at(int i)
{
	for (auto& pair : catalog)
	{
		if (i == 0)
		{
			return pair.second;
		}
		i--;
	}
	return Disciplina();
}

Disciplina RepoLab::StergeDisciplina(const std::string& _denumire)
{
	if (getRandomFloat() < ExeptionProbability)
	{
		throw DontWorryItIsJustAnExeption("RepoLab threw exeption during StergeDisciplina\n");
	}
	auto it = catalog.find(_denumire);
	if (it != catalog.end()) 
	{
		Disciplina value = it->second;
		catalog.erase(it);
		return value;
	}
	return Disciplina();
}

bool RepoLab::CautaDisciplina(const std::string& _denumire)
{
	std::map<std::string, Disciplina>::iterator it = catalog.find(_denumire);
	return it != catalog.end();
}

size_t RepoLab::GetSize() noexcept
{
	return catalog.size();
}

void RepoLab::sort(int criteriu, int ordine) noexcept
{
	// E map, frate, e deja sortat
	int carapace = criteriu + ordine;
	carapace++;
}

std::string RepoLab::to_string()
{
	std::string str = "";

	int i = 1;
	for (auto& pair : catalog)
	{
		str += std::to_string(i) + "). " + pair.second.to_string() + "\n";
		i ++;
	}
	return str;
}

std::string RepoLab::filter(int filter_type, int nr_min_ore, int nr_max_ore, std::string cadru_didactic)
{
	std::string str = "";

	//const size_t size = this->GetSize();
	int i = 1;
	for (auto& pair : catalog)
	{
		Disciplina disc = pair.second;
		if (filter_type == 1 && (disc.get_ore() > nr_max_ore || disc.get_ore() < nr_min_ore))
		{
			continue;
		}
		if (filter_type == 2 && disc.get_cadru_didactic() != cadru_didactic)
		{
			continue;
		}
		str += std::to_string(i) + "). " + disc.to_string() + "\n";
		i++;
	}
	return str;
}

std::map<std::string, int> RepoLab::getNrOfEachType()
{
	std::map<std::string, int> nrOfEachType;
	for (auto& pair : catalog)
	{
		Disciplina disc = pair.second;
		if (nrOfEachType.count(disc.get_tip()) == 0)
		{
			nrOfEachType[disc.get_tip()] = 1;
		}
		else
		{
			nrOfEachType[disc.get_tip()]++;
		}
	}
	return nrOfEachType;
}



void test_repo()
{
	Repo repo1 = Repo();
	Disciplina disc1 = Disciplina("Fizica", 3, "Stiinta", "Negrea Gabriel");
	repo1.AdaugaDisciplina(disc1);
	//Repo repo2 = Repo(repo1);
	assert(repo1.GetSize() == 1);
	//assert(repo2.GetSize() == 1);
	assert(repo1.StergeDisciplina("Mate").get_denumire() != "Mate");
	Disciplina disc2 = repo1.at(0);

	RepoFisier repo_f = RepoFisier();
	repo_f.AdaugaDisciplina(disc1);
	repo_f.AdaugaDisciplina(disc2);
	repo_f.StergeDisciplina("Mate");
	repo_f.StergeDisciplina("Fizica");

	RepoLab repo_l = RepoLab(0);
	Disciplina disc3 = Disciplina("mate", 6, "stiinte", "Pop");
	repo_l.AdaugaDisciplina(disc1);
	repo_l.AdaugaDisciplina(disc2);
	repo_l.AdaugaDisciplina(disc3);
	assert(repo_l.GetSize() == 2);
	repo_l.StergeDisciplina("Biologie");
	Disciplina disc4 = repo_l.at(2);
	repo_l.StergeDisciplina("mate");
	repo_l.sort(2, 6);
	repo_l.AdaugaDisciplina(disc3);
	Disciplina disc5 = Disciplina("Romana", 1, "limba", "Pop");
	repo_l.AdaugaDisciplina(disc5);
	std::string strLab = repo_l.to_string();
	strLab = repo_l.filter(1, 2, 7, "pastarnac");
	strLab = repo_l.filter(2, 0, 0, "Pop");
	disc2 = repo_l.at(2);
	std::map<std::string, int> matale = repo_l.getNrOfEachType();

	RepoLab repo_l_5 = RepoLab(0.5);
	bool except = false, noexception = false;
	while (!except || !noexception)
	{
		try
		{
			repo_l_5.AdaugaDisciplina(disc1);
			noexception = true;
		}
		catch (const std::exception& e)
		{
			std::string exc = e.what();
			except = true;
		}
	}
	except = false, noexception = false;
	while (!except || !noexception)
	{
		try
		{
			repo_l_5.StergeDisciplina(disc1.get_denumire());
			noexception = true;
		}
		catch (const std::exception& e)
		{
			std::string exc = e.what();
			except = true;
		}
	}
	
}
