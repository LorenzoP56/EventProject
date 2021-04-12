#include "inputdialog.h"


InputDialog::InputDialog(QWidget *parent, int t) : QDialog(parent),type(t)
{
    lytMain = new QFormLayout(this);

    addNewEvent();

    buildTypeEvent(type);

    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &InputDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &InputDialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList InputDialog::getStrings(QWidget *parent, bool *ok, int type)
{
    InputDialog *dialog = new InputDialog(parent, type);

    QStringList list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto field, dialog->fields) {
            list << field->text();
        }
    }

    dialog->deleteLater();

    return list;
}

void InputDialog::addNewEvent(){

    QLabel* lblNewEvent = new QLabel("-- INFORMAZIONI GENERALI EVENTO --",this);
    lytMain->addRow(lblNewEvent);

    QLabel* lblLoc = new QLabel("Luogo evento: ",this);
    eLoc = new QLineEdit(this);
    lytMain->addRow(lblLoc,eLoc);
    fields<<eLoc;

    itemList.insert(0,eLoc->text());

    QLabel* lblTit = new QLabel("Titolo evento: ",this);
    eTit = new QLineEdit(this);
    lytMain->addRow(lblTit,eTit);
    fields<<eTit;

    QLabel* lblDate= new QLabel("Data evento: ",this);
    eDate = new QDateEdit(this);
    QDate* d = new QDate(2021,1,1);
    eDate->setMinimumDate(*d);
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
}

void InputDialog::buildTypeEvent(int type){
    switch (type) {
        case 0:{
            addFair();
        };break;

        case 1:{

            addBachelor();
        };break;

        case 2:{
            addMarriage();
        };break;

        case 3:{
            addMarathon();
        };break;

        case 4:{
            addTournament();
        };break;
    }
}

void InputDialog::addFair(){
    QLabel* lblFiera = new QLabel ("-- INFORMAZIONI RELATIVE ALLA FIERA --");
    lytMain->addRow(lblFiera);

    QLabel* lblTypeFair = new QLabel ("Inserisci tipo fiera",this);
    QComboBox* comboTypeFair = new QComboBox(this);
    comboTypeFair->addItem("Piccola");
    comboTypeFair->addItem("Media");
    comboTypeFair->addItem("Grande");
    lytMain->addRow(lblTypeFair,comboTypeFair);

    QLabel* lblCompName = new QLabel("Nome compagnia",this);
    QLineEdit* eCompName = new QLineEdit(this);
    lytMain->addRow(lblCompName,eCompName);

    QLabel* lblNumWork = new QLabel("Numero lavoratori",this);
    QSpinBox* eNumWork = new QSpinBox(this);
    lytMain->addRow(lblNumWork,eNumWork);

    QLabel* lblCostFairWorkersB = new QLabel("Costo lavoratore BIG-COMPANY");
    QDoubleSpinBox* spinCostFairWorkersB = new QDoubleSpinBox(this);
    lytMain->addRow(lblCostFairWorkersB,spinCostFairWorkersB);

    QLabel* lblCostFairWorkersSmall = new QLabel("Costo lavoratore SMALL-COMPANY");
    QDoubleSpinBox* spinCostFairWorkersSmall = new QDoubleSpinBox(this);
    lytMain->addRow(lblCostFairWorkersSmall,spinCostFairWorkersSmall);
}

void InputDialog::addWedding(){
    QLabel* lblMatrimonio = new QLabel ("-- INFORMAZIONI RELATIVE AL MATRIMONIO --");
    lytMain->addRow(lblMatrimonio);

    QLabel* lblNumGue = new QLabel ("Numero invitati",this);
    QSpinBox* eNumGue = new QSpinBox(this);
    lytMain->addRow(lblNumGue,eNumGue);

    QLabel* lblGuestMale = new QLabel ("Inserisci sesso organizzatore",this);
    QComboBox* comboIsMale = new QComboBox(this);
    comboIsMale->addItem("Uomo");
    comboIsMale->addItem("Donna");
    lytMain->addRow(lblGuestMale,comboIsMale);
}

void InputDialog::addBachelor(){

    addWedding();

    QLabel* lblBachelor = new QLabel ("-- INFORMAZIONI RELATIVE AL BACHELOR --");
    lytMain->addRow(lblBachelor);

    QLabel* lblNumberDancers = new QLabel ("Numero ballerine");
    QSpinBox* spinNumberDancers = new QSpinBox(this);
    spinNumberDancers->setMinimum(2);
    lytMain->addRow(lblNumberDancers,spinNumberDancers);

    QLabel* lblPriceForDancers = new QLabel ("Costo per ballerina");
    QDoubleSpinBox* spinPriceForDancers = new QDoubleSpinBox(this);
    lytMain->addRow(lblPriceForDancers,spinPriceForDancers);

    QLabel* lblPriceForGuests = new QLabel ("Costo per invitato");
    QDoubleSpinBox* spinPriceForGuests = new QDoubleSpinBox(this);
    lytMain->addRow(lblPriceForGuests,spinPriceForGuests);

}

void InputDialog::addMarriage(){

    addWedding();

    QLabel* lblMarriage = new QLabel ("-- INFORMAZIONI RELATIVE AL MARRIAGE --");
    lytMain->addRow(lblMarriage);

    QLabel* lblCheckLunch = new QLabel ("Pranzo compreso? ");
    QCheckBox* checkLunch = new QCheckBox(this);
    lytMain->addRow(lblCheckLunch,checkLunch);

    addTypeChurch();

    QLabel* lblFlower = new QLabel("Numero di fiori");
    QSpinBox* spinNumberOfFlower = new QSpinBox(this);
    lytMain->addRow(lblFlower,spinNumberOfFlower);

    QLabel* lblPriceForFlower = new QLabel ("Costo per fiore");
    QDoubleSpinBox* spinPriceForFlower = new QDoubleSpinBox(this);
    lytMain->addRow(lblPriceForFlower,spinPriceForFlower);

    QLabel* lblWaiters = new QLabel("Numero di camerieri");
    QSpinBox* spinNumberOfWaiters = new QSpinBox(this);
    spinNumberOfWaiters->setMinimum(2);
    lytMain->addRow(lblWaiters,spinNumberOfWaiters);

    QLabel* lblPriceForWaiters = new QLabel ("Costo per cameriere");
    QDoubleSpinBox* spinPriceForWaiters = new QDoubleSpinBox(this);
    spinPriceForWaiters->setMinimum(50);
    lytMain->addRow(lblPriceForWaiters,spinPriceForWaiters);


    QLabel* lblPriceForBand = new QLabel ("Costo per la banda");
    QDoubleSpinBox* spinPriceForBand = new QDoubleSpinBox(this);
    spinPriceForBand->setMinimum(500);
    spinPriceForBand->setMaximum(100000);
    lytMain->addRow(lblPriceForBand,spinPriceForBand);

}

void InputDialog::addTypeChurch(){
    QLabel* lblTypeChurch = new QLabel ("Tipo di chiesa");
    QComboBox* comboTypeChurch = new QComboBox(this);
    comboTypeChurch->addItem("Cristiana");
    comboTypeChurch->addItem("Ortodossa");
    lytMain->addRow(lblTypeChurch,comboTypeChurch);
}

void InputDialog::addSport(){
    QLabel* lblSport = new QLabel ("-- INFORMAZIONI RELATIVE EVENTO SPORTIVO --");
    lytMain->addRow(lblSport);

    QLabel* lblIsPro = new QLabel ("Atleti professionisti?");
    QCheckBox* checkIsPro = new QCheckBox(this);
    lytMain->addRow(lblIsPro,checkIsPro);

    QLabel* lblPricePolicy = new QLabel ("Costo polizza assicurativa");
    QDoubleSpinBox* spinPricePolicy = new QDoubleSpinBox(this);
    spinPricePolicy->setMinimum(500);
    spinPricePolicy->setMaximum(10000);
    lytMain->addRow(lblPricePolicy,spinPricePolicy);
}

void InputDialog::addMarathon(){

    addSport();

    QLabel* lblMarathon = new QLabel ("-- INFORMAZIONI RELATIVE MARATONA --");
    lytMain->addRow(lblMarathon);

    QLabel* lblTown = new QLabel("Città svolgimento maratona");
    QLineEdit* qlTown = new QLineEdit(this);
    lytMain->addRow(lblTown,qlTown);

    QLabel* lblMarathonPart = new QLabel("Numero di iscritti");
    QSpinBox* spinMarathonPart = new QSpinBox(this);
    spinMarathonPart->setMinimum(20);
    lytMain->addRow(lblMarathonPart,spinMarathonPart);

    QLabel* lblPriceMarathonSub = new QLabel ("Costo per l'iscrizione");
    QDoubleSpinBox* spinPriceMarathonSub = new QDoubleSpinBox(this);
    spinPriceMarathonSub->setMinimum(5);
    lytMain->addRow(lblPriceMarathonSub,spinPriceMarathonSub);


    QLabel* lblLength = new QLabel ("Lunghezza totale percorso (metri)");
    QDoubleSpinBox* spinLength = new QDoubleSpinBox(this);
    spinLength->setMinimum(2500);
    spinLength->setMaximum(10000);
    lytMain->addRow(lblLength,spinLength);


}

void InputDialog::addTournament(){
    addSport();

    QLabel* lblTournament = new QLabel ("-- INFORMAZIONI RELATIVE TORNEO --");
    lytMain->addRow(lblTournament);

    addTypeSport();

    QLabel* lblOrganizationTeam = new QLabel("Squadra organizzatrice");
    QLineEdit* qlOrganizationTeam = new QLineEdit (this);
    lytMain->addRow(lblOrganizationTeam,qlOrganizationTeam);

    QLabel* lblComponents = new QLabel("Numero atleti del team");
    QSpinBox* spinComponents = new QSpinBox(this);
    lytMain->addRow(lblComponents,spinComponents);

    QLabel* lblTeamSub = new QLabel ("Squadre iscritte");
    QSpinBox* spinTeamSub = new QSpinBox(this);
    lytMain->addRow(lblTeamSub,spinTeamSub);
}

void InputDialog::addTypeSport(){
    QLabel* lblTypeSport = new QLabel ("Tipo di sport");
    QComboBox* comboTypeSport = new QComboBox(this);
    comboTypeSport->addItem("Basket");
    comboTypeSport->addItem("Football");
    lytMain->addRow(lblTypeSport,comboTypeSport);
}
