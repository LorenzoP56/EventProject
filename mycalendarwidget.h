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
    /**
     * @brief mettodo di aggiunta della data in lista contenente tutte le date degli eventi salvati
     */
    void addEvent(const QDate&);
    /**
     * @brief metodo che elimina da myDates la QDate passata
     */
    void cleanCalendar(const QDate&);
    void cleanAllEvent();
protected:
    /**
     * @brief override funzione paintCell di QCalendarWidget
     */
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;
private:
    QList<QDate> myDates;
    /**
     * @brief metodo che controlla la presenza della data nella lista
     * @return true se presente, false altrimenti
     */
    bool isIn(const QDate&);
    QDate data;

    EventViewer* e;
public slots:
    void showMyEvent(const QDate&);
signals:
    void ShowEventAux(const QDate&);
};

#endif // MYCALENDARWIDGET_H
