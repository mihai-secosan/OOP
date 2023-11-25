#include "../Header Files/Service.h"

/*
Service::Service() noexcept : repo(default_repo)
{
	//this->repo = *new Repo();
	this->contract = Contract();
}
*/

Service::Service(RepoAbstract& _repo) : repo(_repo)
{
	//this->repo = _repo;
	this->contract = Contract();
}

bool Service::service_1(const Disciplina& disc)
{
	ActiuneUndo* act = new UndoAdauga(disc.get_denumire());
	ListaDeUndo.push_back(act);
	return this->repo.AdaugaDisciplina(disc);
}

bool Service::service_2(const std::string& _denumire)
{
	ActiuneUndo* act = new UndoSterge(this->repo.StergeDisciplina(_denumire));
	ListaDeUndo.push_back(act);
	return true;
}

bool Service::service_3(const std::string& _denumire, const Disciplina& disc)
{
	Disciplina disciplina = this->repo.StergeDisciplina(_denumire);
	ActiuneUndo* act = new UndoModifica(disc.get_denumire(), disciplina);
	if (!this->repo.AdaugaDisciplina(disc))
	{
		this->repo.AdaugaDisciplina(disciplina);
		//delete[] act;
		return false;
	}
	ListaDeUndo.push_back(act);
	return true;
}

std::string Service::service_4()
{
	return this->repo.to_string();
}

bool Service::service_5(const std::string& _denumire)
{
	return this->repo.CautaDisciplina(_denumire);
}

std::string Service::service_6(int filter_type, int nr_min_ore, int nr_max_ore, std::string cadru_didactic)
{
	return this->repo.filter(filter_type, nr_min_ore, nr_max_ore, cadru_didactic);
}

std::string Service::service_7(int criteriu, int ordine)
{
	//repo.sort(repo.Comparatori[criteriu][ordine]);
	repo.sort(criteriu, ordine);
	return this->service_4();
}

void Service::service_8() noexcept
{
	contract.Clear();
}

void Service::service_9(int count)
{
	contract.Populate(this->repo, count);
}

bool Service::service_10(int index)
{
	if (index > repo.GetSize())
	{
		return false;
	}
	contract.Add(repo.at(index - 1).get_denumire());
	return true;
}

void Service::service_11(std::string filePath)
{
	contract.Export(filePath);
}

void Service::service_12()
{
	if (ListaDeUndo.size() == 0)
	{
		return;
	}

	ActiuneUndo* act = ListaDeUndo.at(ListaDeUndo.size() - 1);
	ListaDeUndo.pop_back();

	act->doUndo(this->repo);

	//delete[] act;
}

std::vector<Disciplina> Service::get_list()
{
	std::vector<Disciplina> lista;
	size_t n = repo.GetSize();
	for (int i = 0; i < n; i++)
	{
		lista.push_back(repo.at(i));
	}
	return lista;
}

std::map<std::string, int> Service::getNrOfEachType()
{
	return repo.getNrOfEachType();
}

std::string Service::contractString()
{
	return contract.to_string();
}

/*
Service::~Service()
{
	for (ActiuneUndo* act : ListaDeUndo)
	{
		//delete[] act;
	}
}
*/

void test_service()
{
	//Service service_default = Service();
	Repo repo = Repo();
	Service service = Service(repo);
	assert(service.service_1(Disciplina("Matematica", 5, "Stiinte", "Pop Alin")));
	assert(service.service_1(Disciplina("Fizica", 3, "Stiinte", "Negrea Gabriel")));
	assert(service.service_3("Fizica", Disciplina("Fizica", 4, "Stiinte", "Negrea")));
	assert(!service.service_3("Fizica", Disciplina("Matematica", 4, "Stiinte", "Negrea")));
	assert(service.service_5("Fizica"));
	assert(!service.service_5("Bio"));
	assert(!service.service_1(Disciplina("Matematica", 5, "Stiinte", "Pop Alin")));
	assert(service.service_1(Disciplina("Bio", 2, "Stiinte", "Sandulescu")));
	assert(service.service_1(Disciplina("Sport", 1, "Sport", "Masca Daniel")));
	assert(service.service_1(Disciplina("Chimie", 2, "Stiinte", "Sandulescu")));
	assert(service.service_1(Disciplina("Romana", 3, "Literatura", "Otoiu")));
	assert(service.service_1(Disciplina("Info", 6, "Info", "Oancea")));
	(void)service.service_6(1, 5, 6, "De ce citesti testele, huh?");
	(void)service.service_6(2, 0, 0, "Negrea");
	(void)service.service_7(0, 0);
	(void)service.service_7(1, 0);
	(void)service.service_7(2, 0);
	(void)service.service_7(3, 0);
	(void)service.service_7(0, 1);
	(void)service.service_7(1, 1);
	(void)service.service_7(2, 1);
	(void)service.service_7(3, 1);
	(void)service.service_4();

	std::map<std::string, int> matale = service.getNrOfEachType();

	assert(service.service_2("Bio"));

	service.service_9(2);
	service.service_8();
	service.service_9(-2);
	service.service_8();
	service.service_10(1);
	service.service_10(20);
	service.service_11("../Resource Files/Contract.txt");
	(void)service.contractString();

	for (int i = 0; i < 20; i++)
	{
		service.service_12();
	}
}
