#include "Header Files/MainWindow.h"

#include <iostream>
#include <cstdlib>

#include <QApplication>

void test_all()
{
	test_domain();
	std::cout << "Domain		test ran successfully!\n";

	test_repo();
	std::cout << "Repo		test ran successfully!\n";

	test_contract();
	system("CLS");
	std::cout << "Domain		test ran successfully!\n";
	std::cout << "Repo		test ran successfully!\n";
	std::cout << "Contract	test ran successfully!\n";

	test_service();
	std::cout << "Service		test ran successfully!\n";

	test_undo();
	std::cout << "Undo		test ran successfully!\n";

	test_exeptions();
	std::cout << "Exeption	test ran successfully!\n";

	std::cout << "\n";

	// system("CLS");
}

void init_Repo(Repo& repo)
{
	repo.AdaugaDisciplina(Disciplina("Matematica", 6, "Stiinta", "Pop Alin Radu Bujor"));
	repo.AdaugaDisciplina(Disciplina("Fizica", 3, "Stiinta", "Negrea Gabriel"));
	repo.AdaugaDisciplina(Disciplina("Educatie Fizica si Sport", 1, "Sport", "Masca Daniel"));
	repo.AdaugaDisciplina(Disciplina("Engleza", 2, "Limba", "Masca Daniel"));
	repo.AdaugaDisciplina(Disciplina("Limba si Literatura Romana", 3, "Limba", "Otoiu Carmen"));
	repo.AdaugaDisciplina(Disciplina("Informatica", 5, "Informatica", "Popescu Carmen"));
}
void init_RepoLab(RepoLab& repo)
{
	while (true)
	{
		try
		{
			repo.AdaugaDisciplina(Disciplina("Matematica", 6, "Stiinta", "Pop Alin Radu Bujor"));
			break;
		}
		catch (std::exception e) {}
	}
	while (true)
	{
		try
		{
			repo.AdaugaDisciplina(Disciplina("Fizica", 3, "Stiinta", "Negrea Gabriel"));
			break;
		}
		catch (std::exception e) {}
	}
	while (true)
	{
		try
		{
			repo.AdaugaDisciplina(Disciplina("Educatie Fizica si Sport", 1, "Sport", "Masca Daniel"));
			break;
		}
		catch (std::exception e) {}
	}
	while (true)
	{
		try
		{
			repo.AdaugaDisciplina(Disciplina("Engleza", 2, "Limba", "Masca Daniel"));
			break;
		}
		catch (std::exception e) {}
	}
	while (true)
	{
		try
		{
			repo.AdaugaDisciplina(Disciplina("Limba si Literatura Romana", 3, "Limba", "Otoiu Carmen"));
			break;
		}
		catch (std::exception e) {}
	}
	while (true)
	{
		try
		{
			repo.AdaugaDisciplina(Disciplina("Informatica", 5, "Informatica", "Popescu Carmen"));
			break;
		}
		catch (std::exception e) {}
	}
}
void init_RepoFisier(RepoFisier& repo)
{
	repo.revert_from_backup("Resource Files/StartingRepo.txt");
	repo.backup("Resource Files/Repo.txt");
}

int main(int argc, char* argv[])
{
	test_all();

	Repo repo = Repo();
	init_Repo(repo);
	RepoLab repoLab = RepoLab(0.95);
	init_RepoLab(repoLab);
	RepoFisier repoFisier = RepoFisier();
	init_RepoFisier(repoFisier);

	Service service = Service(repoFisier);

    QApplication app(argc, argv);

	MainWindow mainWindow(service);
	mainWindow.show();

    return app.exec();
}
