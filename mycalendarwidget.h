#ifndef MYCALENDARWIDGET_H
#define MYCALENDARWIDGET_H

#include<QCalendarWidget>
#include<QPainter>
#include<QRect>
#include<eventviewer.h>

class MyCalendarWidget : public QCalendarWidget
{
    Q_OBJECT
public:
    MyCalendarWidget(QWidget *parent=Q_NULLPTR);
    void addEvent(const QDate&);
    void cleanCalendar(const QDate&);
protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;
private:
    QList<QDate> myDates;
    bool isIn(const QDate&);
    QDate data;

    EventViewer* e;
public slots:
    void showMyEvent(const QDate&);
signals:
    void ShowEventAux(const QDate&);
};

#endif // MYCALENDARWIDGET_H
