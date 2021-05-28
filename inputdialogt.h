#ifndef INPUTDIALOGT_H
#define INPUTDIALOGT_H

#include<QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDateEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <vector>
#include<utility>
#include "eventviewer.h"

class InputDialogT : public QDialog
{
    Q_OBJECT
public:
    InputDialogT(QWidget* parent = nullptr);
    /**
     * @brief metodo ritorna list
     */
    std::pair<int, std::vector<QString>> getI()const;
private:
    QLineEdit* eLoc;
    QLineEdit* eTit;
    QLineEdit* eEmpl;
    QSpinBox* eRating;
    QSpinBox* eExp;
    QDateEdit* eDate;

    QCheckBox* isPro;
    QComboBox* comboTypeSport;
    QLineEdit* qlOrganizationTeam;
    QSpinBox* spinComponents;
    QSpinBox* spinTeamSub;

    QFormLayout *lytMain;
    EventViewer* e;

    std::pair<int, std::vector<QString>> list;

    /**
     * @brief metodo che agginge i campi da riempire nel dialog
     */
    void addNewEvent();
public slots:
    void getInfo();
};

#endif // INPUTDIALOGT_H
