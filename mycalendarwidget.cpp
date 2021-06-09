#include "mycalendarwidget.h"

MyCalendarWidget::MyCalendarWidget(QWidget *parent): QCalendarWidget(parent),e(dynamic_cast<EventViewer*>(parent))
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

void MyCalendarWidget::cleanAllEvent(){
    myDates.clear();
    updateCells();
}
void MyCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{


    if(myDates.contains(date)){
        painter->save();
        /*QImage img (":/Resources/calendar.png");
        painter->drawImage(rect, img);*/

        painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(51,204,255));
        painter->drawEllipse(QPoint(rect.x()+rect.width()/2,rect.y()+rect.height()/2),15,15);
        painter->setPen(QColor(255, 255, 255));
        painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
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
    e->updateLabel();
    if(isIn(data))
        emit ShowEventAux(data);//lancio segnale
    else e->clean();
}

