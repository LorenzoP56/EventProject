#ifndef INPUTDIALOGB_H
#define INPUTDIALOGB_H

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

class InputDialogB : public QDialog
{
    Q_OBJECT
public:
    InputDialogB(QWidget* parent = nullptr);
    std::pair<int, std::vector<QString>> getI()const;
private:
    QLineEdit* eLoc;
    QLineEdit* eTit;
    QLineEdit* eEmpl;
    QSpinBox* eRating;
    QSpinBox* eExp;
    QDateEdit* eDate;

    QSpinBox* eNumGue;
    QComboBox* comboIsMale;
    QSpinBox* spinNumberDancers;

    QFormLayout *lytMain;
    EventViewer* e;

    std::pair<int, std::vector<QString>> aux;


    void addNewEvent();
public slots:
    void getInfo();

};

#endif // INPUTDIALOGB_H
