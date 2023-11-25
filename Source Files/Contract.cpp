#include "../Header Files/Contract.h"

#include <random>

Contract::Contract()
{
	Clear();
	FilePath = "../Resource Files/Contract.txt";
}

Contract::Contract(std::string file)
{
	Clear();
	FilePath = file;
}

void Contract::Clear() noexcept
{
	Lista.clear();
}

void Contract::Add(std::string denumire)
{
	for (std::string den : Lista)
	{
		if (den == denumire)
		{
			throw ItemAlreadyExists("Disciplina aceasta deja exista in contract!\n");
		}
	}
	Lista.push_back(denumire);
}

int getRandomNr(int minVal, int maxVal) noexcept
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const int randomNumber = rand() % (maxVal - minVal + 1) + minVal;

	return randomNumber;
}

void Contract::Populate(RepoAbstract& repo, int count)
{
	Clear();
	for (int i = 0; i < repo.GetSize(); i++)
	{
		Lista.push_back(repo.at(i).get_denumire());
	}
	if (count < 0)
	{
		count = 0;
	}
	while (Lista.size() > count)
	{
		const int rng = getRandomNr(0, static_cast<int>(Lista.size() - 1));
		Lista.erase(Lista.begin() + rng);
	}
}

void clearFile(const std::string& filePath)
{
	if (filePath == "stdout")
	{
		return;
	}
	std::ofstream file(filePath, std::ios::trunc);
	file.close();
}

void Contract::Export()
{
	Export(FilePath);
}

void Contract::Export(std::string file)
{
	if (file == "stdout")
	{
		for (std::string denumire : Lista)
		{
			std::cout << denumire << "\n";
		}
		return;
	}
	clearFile(file);
	std::ofstream fout(file);
	for (std::string denumire : Lista)
	{
		fout << denumire << "\n";
		// std::cout << "AM AFISAT CEVA IN FISIER!!!\n";
	}
}

std::string Contract::to_string()
{
	std::string str = "";
	for (std::string denumire : Lista)
	{
		str += denumire + "\n";
	}
	return str;
}

void test_contract()
{
	Contract contract = Contract("../Resource Files/Contract.txt");
	contract.Add("mate");
	contract.Add("fizica");
	try
	{
		contract.Add("mate");
	}
	catch (const std::exception& e)
	{
		const std::string msg = e.what();
	}
	clearFile("stdout");
	contract.Export();
	(void)contract.to_string();
	contract.Export("../Resource Files/Contract.txt");
	contract.Export("stdout");
	clearFile("../Resource Files/Contract.txt");
	int rng = getRandomNr(0, 9);
	rng = getRandomNr(rng, 9);
	assert(rng >= 0 && rng <= 9);
}
