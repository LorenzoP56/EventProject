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
#include<QString>
#include<inputdialogb.h>
#include<mycalendarwidget.h>
#include<inputdialogmarriage.h>
#include<inputdialogmarathon.h>
#include<inputdialogt.h>

class Controller;

class EventViewer : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* lblCalendarLayout;
    QHBoxLayout* buttonLayout;
    QVBoxLayout* lineLayout;

    QMenuBar* menuBar;
    QMenu* inserisci;
    QMenu* file;
    QMenu* exit;
    QMenu* control;

    MyCalendarWidget* calendar;
    QLabel* label;
    QFrame* line;

    Controller* controller;

    QPushButton* previuosEvent;
    QPushButton* nextEvent;
    QPushButton* firstEvent;
    QPushButton* lastEvent;
    QPushButton* download;
    QPushButton* upload;

    void addMenus();
    void addCalendar();
    void addLabel();
    void addControls();
    void addLine();


public:
    void setController(Controller* c);
    explicit EventViewer(QWidget *parent = nullptr);
    void showWarning(const QString&) const;

    QString showRemoveEvent();

    void showEvento(Event* event);
    void finish(std::pair<int, std::vector<QString>>) const;
    void clean();

    void cleanCalendar(const QDate&) const;

public slots:
    void showAddEvent();
    void showAddEventB();
    void showAddEventMarriage();
    void showAddEventMarathon();
    void showAddEventTournament();
};

#endif // EVENTVIEWER_H
