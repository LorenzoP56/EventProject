#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include<eventviewer.h>
#include<modelevent.h>
#include<utility>

class Controller : public QObject
{
    Q_OBJECT
private:
    EventViewer* view;
    ModelEvent* model;
    void showEvent() const;
public:
    explicit Controller(QObject *parent = nullptr);

    void setModel(ModelEvent* m);
    void setView(EventViewer* v);
public slots:
    void nextEvent() const;
    void previousEvent() const;
    void begin() const;
    void last() const;

    void addEvent() const;
    void removeEvent() const;

};

#endif // CONTROLLER_H
