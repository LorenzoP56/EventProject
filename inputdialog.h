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


class QLineEdit;
class QLabel;

class InputDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* eLoc;
    QLineEdit* eTit;
    QDateEdit* eDate;
    QComboBox* cType;
    QSpinBox* eRating;
    QLineEdit* eEmpl;
    QSpinBox* eExp;

    QFormLayout *lytMain;

    QList<QLineEdit*> fields;

    QList<QString*> list;

    int type;

    void addNewEvent();
    void buildTypeEvent(int type);
    void addFair();
    void addWedding();
    void addBachelor();
    void addMarriage();
    void addTypeChurch();
    void addSport();
    void addMarathon();
    void addTournament();
    void addTypeSport();

public:
    explicit InputDialog(QWidget *parent = nullptr, int t = 0);
    static void getEvent(QWidget* parent);
    static QStringList getStrings(QWidget *parent, bool *ok = nullptr,int type = 0);

};

#endif // INPUTDIALOG_H
