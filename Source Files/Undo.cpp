#include "../Header Files/Undo.h"



/*
ActiuneUndo::ActiuneUndo()
{

}
*/

/*
void ActiuneUndo::doUndo(Repo& repo)
{
	const int size = repo.GetSize();
}
*/

/*
ActiuneUndo::~ActiuneUndo()
{

}
*/



/*
UndoAdauga::UndoAdauga()
{
	Denumire.clear();
}
*/

UndoAdauga::UndoAdauga(std::string denumire)
{
	Denumire = denumire;
}

void UndoAdauga::doUndo(RepoAbstract& repo)
{
	repo.StergeDisciplina(Denumire);
}

/*
UndoAdauga::~UndoAdauga()
{

}
*/



/*
UndoSterge::UndoSterge()
{
	Disc = Disciplina();
}
*/

UndoSterge::UndoSterge(Disciplina disc)
{
	Disc = disc;
}

void UndoSterge::doUndo(RepoAbstract& repo)
{
	repo.AdaugaDisciplina(Disc);
}

/*
UndoSterge::~UndoSterge()
{

}
*/



/*
UndoModifica::UndoModifica()
{
	Denumire.clear();
	Disc = Disciplina();
}
*/

UndoModifica::UndoModifica(std::string denumire, Disciplina disc)
{
	Denumire = denumire;
	Disc = disc;
}

void UndoModifica::doUndo(RepoAbstract& repo)
{
	repo.StergeDisciplina(Denumire);
	repo.AdaugaDisciplina(Disc);
}

/*
UndoModifica::~UndoModifica()
{

}
*/

void test_undo()
{
	/*
	ActiuneUndo act = ActiuneUndo();
	Repo repo = Repo();
	act.doUndo(repo);
	*/
}
