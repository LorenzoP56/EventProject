#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QObject>
#include "eventviewer.h"
#include "modelevent.h"
#include<utility>
#include<vector>

class Controller : public QObject
{
    Q_OBJECT
private:
    EventViewer* view;
    ModelEvent* model;
    /**
     * @brief metodo che richiama la vista per mostrare un determinato Evento
     */
    void showEvent() const;
public:
    explicit Controller(QObject *parent = nullptr);

    void setModel(ModelEvent* m);
    void setView(EventViewer* v);
public slots:
    void nextEvent() const;
    void previousEvent() const;
    void begin();
    void last() const;

    void addEvent(std::pair<int, std::vector<QString>>) const;
    void removeEvent() const;

    void takeEvent(const QDate&);

};

#endif // CONTROLLER_H
