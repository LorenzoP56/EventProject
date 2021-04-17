#include "inputdialogmarathon.h"

InputDialogMarathon::InputDialogMarathon(QWidget* parent): QDialog(parent), e(dynamic_cast<EventViewer*>(parent))
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

std::pair<int, std::vector<QString> > InputDialogMarathon::getI() const
{
    return list;
}

void InputDialogMarathon::addNewEvent()
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

    QLabel* lblMarathon = new QLabel ("-- INFORMAZIONI RELATIVE MARATONA --");
    lytMain->addRow(lblMarathon);

    QLabel* lblTown = new QLabel("Città svolgimento maratona");
    city = new QLineEdit(this);
    lytMain->addRow(lblTown,city);

    QLabel* lblMarathonPart = new QLabel("Numero di iscritti");
    partecipants = new QSpinBox(this);
    partecipants->setMinimum(40);
    lytMain->addRow(lblMarathonPart,partecipants);

    QLabel* lblLength = new QLabel ("Lunghezza totale percorso (metri)");
    len = new QDoubleSpinBox(this);
    len->setMinimum(2500);
    len->setMaximum(10000);
    lytMain->addRow(lblLength,len);
}

void InputDialogMarathon::getInfo()
{
    QString day, month;
    list.first = 4;
    list.second.push_back(eLoc->text());
    list.second.push_back(eTit->text());
    list.second.push_back(eEmpl->text());
    list.second.push_back(eRating->text());
    list.second.push_back(eExp->text());
    list.second.push_back(day.setNum(eDate->date().day()));
    list.second.push_back(month.setNum(eDate->date().month()));
    list.second.push_back(isPro->isChecked() == true ? "yes" : "no");
    list.second.push_back(partecipants->text());
    list.second.push_back(city->text());
    list.second.push_back(len->text());

    e->finish(list);
}
