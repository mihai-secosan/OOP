#ifndef CONTRACT_H
#define CONTRACT_H

#include "Repo.h"

class Contract
{
private:
	std::string FilePath;
	std::vector<std::string> Lista;
public:
	Contract();
	Contract(std::string file);
	void Clear() noexcept;
	void Add(std::string denumire);
	void Populate(RepoAbstract& repo, int count);
	void Export();
	void Export(std::string file);
	std::string to_string();
};

void test_contract();

#endif
