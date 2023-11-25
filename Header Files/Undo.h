#ifndef UNDO_H
#define UNDO_H

#include "Repo.h"

class ActiuneUndo
{
public:
	//ActiuneUndo();
	virtual void doUndo(RepoAbstract& repo) = 0;
	//~ActiuneUndo();
};

class UndoAdauga : public ActiuneUndo
{
private:
	std::string Denumire;
public:
	//UndoAdauga();
	UndoAdauga(std::string denumire);
	void doUndo(RepoAbstract& repo) override;
	//~UndoAdauga();
};

class UndoSterge : public ActiuneUndo
{
private:
	Disciplina Disc;
public:
	//UndoSterge();
	UndoSterge(Disciplina disc);
	void doUndo(RepoAbstract& repo) override;
	//~UndoSterge();
};

class UndoModifica : public ActiuneUndo
{
private:
	std::string Denumire;
	Disciplina Disc;
public:
	//UndoModifica();
	UndoModifica(std::string denumire, Disciplina disc);
	void doUndo(RepoAbstract& repo) override;
	//~UndoModifica();
};

void test_undo();

#endif
