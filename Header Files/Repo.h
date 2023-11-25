#ifndef REPO_H
#define REPO_H

#include "Domain.h"

#include <map>

class RepoAbstract
{
private:

public:
	virtual bool AdaugaDisciplina(const Disciplina& disc) = 0;
	virtual Disciplina at(int i) = 0;
	virtual Disciplina StergeDisciplina(const std::string& _denumire) = 0;
	virtual bool CautaDisciplina(const std::string& _denumire) = 0;
	virtual size_t GetSize() noexcept = 0;
	virtual void sort(int criteriu, int ordine) = 0;
	virtual std::string to_string() = 0;
	virtual std::string filter(int filter_type, int nr_min_ore, int nr_max_ore, std::string cadru_didactic) = 0;
	virtual std::map<std::string, int> getNrOfEachType() = 0;
};

class Repo : public RepoAbstract
{
protected:
	std::vector<Disciplina> lista_de_discipline;

	bool comparator_denumire_crescator(const Disciplina& disc1, const Disciplina& disc2);
	/*
		returns true if disc1.denumire > disc2.denumire
	*/

	bool comparator_denumire_descrescator(const Disciplina& disc1, const Disciplina& disc2);
	/*
		returns false if disc1.denumire > disc2.denumire
	*/

	bool comparator_ore_crescator(const Disciplina& disc1, const Disciplina& disc2) noexcept;
	/*
		returns true if disc1.ore > disc2.ore
	*/

	bool comparator_ore_descrescator(const Disciplina& disc1, const Disciplina& disc2) noexcept;
	/*
		returns false if disc1.ore > disc2.ore
	*/

	bool comparator_tip_crescator(const Disciplina& disc1, const Disciplina& disc2);
	/*
		returns true if disc1.tip > disc2.tip
	*/

	bool comparator_tip_descrescator(const Disciplina& disc1, const Disciplina& disc2);
	/*
		returns false if disc1.tip > disc2.tip
	*/

	bool comparator_cadru_crescator(const Disciplina& disc1, const Disciplina& disc2);
	/*
		returns true if disc1.cadru > disc2.cadru
	*/

	bool comparator_cadru_descrescator(const Disciplina& disc1, const Disciplina& disc2);
	/*
		returns false if disc1.cadru > disc2.cadru
	*/

	//void swap(Disciplina first, Disciplina second);
	/*
		swaps the 2
	*/

public:
	using FunctionPointer = bool (Repo::*)(const Disciplina&, const Disciplina&);
	FunctionPointer Comparatori[4][2];

	Repo() noexcept;
	/*
		Creates a new empty Repo
	*/

	// Repo(const Repo& _repo);
	/*
		Creates a copy of _repo
	*/

	virtual bool AdaugaDisciplina(const Disciplina& disc) override;
	/*
		Adds disc to Repo
		returns true if success
	*/

	Disciplina at(int i) override;
	/*
	
	*/

	virtual Disciplina StergeDisciplina(const std::string& _denumire) override;
	/*
		Deletes first Disciplina from Repo with denumire _denumire
		returns true if success
	*/

	bool CautaDisciplina(const std::string& _denumire) override;
	/*
		returns true if it finds _denumire 
	*/

	size_t GetSize() noexcept override;
	/*
		Returns the amount of Disciplina from this
	*/

	void sort(int criteriu, int ordine) override;// FunctionPointer comparator);
	/*
		sorts the repo using the function givven as paramater
		bubble sort
	*/

	std::string to_string() override;
	/*
		Returns a std::string with information of this
	*/

	std::string filter(int filter_type, int nr_min_ore, int nr_max_ore, std::string cadru_didactic) override;
	/*
		returns a std::String of the filtered repo
	*/

	std::map<std::string, int> getNrOfEachType() override;
};

class RepoFisier : public Repo
{
private:

public:
	bool AdaugaDisciplina(const Disciplina& disc) override;
	Disciplina StergeDisciplina(const std::string& _denumire) override;
	void backup(std::string filePath);
	void revert_from_backup(std::string filePath);
};

class RepoLab : public RepoAbstract
{
private:
	std::map<std::string, Disciplina> catalog;
	double ExeptionProbability;
public:
	RepoLab(double exeption_probability);
	bool AdaugaDisciplina(const Disciplina& disc) override;
	Disciplina at(int i) override;
	Disciplina StergeDisciplina(const std::string& _denumire) override;
	bool CautaDisciplina(const std::string& _denumire) override;
	size_t GetSize() noexcept override;
	void sort(int criteriu, int ordine) noexcept override;
	std::string to_string() override;
	std::string filter(int filter_type, int nr_min_ore, int nr_max_ore, std::string cadru_didactic) override;
	std::map<std::string, int> getNrOfEachType() override;
};

void test_repo();

#endif
