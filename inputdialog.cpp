#include "inputdialog.h"
#include<eventviewer.h>

InputDialog::InputDialog(QWidget *parent) : QDialog(parent), e(dynamic_cast<EventViewer*>(parent))
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


std::pair<int, std::vector<QString> > InputDialog::getI() const
{
    return list;
}

void InputDialog::getInfo()
{
    QString day, month;
    list.first = 1;
    list.second.push_back(eLoc->text());
    list.second.push_back(eTit->text());
    list.second.push_back(eEmpl->text());
    list.second.push_back(eRating->text());
    list.second.push_back(eExp->text());
    list.second.push_back(day.setNum(eDate->date().day()));
    list.second.push_back(month.setNum(eDate->date().month()));
    list.second.push_back(cType->currentText());
    list.second.push_back(cName->text());
    list.second.push_back(cNumWork->text());

    e->finish(list);
}


void InputDialog::addNewEvent(){

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
    eDate->setMaximumDate(QDate(2021, 12,31));
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

    QLabel* lblFiera = new QLabel ("-- INFORMAZIONI RELATIVE ALLA FIERA --");
    lytMain->addRow(lblFiera);

    QLabel* lblTypeFair = new QLabel ("Inserisci tipo fiera",this);
    cType = new QComboBox(this);
    cType->addItem("Piccola");
    cType->addItem("Media");
    cType->addItem("Grande");
    lytMain->addRow(lblTypeFair,cType);

    QLabel* lblCompName = new QLabel("Nome compagnia",this);
    cName = new QLineEdit(this);
    lytMain->addRow(lblCompName,cName);

    QLabel* lblNumWork = new QLabel("Numero lavoratori",this);
    cNumWork = new QSpinBox(this);
    lytMain->addRow(lblNumWork,cNumWork);
}
