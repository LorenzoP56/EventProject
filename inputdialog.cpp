#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent, int t) : QDialog(parent),type(t)
{
    QFormLayout *lytMain = new QFormLayout(this);

    QLabel* lblLoc = new QLabel("Luogo evento: ",this);
    eLoc = new QLineEdit(this);
    lytMain->addRow(lblLoc,eLoc);
    fields<<eLoc;

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

    switch (type) {
        case 0:{
            QLabel* lblFiera = new QLabel ("- STAI INSERENDO UNA FIERA -");
            lytMain->addRow(lblFiera);
            QLabel* lblCompName = new QLabel("Nome compagnia",this);
            QLineEdit* eCompName = new QLineEdit(this);
            lytMain->addRow(lblCompName,eCompName);
            QLabel* lblNumWork = new QLabel("Numero lavoratori",this);
            QSpinBox* eNumWork = new QSpinBox(this);
            lytMain->addRow(lblNumWork,eNumWork);
        };break;

        case 1:{
        QLabel* lblMatrimonio = new QLabel ("- STAI INSERENDO UN MATRIMONIO -");
        lytMain->addRow(lblMatrimonio);
        QLabel* lblNumGue = new QLabel ("Numero invitati",this);
        QSpinBox* eNumGue = new QSpinBox(this);
        lytMain->addRow(lblNumGue,eNumGue);
        };break;
    }

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
    InputDialog *dialog = new InputDialog(parent,type);

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
