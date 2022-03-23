#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
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


class EventViewer;

class InputDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* eLoc;
    QLineEdit* eTit;
    QLineEdit* eEmpl;
    QSpinBox* eRating;    
    QSpinBox* eExp;
    QDateEdit* eDate;

    QFormLayout *lytMain;

    QComboBox* cType;
    QLineEdit* cName;
    QSpinBox* cNumWork;

    EventViewer* e;

    std::pair<int, std::vector<QString>> list;


    void addNewEvent();

public:
    explicit InputDialog(QWidget *parent = nullptr);

    std::pair<int, std::vector<QString>> getI()const;

public slots:
     void getInfo();

};

#endif // INPUTDIALOG_H
