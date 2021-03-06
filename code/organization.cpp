#include "organization.h"

Organization::Organization(): Eventi(), currentEvent(0) {}


void Organization::addEvent(DeepPtr<Event> evento)
{
    bool flag = false;
    for (std::vector<DeepPtr<Event>>::iterator i = Eventi.begin(); i!=Eventi.end(); ++i){
        if((*i)->getTitle() == evento->getTitle())
            throw new std::logic_error("evento già inserito");
        if((*i)->getDate() == evento->getDate())
            throw new std::logic_error("evento deve essere univoco, nella data ne è già presente un altro");
    }
    for (std::vector<DeepPtr<Event>>::iterator i = Eventi.begin(); i!=Eventi.end() && !flag; ++i)
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
    for (std::vector<DeepPtr<Event>>::iterator i = Eventi.begin(); i!=Eventi.end() && !flag; i++){
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


