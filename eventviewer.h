#ifndef EVENTVIEWER_H
#define EVENTVIEWER_H

#include <QWidget>
#include<QBoxLayout>
#include<QMenuBar>
#include<QPushButton>
#include<QCalendarWidget>
#include<QLabel>
#include<QDialog>
#include<vector>
#include<QInputDialog>
#include<QDate>
#include<event.h>
#include<inputdialog.h>
#include<QGroupBox>
#include<QLine>
#include<string>

class EventViewer : public QWidget
{
    Q_OBJECT
private:

    //Controller* controller;
    QVBoxLayout* mainLayout;
    QHBoxLayout* lblCalendarLayout;
    QHBoxLayout* buttonLayout;
    QVBoxLayout* lineLayout;

    QMenuBar* menuBar;
    QMenu* inserisci;
    QMenu* file;
    QMenu* exit;
    QMenu* control;

    QCalendarWidget* calendar;
    QLabel* label;
    QFrame* line;

    void addMenus();
    void addCalendar();
    void addLabel();
    void addControls();
    void addLine();
public:
    //void setController(Controller* c);
    explicit EventViewer(QWidget *parent = nullptr);
    void showThisEvent (Event* e) const;
    void showWarning(const QString&);
    QStringList showAddEvent();
    QString showRemoveEvent();


signals:

};

#endif // EVENTVIEWER_H
