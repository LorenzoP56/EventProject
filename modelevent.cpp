#include "modelevent.h"

ModelEvent::ModelEvent():organization(new Organization){}

ModelEvent::~ModelEvent(){
    delete organization;
}

void ModelEvent::addNewEventFair(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork) const{
    EventCreator creator;
    Event* newEvent = creator.createFair(loc,titl,empl,rating,exp,d,t,name,numWork);
    organization->addEvent(newEvent);
}

void ModelEvent::addNewEventBachelor(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance) const{
    EventCreator creator;
    Event* newEvent = creator.createBachelor(loc,titl,empl,rating, exp,d,bG,gue,dance);
    organization->addEvent(newEvent);
}

void ModelEvent::addNewMarriage(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool bG, u_int gue, bool l, TypeChurch t, u_int fl, u_int nW) const{
    EventCreator creator;
    Event* newEvent = creator.createMarriage(loc,titl,empl,rating,exp,d,bG,gue,l,t,fl,nW);
    organization->addEvent(newEvent);
}

void ModelEvent::addNewTournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int compNum, u_int tNumber, std::string name, typeSport tS) const{
    EventCreator creator;
    Event* newEvent = creator.createTournament(loc,titl,empl,rating,exp,d,pro,compNum,tNumber,name,tS);
    organization->addEvent(newEvent);
}

void ModelEvent::addNewMarathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int part, std::string city, double len) const{
    EventCreator creator;
    Event* newEvent = creator.createMarathon(loc,titl,empl,rating,exp,d,pro,part,city,len);
    organization->addEvent(newEvent);
}

void ModelEvent::remove(std::string titl) const{
    organization->removeEvent(titl);
}
void ModelEvent::nextEvent() const{
    organization->next();
}
void ModelEvent::previousEvent() const{
    organization->prevoius();
}
void ModelEvent::firstEvent() const{
    organization->goToStart();
}
void ModelEvent::lastEvent() const{
    organization->goToEnd();
}
Event* ModelEvent::getEvent(u_int index) const{
    return organization->getEvent(index);
}
u_int ModelEvent::getCurrent() const{
    return organization->getCurrentEvent();
}
u_int ModelEvent::getNumOfEvent() const{
    return organization->getSize();
}





