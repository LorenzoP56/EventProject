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

class EventViewer : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* secondLayout;
    QVBoxLayout* thirdLayout;
    QVBoxLayout* fourthLayout;
    QMenuBar* menuBar;
    QCalendarWidget* calendar;
    QLabel* label;

    void addMenus();
    void addCalendar();
    void addLabel();
    void addControls();
public:
    explicit EventViewer(QWidget *parent = nullptr);
    void showThisEvent (Event* e) const;
    void showWarning(const QString&);
    std::pair<int,QString*> showAddEvent();
    QString showRemoveEvent();

signals:

};

#endif // EVENTVIEWER_H
