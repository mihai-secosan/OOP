#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Service.h"

#include <utility>

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QComboBox>
#include <QDialog>
#include <QMessageBox>
#include <QListWidget>

class AdaugareDialog : public QDialog
{
    Q_OBJECT

public:
    AdaugareDialog(QWidget* parent = nullptr);

    Disciplina getDisciplina() const;

private:
    QLineEdit* denumire;
    QLineEdit* numarOre;
    QLineEdit* tip;
    QLineEdit* cadruDidactic;
};

class FiltrareCadruDidacticDialog : public QDialog
{
    Q_OBJECT

public:
    FiltrareCadruDidacticDialog(QWidget* parent = nullptr);

    std::string getCadruDidactic() const;

private:
    QLineEdit* cadruDidactic;
};

class FiltrareNumarOreDialog : public QDialog
{
    Q_OBJECT

public:
    FiltrareNumarOreDialog(QWidget* parent = nullptr);

    std::pair<int, int> getMinMax() const;

private:
    QLineEdit* minim;
    QLineEdit* maxim;
};

class stdStringDialog : public QDialog
{
    Q_OBJECT

public:
    stdStringDialog(QString message, QWidget* parent = nullptr);

    std::string getValue() const;

private:
    QLineEdit* value;
};


class CosGUI : public QMainWindow
{
private:
    Service& service;
public:
    CosGUI(Service& _service, QWidget* parent = nullptr);
    virtual void Update() = 0;
};

class CosCRUDGUI : public CosGUI
{
private:
    QListWidget* ContractItems;

public:
    CosCRUDGUI(Service& _service, QWidget* parent = nullptr);
    void Update() override;

private slots:
    void golire();
    void generare();
};

class CosReadOnlyGUI : public CosGUI
{
private:

public:
    CosReadOnlyGUI(Service& _service, QWidget* parent = nullptr);
    void Update() override;

private slots:
    
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Service& service;

    //QListWidget* RepoList;
    QTableWidget* RepoTable;
    QLineEdit* SearchBar;
    QVBoxLayout* ButoaneCategoriiLayout;
    QComboBox* SortareDropMenu;
    QPushButton* ReverseOrderButton;

    std::vector<CosGUI*> observers;

    void refresh();
    void refreshRepoTable(std::vector<Disciplina>& listaDiscipline);
    void refreshCategoryButtonsLayout();

public:
    explicit MainWindow(Service& _service, QWidget* parent = nullptr);
    void UpdateContractWindows();

private slots:
    void adaugaDisciplina();
    void stergeDisciplina();
    void modificaDisciplina();
    void cautaDisciplina();
    void filtrareOreSaptamana();
    void filtrareCadruDidactic();
    void sortare();
    void schimbaDirectiaSortarii();
    void golireContract();
    void adaugareInContract();
    void populareContract();
    void exportContract();
    void afisareContract();
    void undo();
    void showNumberOfItemsInCategory();

};

#endif
