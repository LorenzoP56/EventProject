#include "controller.h"

void Controller::showEvent() const
{
    /*
    try {
        view->showEvent(model->getEvent());
    } catch () {

    }*/
}

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::setModel(ModelEvent *m)
{
    model = m;
}

void Controller::setView(EventViewer *v)
{
    view = v;
}

void Controller::nextEvent() const
{
    model->nextEvent();
    showEvent();
}

void Controller::previousEvent() const
{
    model->previousEvent();
    showEvent();
}

void Controller::begin() const
{
    model->firstEvent();
    showEvent();
}

void Controller::last() const
{
    model->lastEvent();
    showEvent();
}

void Controller::addEvent() const
{
    std::pair<int, QString*> add; //= view->showAddEvent();
    switch (add.first) {
        case 1: //model->addNewEventFair(add.second[0],...)
        break;
        case 2: //model->addNewEventBachelor(add.second[0],...)
        break;
        case 3: //model->addNewEventBachelor(add.second[0],...)
        break;
        case 4: //model->addNewEventBachelor(add.second[0],...)
        break;
        case 5: //model->addNewEventBachelor(add.second[0],...)
        break;
    }
}

void Controller::removeEvent() const
{
    QString title = view->showRemoveEvent();
    model->remove(title.toStdString());
}

