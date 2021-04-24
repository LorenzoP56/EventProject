#include "inputdialogt.h"

InputDialogT::InputDialogT(QWidget* parent): QDialog(parent), e(dynamic_cast<EventViewer*>(parent))
{
    lytMain = new QFormLayout(this);
    addNewEvent();

    QPushButton* button = new QPushButton("Invia", this);
    lytMain->addWidget(button);


    connect(button, SIGNAL(clicked()), this, SLOT(getInfo()));
    connect(button, SIGNAL(clicked()), this, SLOT(close()));

    setLayout(lytMain);
    setMinimumSize(200,200);
}

std::pair<int, std::vector<QString> > InputDialogT::getI() const
{
    return list;
}

void InputDialogT::addNewEvent()
{
    QLabel* lblNewEvent = new QLabel("-- INFORMAZIONI GENERALI EVENTO --",this);
    lytMain->addRow(lblNewEvent);

    QLabel* lblLoc = new QLabel("Luogo evento: ",this);
    eLoc = new QLineEdit(this);
    lytMain->addRow(lblLoc,eLoc);

    QLabel* lblTit = new QLabel("Titolo evento: ",this);
    eTit = new QLineEdit(this);
    lytMain->addRow(lblTit,eTit);

    QLabel* lblDate= new QLabel("Data evento: ",this);
    eDate = new QDateEdit(this);
    eDate->setMinimumDate(QDate(2021,1,1));
    lytMain->addRow(lblDate,eDate);

    QLabel* lblRating = new QLabel("Difficoltà evento",this);
    eRating = new QSpinBox(this);
    eRating->setMinimum(1);
    eRating->setMaximum(5);
    lytMain->addRow(lblRating,eRating);

    QLabel* lblEmpl = new QLabel("Impiegato designato: ",this);
    eEmpl= new QLineEdit(this);
    lytMain->addRow(lblEmpl,eEmpl);

    QLabel* lblExp = new QLabel("Esperienza impiegato",this);
    eExp = new QSpinBox(this);
    eExp->setMinimum(1);
    eExp->setMaximum(5);
    lytMain->addRow(lblExp,eExp);

    QLabel* lblSport = new QLabel ("-- INFORMAZIONI RELATIVE EVENTO SPORTIVO --");
    lytMain->addRow(lblSport);

    QLabel* lblIsPro = new QLabel ("Atleti professionisti?");
    isPro = new QCheckBox(this);
    lytMain->addRow(lblIsPro, isPro);

    QLabel* lblTournament = new QLabel ("-- INFORMAZIONI RELATIVE TORNEO --");
    lytMain->addRow(lblTournament);

    QLabel* lblTypeSport = new QLabel ("Tipo di sport");
    comboTypeSport = new QComboBox(this);
    comboTypeSport->addItem("Basket");
    comboTypeSport->addItem("Football");
    lytMain->addRow(lblTypeSport,comboTypeSport);

    QLabel* lblOrganizationTeam = new QLabel("Squadra organizzatrice");
    qlOrganizationTeam = new QLineEdit (this);
    lytMain->addRow(lblOrganizationTeam,qlOrganizationTeam);

    QLabel* lblComponents = new QLabel("Numero atleti del team");
    spinComponents = new QSpinBox(this);
    lytMain->addRow(lblComponents,spinComponents);

    QLabel* lblTeamSub = new QLabel ("Squadre iscritte");
    spinTeamSub = new QSpinBox(this);
    lytMain->addRow(lblTeamSub,spinTeamSub);
}

void InputDialogT::getInfo()
{
    QString day, month;
    list.first = 5;
    list.second.push_back(eLoc->text());
    list.second.push_back(eTit->text());
    list.second.push_back(eEmpl->text());
    list.second.push_back(eRating->text());
    list.second.push_back(eExp->text());
    list.second.push_back(day.setNum(eDate->date().day()));
    list.second.push_back(month.setNum(eDate->date().month()));
    list.second.push_back(isPro->isChecked() == true ? "yes" : "no");
    list.second.push_back(comboTypeSport->currentText());
    list.second.push_back(qlOrganizationTeam->text());
    list.second.push_back(spinComponents->text());
    list.second.push_back(spinTeamSub->text());

    e->finish(list);
}
