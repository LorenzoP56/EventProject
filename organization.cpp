#include "organization.h"

Organization::Organization(): Eventi(), currentEvent(0) {}


void Organization::addEvent(DeepPtr<Event> evento)
{
    bool flag = false;
    for (Container<DeepPtr<Event>>::Iterator i = Eventi.begin(); i!=Eventi.end(); ++i){
        if((*i)->getTitle() == evento->getTitle())
            throw new std::logic_error("Evento già inserito");
        if((*i)->getDate() == evento->getDate())
            throw new std::logic_error("Evento deve essere univoco, nella data ne è già presente un altro");
    }
    for (Container<DeepPtr<Event>>::Iterator i = Eventi.begin(); i!=Eventi.end() && !flag; ++i)
        if((*i)->getDate() > evento->getDate()){
            Eventi.insert(i, evento);
            flag = true;
        }
    //caso in cui debba andare in coda
    if(!flag)
        Eventi.push_back(evento);
}

std::pair<int, int> Organization::removeEvent(std::string title)
{
    bool flag  = false;
    std::pair<int, int> aux;
    for (Container<DeepPtr<Event>>::Iterator i = Eventi.begin(); i!=Eventi.end() && !flag; i++){
        if ((*i)->getTitle() == title){
            aux.first = (*i)->getDate().getDay();
            aux.second = (*i)->getDate().getMonth();
            Eventi.erase(i);
            flag = true;
        }
    }
    if(!flag)
        throw new std::logic_error("Evento non presente nella raccolta");
    else
        return aux;
}

void Organization::next()
{
    if (currentEvent < static_cast<u_int>(Eventi.size()) - 1)
        currentEvent++;
    else
        goToStart();
}

void Organization::prevoius()
{
    if (currentEvent > 0)
        currentEvent--;
}

void Organization::goToStart()
{
    currentEvent = 0;
}

void Organization::goToEnd()
{
    currentEvent = static_cast<u_int>(Eventi.size()) - 1;
}

u_int Organization::getSize() const
{
    return Eventi.size();
}

Event *Organization::getEvent(u_int i) const
{
    if (i > static_cast<u_int>(Eventi.size() - 1))
        throw std::out_of_range("indice fuori da vettore");
    else
        return Eventi[i].getPunt();
}

u_int Organization::getCurrentEvent() const
{
    return currentEvent;
}

Event *Organization::getEvent(const Date & d) const
{
    for(auto it = Eventi.begin(); it != Eventi.end(); it++)
        if((*it)->getDate() == d)
            return (*it).getPunt();
    return nullptr;
}

void Organization::removeAllEvent()
{
    Eventi.clear();
}

Event *Organization::searchEvent(const std::string &title) const
{
    for(auto it = Eventi.begin(); it != Eventi.end(); it++){
        if((*it)->getTitle() == title)
            return (*it).getPunt();
    }
    return nullptr;
}

void Organization::write(QJsonObject &json) const{

    QJsonArray eventJSON;
    for(auto it = Eventi.begin(); it != Eventi.end(); it++){
        QJsonObject jsonObj;
        (*it)->write(jsonObj);
        jsonObj["type"] = typeid((*it).operator*()).name();
        eventJSON.append(jsonObj);
    }
    json["eventi"] = eventJSON;
}

void Organization::read(QJsonObject jsonFile){

    Eventi.clear();

    QJsonArray items = jsonFile["eventi"].toArray();
        foreach(QJsonValue item, items){
            QJsonObject obj = item.toObject();
            Event *p = nullptr;

            if (obj["type"].toString() == typeid(CommercialFair).name()) {
                p = new CommercialFair();
                p->read(obj);
            }

            else if (obj["type"].toString() == typeid(BachelorParty).name()) {
                p = new BachelorParty();
                p->read(obj);
            }

            else if (obj["type"].toString() == typeid(Marriage).name()) {
                p = new Marriage();
                p->read(obj);
            }

            else if (obj["type"].toString() == typeid(Marathon).name()) {
                p = new Marathon();
                p->read(obj);
            }

            else if (obj["type"].toString() == typeid(Tournament).name()) {
                p = new Tournament();
                p->read(obj);
            }

            addEvent(DeepPtr<Event>(p));
        }
}


