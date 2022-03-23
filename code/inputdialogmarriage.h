#ifndef INPUTDIALOGMARRIAGE_H
#define INPUTDIALOGMARRIAGE_H

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

class InputDialogMarriage : public QDialog
{
    Q_OBJECT
public:
    InputDialogMarriage(QWidget *parent = nullptr);
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
    QCheckBox* checkLunch;
    QSpinBox* spinNumberOfFlower;
    QSpinBox* spinNumberOfWaiters;
    QComboBox* cType;




    QFormLayout *lytMain;
    EventViewer* e;

    std::pair<int, std::vector<QString>> list;


    void addNewEvent();
public slots:
    void getInfo();
};

#endif // INPUTDIALOGMARRIAGE_H
