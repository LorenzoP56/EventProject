#include "inputdialogmarriage.h"

InputDialogMarriage::InputDialogMarriage(QWidget *parent): QDialog(parent), e(dynamic_cast<EventViewer*>(parent))
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

std::pair<int, std::vector<QString> > InputDialogMarriage::getI() const
{
    return list;
}

void InputDialogMarriage::addNewEvent()
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

    QLabel* lblMarriage = new QLabel ("-- INFORMAZIONI RELATIVE AL MARRIAGE --");
    lytMain->addRow(lblMarriage);

    QLabel* lblCheckLunch = new QLabel ("Pranzo compreso? ");
    checkLunch = new QCheckBox(this);
    lytMain->addRow(lblCheckLunch,checkLunch);

    QLabel* lblFlower = new QLabel("Numero di fiori");
    spinNumberOfFlower = new QSpinBox(this);
    lytMain->addRow(lblFlower,spinNumberOfFlower);

    QLabel* lblWaiters = new QLabel("Numero di camerieri");
    spinNumberOfWaiters = new QSpinBox(this);
    spinNumberOfWaiters->setMinimum(2);
    lytMain->addRow(lblWaiters,spinNumberOfWaiters);

    QLabel* lblPriceForBand = new QLabel ("Tipologia chiesa");
    cType = new QComboBox(this);
    cType->addItem("Cristiana");
    cType->addItem("Ortodossa");
    lytMain->addRow(lblPriceForBand,cType);


}

void InputDialogMarriage::getInfo()
{
    QString day, month;
    list.first = 3;
    list.second.push_back(eLoc->text());
    list.second.push_back(eTit->text());
    list.second.push_back(eEmpl->text());
    list.second.push_back(eRating->text());
    list.second.push_back(eExp->text());
    list.second.push_back(day.setNum(eDate->date().day()));
    list.second.push_back(month.setNum(eDate->date().month()));
    list.second.push_back(eNumGue->text());
    list.second.push_back(comboIsMale->currentText());
    list.second.push_back(checkLunch->isChecked() == true ? "yes" : "no");
    list.second.push_back(spinNumberOfFlower->text());
    list.second.push_back(spinNumberOfWaiters->text());
    list.second.push_back(cType->currentText());

    e->finish(list);
}
