#ifndef SERVICE_H
#define SERVICE_H

#include "Contract.h"
#include "Undo.h"

class Service
{
private:
	RepoAbstract& repo;
	Contract contract;
	std::vector<ActiuneUndo*> ListaDeUndo;

	//static Repo default_repo;

public:
	//Service() noexcept;
	/*
		Creates a new Service with empty Repo
	*/

	Service(RepoAbstract& _repo);
	/*
		Creates a new Service with _repo Repo
	*/

	bool service_1(const Disciplina& disc);
	/*
		Adds disc to Repo
		returns true if success
	*/

	bool service_2(const std::string& _denumire);
	/*
		Deletes first Disciplina from Repo with denumire _denumire
		returns true if success
	*/

	bool service_3(const std::string& _denumire, const Disciplina& disc);
	/*
		Deletes first Disciplina from Repo with denumire _denumire
		and Adds disc instead
		returns true if success
	*/

	std::string service_4();
	/*
		Returns a std::string with information of the Repo
	*/

	bool service_5(const std::string& _denumire);
	/*
		returns true if it finds a Disciplina with Denumire _denumire in this->repo
		and false otherwise
	*/

	std::string service_6(int filter_type, int nr_min_ore, int nr_max_ore, std::string cadru_didactic);
	/*
		Returns a std::string with information of the filtered Repo
	*/

	std::string service_7(int criteriu, int ordine);
	/*
		sorts the repo then prints it
	*/

	void service_8() noexcept;
	/*
		clears the contract
	*/

	void service_9(int count);
	/*
		fills the contract with random discipline
	*/

	bool service_10(int index);
	/*
		adds a disciplina to contract
	*/

	void service_11(std::string filePath);
	/*
		backups
	*/

	void service_12();
	/*
		UNDO
	*/

	std::vector<Disciplina> get_list();

	std::map<std::string, int> getNrOfEachType();

	std::string contractString();

	// ~Service();
};

//Repo Service::default_repo;

void test_service();

#endif
