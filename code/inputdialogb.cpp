#include "inputdialogb.h"

InputDialogB::InputDialogB(QWidget* parent): QDialog(parent), e(dynamic_cast<EventViewer*>(parent))
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

std::pair<int, std::vector<QString> > InputDialogB::getI() const
{
    return aux;
}

void InputDialogB::addNewEvent()
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

    QLabel* lblMatrimonio = new QLabel ("-- INFORMAZIONI RELATIVE AL MATRIMONIO --");
    lytMain->addRow(lblMatrimonio);
    QLabel* lblNumGue = new QLabel ("Numero invitati",this);
    eNumGue = new QSpinBox(this);
    lytMain->addRow(lblNumGue,eNumGue);

    QLabel* lblGuestMale = new QLabel ("Inserisci sesso organizzatore",this);
    comboIsMale = new QComboBox(this);
    comboIsMale->addItem("Uomo");
    comboIsMale->addItem("Donna");
    lytMain->addRow(lblGuestMale,comboIsMale);

    QLabel* lblBachelor = new QLabel ("-- INFORMAZIONI RELATIVE AL BACHELOR --");
    lytMain->addRow(lblBachelor);

    QLabel* lblNumberDancers = new QLabel ("Numero ballerine");
    spinNumberDancers = new QSpinBox(this);
    spinNumberDancers->setMinimum(2);
    lytMain->addRow(lblNumberDancers,spinNumberDancers);

}

void InputDialogB::getInfo()
{
    QString day, month;
    aux.first = 2;
    aux.second.push_back(eLoc->text());
    aux.second.push_back(eTit->text());
    aux.second.push_back(eEmpl->text());
    aux.second.push_back(eRating->text());
    aux.second.push_back(eExp->text());
    aux.second.push_back(day.setNum(eDate->date().day()));
    aux.second.push_back(month.setNum(eDate->date().month()));
    aux.second.push_back(eNumGue->text());
    aux.second.push_back(comboIsMale->currentText());
    aux.second.push_back(spinNumberDancers->text());

    e->finish(aux);
}
