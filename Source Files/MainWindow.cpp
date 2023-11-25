#include "../Header Files/MainWindow.h"


QHBoxLayout* make_pair(QWidget* first, QWidget* second)
{
    QHBoxLayout* qhbl = new QHBoxLayout;
    qhbl->addWidget(first);
    qhbl->addWidget(second);
    return qhbl;
}


AdaugareDialog::AdaugareDialog(QWidget* parent) : QDialog(parent)
{
    QLineEdit* denumire_ = new QLineEdit(this);
    denumire_->setText("Denumire");
    denumire_->setReadOnly(true);
    QLineEdit* numarOre_ = new QLineEdit(this);
    numarOre_->setText("Nr. Ore");
    numarOre_->setReadOnly(true);
    QLineEdit* tip_ = new QLineEdit(this);
    tip_->setText("Tip");
    tip_->setReadOnly(true);
    QLineEdit* cadruDidactic_ = new QLineEdit(this);
    cadruDidactic_->setText("Cadru Didactic");
    cadruDidactic_->setReadOnly(true);
    denumire = new QLineEdit(this);
    numarOre = new QLineEdit(this);
    tip = new QLineEdit(this);
    cadruDidactic = new QLineEdit(this);
    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    connect(okButton, &QPushButton::clicked, this, &AdaugareDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AdaugareDialog::reject);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(make_pair(denumire_, denumire));
    layout->addLayout(make_pair(numarOre_, numarOre));
    layout->addLayout(make_pair(tip_, tip));
    layout->addLayout(make_pair(cadruDidactic_, cadruDidactic));
    layout->addLayout(make_pair(okButton, cancelButton));

    setLayout(layout);
}

Disciplina AdaugareDialog::getDisciplina() const
{
    if (denumire->text().isEmpty() || numarOre->text().isEmpty() || tip->text().isEmpty() || cadruDidactic->text().isEmpty())
    {
        return Disciplina();
    }
    std::string denum = denumire->text().toStdString();
    int nrO = std::stoi(numarOre->text().toStdString());
    std::string tp = tip->text().toStdString();
    std::string cdrDid = cadruDidactic->text().toStdString();
    return Disciplina(denum, nrO, tp, cdrDid);
}


FiltrareCadruDidacticDialog::FiltrareCadruDidacticDialog(QWidget* parent) : QDialog(parent)
{
    QLineEdit* cadruDidactic_ = new QLineEdit(this);
    cadruDidactic_->setText("Cadru Didactic");
    cadruDidactic_->setReadOnly(true);
    cadruDidactic = new QLineEdit(this);
    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    connect(okButton, &QPushButton::clicked, this, &AdaugareDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AdaugareDialog::reject);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(make_pair(cadruDidactic_, cadruDidactic));
    layout->addLayout(make_pair(okButton, cancelButton));

    setLayout(layout);
}

std::string FiltrareCadruDidacticDialog::getCadruDidactic() const
{
    return cadruDidactic->text().toStdString();
}


FiltrareNumarOreDialog::FiltrareNumarOreDialog(QWidget* parent) : QDialog(parent)
{
    QLineEdit* minim_ = new QLineEdit(this);
    minim_->setText("minim");
    minim_->setReadOnly(true);
    QLineEdit* maxim_ = new QLineEdit(this);
    maxim_->setText("maxim");
    maxim_->setReadOnly(true);
    minim = new QLineEdit(this);
    maxim = new QLineEdit(this);
    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    connect(okButton, &QPushButton::clicked, this, &AdaugareDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AdaugareDialog::reject);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(make_pair(minim_, minim));
    layout->addLayout(make_pair(maxim_, maxim));
    layout->addLayout(make_pair(okButton, cancelButton));

    setLayout(layout);
}

std::pair<int, int> FiltrareNumarOreDialog::getMinMax() const
{
    int _min = std::stoi(minim->text().toStdString());
    int _max = std::stoi(maxim->text().toStdString());
    return std::pair<int, int>(_min, _max);
}


stdStringDialog::stdStringDialog(QString message, QWidget* parent) : QDialog(parent)
{
    QLineEdit* value_ = new QLineEdit(this);
    value_->setText(message);
    value_->setReadOnly(true);
    value = new QLineEdit(this);
    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    connect(okButton, &QPushButton::clicked, this, &AdaugareDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AdaugareDialog::reject);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(make_pair(value_, value));
    layout->addLayout(make_pair(okButton, cancelButton));

    setLayout(layout);
}

std::string stdStringDialog::getValue() const
{
    return value->text().toStdString();
}


CosGUI::CosGUI(Service& _service, QWidget* parent) : QMainWindow(parent), service(_service)
{

}

CosCRUDGUI::CosCRUDGUI(Service& _service, QWidget* parent) : CosGUI(_service, parent)
{
    QPushButton* golireButton = new QPushButton;
    connect(golireButton, &QPushButton::clicked, this, &CosCRUDGUI::golire);
    QPushButton* generareButton = new QPushButton;
    connect(generareButton, &QPushButton::clicked, this, &CosCRUDGUI::generare);

    QVBoxLayout* ListLayout = new QVBoxLayout;
    ContractItems = new QListWidget;
    ListLayout->addWidget(ContractItems);

    QHBoxLayout* ButtonLayout = new QHBoxLayout;
    ButtonLayout->addWidget(golireButton);
    ButtonLayout->addWidget(generareButton);

    QVBoxLayout* WindowLayout = new QVBoxLayout;
    WindowLayout->addLayout(ListLayout);
    WindowLayout->addLayout(ButtonLayout);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(WindowLayout);
    setCentralWidget(centralWidget);

    Update();
}

void CosCRUDGUI::Update()
{

}

void CosCRUDGUI::golire()
{

}

void CosCRUDGUI::generare()
{

}

CosReadOnlyGUI::CosReadOnlyGUI(Service& _service, QWidget* parent) : CosGUI(_service, parent)
{

}

void CosReadOnlyGUI::Update()
{

}


MainWindow::MainWindow(Service& _service, QWidget* parent) : QMainWindow(parent), service(_service)
{
    RepoTable = new QTableWidget(this);
    //RepoList = new QListWidget(this);
    QVBoxLayout* RepoLayout = new QVBoxLayout;
    RepoLayout->addWidget(RepoTable);
    //RepoLayout->addWidget(RepoList);

    QPushButton* AdaugareButton = new QPushButton("Adaugare", this);
    connect(AdaugareButton, &QPushButton::clicked, this, &MainWindow::adaugaDisciplina);
    QVBoxLayout* AdaugareLayout = new QVBoxLayout;
    AdaugareLayout->addWidget(AdaugareButton);

    QLineEdit* CautareLineEdit = new QLineEdit;
    CautareLineEdit->setText("Cautare");
    CautareLineEdit->setReadOnly(true);
    SearchBar = new QLineEdit;
    connect(SearchBar, &QLineEdit::returnPressed, this, &MainWindow::cautaDisciplina);
    QPushButton* CautareResetareButton = new QPushButton("X", this);
    connect(CautareResetareButton, &QPushButton::clicked, [=]() { SearchBar->clear(); });
    QHBoxLayout* CautareLayout = new QHBoxLayout;
    CautareLayout->addWidget(CautareLineEdit);
    CautareLayout->addWidget(SearchBar);
    CautareLayout->addWidget(CautareResetareButton);

    QPushButton* FiltrareCadruDidacticButton = new QPushButton("Filtrare dupa\nCadru Didactic", this);
    connect(FiltrareCadruDidacticButton, &QPushButton::clicked, this, &MainWindow::filtrareCadruDidactic);
    QPushButton* FiltrareOrePeSaptamanaButton = new QPushButton("Filtrare dupa\nNr. Ore/Saptamana", this);
    connect(FiltrareOrePeSaptamanaButton, &QPushButton::clicked, this, &MainWindow::filtrareOreSaptamana);
    QHBoxLayout* FiltrareLayout = new QHBoxLayout;
    FiltrareLayout->addWidget(FiltrareCadruDidacticButton);
    FiltrareLayout->addWidget(FiltrareOrePeSaptamanaButton);

    SortareDropMenu = new QComboBox;
    SortareDropMenu->setCurrentText("Sortare");
    SortareDropMenu->addItem("Denumire");
    SortareDropMenu->addItem("Nr. Ore");
    SortareDropMenu->addItem("Categorie");
    SortareDropMenu->addItem("Cadru Didactic");
    connect(SortareDropMenu, &QComboBox::currentIndexChanged, this, &MainWindow::sortare);
    ReverseOrderButton = new QPushButton("<->", this);
    ReverseOrderButton->setProperty("isAscending", true);
    connect(ReverseOrderButton, &QPushButton::clicked, this, &MainWindow::schimbaDirectiaSortarii);
    QHBoxLayout* SortareLayout = new QHBoxLayout;
    SortareLayout->addWidget(SortareDropMenu);
    SortareLayout->addWidget(ReverseOrderButton);

    QPushButton* UndoButton = new QPushButton("Undo", this);
    connect(UndoButton, &QPushButton::clicked, this, &MainWindow::undo);
    QVBoxLayout* UndoLayout = new QVBoxLayout;
    UndoLayout->addWidget(UndoButton);

    QPushButton* EmptyContractButton = new QPushButton("Golire Contract", this);
    connect(EmptyContractButton, &QPushButton::clicked, this, &MainWindow::golireContract);
    QPushButton* AddToContractButton = new QPushButton("Adaugare la Contract", this);
    connect(AddToContractButton, &QPushButton::clicked, this, &MainWindow::adaugareInContract);
    QPushButton* PopulateContractButton = new QPushButton("Populare Contract", this);
    connect(PopulateContractButton, &QPushButton::clicked, this, &MainWindow::populareContract);
    QPushButton* ExportContractButton = new QPushButton("Exportare Contract", this);
    connect(ExportContractButton, &QPushButton::clicked, this, &MainWindow::exportContract);
    QPushButton* ViewContractButton = new QPushButton("VizionareContract", this);
    connect(ViewContractButton, &QPushButton::clicked, this, &MainWindow::afisareContract);
    QHBoxLayout* ContractLayout = new QHBoxLayout;
    ContractLayout->addWidget(EmptyContractButton);
    ContractLayout->addWidget(AddToContractButton);
    ContractLayout->addWidget(PopulateContractButton);
    ContractLayout->addWidget(ExportContractButton);
    ContractLayout->addWidget(ViewContractButton);


    QVBoxLayout* MiddleLayout = new QVBoxLayout;
    MiddleLayout->addLayout(AdaugareLayout);
    MiddleLayout->addLayout(CautareLayout);
    MiddleLayout->addLayout(FiltrareLayout);
    MiddleLayout->addLayout(SortareLayout);

    QHBoxLayout* RightSideLayout = new QHBoxLayout;
    RightSideLayout->addLayout(MiddleLayout);
    ButoaneCategoriiLayout = new QVBoxLayout;
    RightSideLayout->addLayout(ButoaneCategoriiLayout);

    QHBoxLayout* TopSide = new QHBoxLayout;
    TopSide->addLayout(RepoLayout);
    TopSide->addLayout(RightSideLayout);

    QVBoxLayout* Footer = new QVBoxLayout;
    Footer->addLayout(UndoLayout);
    Footer->addLayout(ContractLayout);

    QVBoxLayout* WindowLayout = new QVBoxLayout;
    WindowLayout->addLayout(TopSide);
    WindowLayout->addLayout(Footer);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(WindowLayout);
    setCentralWidget(centralWidget);

    refresh();
}

void MainWindow::refreshRepoTable(std::vector<Disciplina>& listaDiscipline)
{
    RepoTable->clear();

    // Set the column count and headers
    int columnCount = 6;  // 3 strings + 1 int + 2 button
    RepoTable->setColumnCount(columnCount);
    QStringList headers;
    headers << "Denumire" << "Nr. Ore" << "Tip" << "Cadru Didactic" << "Sterge" << "Modifica";
    RepoTable->setHorizontalHeaderLabels(headers);

    // Set the row count
    //std::vector<Disciplina> listaDiscipline = service.get_list();
    int rowCount = static_cast<int>(listaDiscipline.size());
    RepoTable->setRowCount(rowCount);

    // Populate the table
    for (int row = 0; row < rowCount; ++row) {
        const Disciplina& disciplina = listaDiscipline[row];

        // Set the values in each cell
        QTableWidgetItem* item1 = new QTableWidgetItem(QString::fromStdString(disciplina.get_denumire()));
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(disciplina.get_ore()));
        QTableWidgetItem* item3 = new QTableWidgetItem(QString::fromStdString(disciplina.get_tip()));
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::fromStdString(disciplina.get_cadru_didactic()));

        // Create a button in the last column for deleting the row
        QPushButton* deleteButton = new QPushButton("X");
        deleteButton->setProperty("deletedItem", QString::fromStdString(disciplina.get_denumire()));
        connect(deleteButton, &QPushButton::clicked, this, &MainWindow::stergeDisciplina);

        // Create a button in the last column for modifying the row
        QPushButton* modifyButton = new QPushButton("~");
        modifyButton->setProperty("modifiedItem", QString::fromStdString(disciplina.get_denumire()));
        connect(modifyButton, &QPushButton::clicked, this, &MainWindow::modificaDisciplina);

        // Set the items and button in the table
        RepoTable->setItem(row, 0, item1);
        RepoTable->setItem(row, 1, item2);
        RepoTable->setItem(row, 2, item3);
        RepoTable->setItem(row, 3, item4);
        RepoTable->setCellWidget(row, 4, deleteButton);
        RepoTable->setCellWidget(row, 5, modifyButton);
    }

    // Resize the columns to fit the content
    RepoTable->resizeColumnsToContents();

    // REFRESH THE REPO LIST AS WELL

    /*
    RepoList->clear();

    for (const Disciplina& disc : listaDiscipline)
    {
        QListWidgetItem* item = new QListWidgetItem;

        item->setText(QString::fromStdString(disc.to_string()));

        RepoList->addItem(item);
    }
    */
}

void MainWindow::refreshCategoryButtonsLayout()
{
    std::map<std::string, int> NrOfEachType = service.getNrOfEachType();

    //QVBoxLayout* TypeButtonsLayout = new QVBoxLayout;
    QLayoutItem* item;
    while ((item = ButoaneCategoriiLayout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            ButoaneCategoriiLayout->removeWidget(widget);
            delete widget;
        }
        else {
            ButoaneCategoriiLayout->removeItem(item);
            delete item;
        }
    }

    for (auto& pair : NrOfEachType)
    {
        QPushButton* button = new QPushButton(QString::fromStdString(pair.first), this);
        button->setProperty("nr", pair.second);
        connect(button, &QPushButton::clicked, this, &MainWindow::showNumberOfItemsInCategory);
        ButoaneCategoriiLayout->addWidget(button);
    }
}

void MainWindow::refresh()
{
    std::vector<Disciplina> listaDiscipline = service.get_list();
    refreshRepoTable(listaDiscipline);
    refreshCategoryButtonsLayout();
}

void MainWindow::showNumberOfItemsInCategory()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QMessageBox::information(this, button->text(), button->property("nr").toString());
}

void MainWindow::adaugaDisciplina()
{
    AdaugareDialog dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        Disciplina disc = dialog.getDisciplina();
        if (disc.get_denumire().size() == 0)
        {
            return;
        }
        service.service_1(disc);
        refresh();
    }
}

void MainWindow::stergeDisciplina()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());

    std::string denumire = senderButton->property("deletedItem").toString().toStdString();

    service.service_2(denumire);

    refresh();
}

void MainWindow::modificaDisciplina()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    std::string denumire = senderButton->property("modifiedItem").toString().toStdString();

    Disciplina disciplina;

    AdaugareDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
    {
        return;
    }

    disciplina = dialog.getDisciplina();
    if (disciplina.get_denumire().size() == 0)
    {
        return;
    }

    service.service_3(denumire, disciplina);

    refresh();
}

void MainWindow::cautaDisciplina()
{
    QLineEdit* senderLineEdit = qobject_cast<QLineEdit*>(sender());
    std::string denumire = senderLineEdit->text().toStdString();

    bool gasit = service.service_5(denumire);

    if (gasit)
    {
        for (int row = 0; row < RepoTable->rowCount(); row++)
        {
            QTableWidgetItem* item = RepoTable->item(row, 0);
            if (item && item->text().toStdString() == denumire)
            {
                item->setBackground(Qt::green);
            }
        }
    }
    else
    {
        QMessageBox::information(this, QString::fromStdString(denumire), "Disciplina nu a fost gasita :(");
    }
}

void MainWindow::filtrareOreSaptamana()
{
    FiltrareNumarOreDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
    {
        return;
    }

    std::pair<int, int> min_max = dialog.getMinMax();
    int _min = min_max.first;
    int _max = min_max.second;

    std::vector<Disciplina> lista = service.get_list();
    std::vector<Disciplina> listaDiscipline;

    std::copy_if(lista.begin(), lista.end(), std::back_inserter(listaDiscipline), [_min, _max](Disciplina disc) { return disc.get_ore() >= _min && disc.get_ore() <= _max; });
    
    refreshRepoTable(listaDiscipline);
}

void MainWindow::filtrareCadruDidactic()
{
    FiltrareCadruDidacticDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
    {
        return;
    }

    std::string cadru = dialog.getCadruDidactic();

    std::vector<Disciplina> lista = service.get_list();
    std::vector<Disciplina> listaDiscipline;

    std::copy_if(lista.begin(), lista.end(), std::back_inserter(listaDiscipline), [cadru](Disciplina disc) { return disc.get_cadru_didactic() == cadru; });

    refreshRepoTable(listaDiscipline);
}

void MainWindow::schimbaDirectiaSortarii()
{
    if (ReverseOrderButton->property("isAscending").toBool())
    {
        ReverseOrderButton->setProperty("isAscending", false);
    }
    else
    {
        ReverseOrderButton->setProperty("isAscending", true);
    }
    sortare();
}

void MainWindow::sortare()
{
    int sort_type = SortareDropMenu->currentIndex();
    bool isAscending = ReverseOrderButton->property("isAscending").toBool();
    int order = 1;
    if (isAscending)
    {
        order = 0;
    }
    service.service_7(sort_type, order);
    refresh();
}

void MainWindow::golireContract()
{
    service.service_8();
}

void MainWindow::adaugareInContract()
{
    stdStringDialog dialog = stdStringDialog("Indexul Disciplinei de Adaugat:");
    if (dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    int index = std::stoi(dialog.getValue());
    try
    {
        service.service_10(index);
    }
    catch (std::exception e)
    {
        QMessageBox::information(this, "Exeption Thrown", "Item already exists!");//QString::fromStdString(e.what()));
    }
}

void MainWindow::populareContract()
{
    stdStringDialog dialog = stdStringDialog("Numarul de Discipline de Adaugat:");
    if (dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    int count = std::stoi(dialog.getValue());

    service.service_9(count);
}

void MainWindow::exportContract()
{
    service.service_11("../Resource Files/Contract.txt");
}

void MainWindow::afisareContract()
{
    QMessageBox::information(this, "Contract", QString::fromStdString(service.contractString()));
}

void MainWindow::undo()
{
    service.service_12();
    refresh();
}

void MainWindow::UpdateContractWindows()
{
    for (CosGUI* observer : observers)
    {

    }
}
