#include "mycalendarwidget.h"

MyCalendarWidget::MyCalendarWidget(QWidget *parent): QCalendarWidget(parent)
{
    QObject::connect(this, SIGNAL(clicked(const QDate&)), this, SLOT(showMyEvent(const QDate&)));
}

void MyCalendarWidget::addEvent(const QDate & date)
{
    myDates<<date;
    updateCell(date);
}

void MyCalendarWidget::cleanCalendar(const QDate & d)
{
    bool flag = false;
    for(auto it = myDates.begin(); it!=myDates.end() && !flag; it++)
        if(*it == d){
            myDates.erase(it);
            flag = true;
        }
    updateCells();
}

void MyCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    if(myDates.contains(date)){
        painter->save();
        painter->drawImage(rect, QImage(":/Resources/index.png"));
        painter->restore();
    }
    else
        QCalendarWidget::paintCell(painter, rect, date);
}

bool MyCalendarWidget::isIn(const QDate & d)
{
    for(auto it = myDates.begin(); it!=myDates.end(); it++)
        if(*it == d)
            return true;
    return false;
}

void MyCalendarWidget::showMyEvent(const QDate & d)
{
    data = d;
    if(isIn(data))
        emit ShowEventAux(data);//lancio segnale
}

