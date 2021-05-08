#ifndef MODELEVENT_H
#define MODELEVENT_H

#include<organization.h>
#include<eventcreator.h>

class ModelEvent
{
private:
    Organization* organization;
public:
    ModelEvent();
    ~ModelEvent();
    void addNewEventFair(std::string loc, std::string titl, std::string empl,
                         u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork) const;
    void addNewEventBachelor(std::string loc, std::string titl, std::string empl,
                             u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance) const;
    void addNewMarriage(std::string loc, std::string titl, std::string empl,
                        u_int rating, u_int exp, Date d, bool bG,
                        u_int gue, bool l, TypeChurch t, u_int fl, u_int nW) const;
    void addNewTournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro,
                          u_int compNum, u_int tNumber, std::string name, typeSport tS) const;
    void addNewMarathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d,
                        bool pro, u_int part, std::string city, double len) const;

    std::pair<int, int> remove(std::string titl) const;
    void nextEvent() const;
    void previousEvent() const;
    void firstEvent() const;
    void lastEvent() const;
    Event* getEvent(u_int index) const;
    u_int getCurrent() const;
    u_int getNumOfEvent() const;
    Event* getEvent(const Date&)const;

    void removeAllEvent();

    void write(QJsonObject &json) const;

    void read (QJsonObject jsonFile);

};

#endif // MODELEVENT_H
