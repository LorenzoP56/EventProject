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
    /**
     * @brief metodo che aggiunge un nuovo evento CommercialFair all'interno del container custom in organization
     */
    void addNewEventFair(std::string loc, std::string titl, std::string empl,
                         u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork) const;
    /**
     * @brief metodo che aggiunge un nuovo evento Bachelor all'interno del container custom in organization
     */
    void addNewEventBachelor(std::string loc, std::string titl, std::string empl,
                             u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance) const;
    /**
     * @brief metodo che aggiunge un nuovo evento Marriage all'interno del container custom in organization
     */
    void addNewMarriage(std::string loc, std::string titl, std::string empl,
                        u_int rating, u_int exp, Date d, bool bG,
                        u_int gue, bool l, TypeChurch t, u_int fl, u_int nW) const;
    /**
     * @brief metodo che aggiunge un nuovo evento Tournament all'interno del container custom in organization
     */
    void addNewTournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro,
                          u_int compNum, u_int tNumber, std::string name, typeSport tS) const;
    /**
     * @brief metodo che aggiunge un nuovo evento Marathon all'interno del container custom in organization
     */
    void addNewMarathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d,
                        bool pro, u_int part, std::string city, double len) const;
    /**
     * @brief metodo che rimuove un evento per titolo
     */
    std::pair<int, int> remove(std::string titl) const;

    /**
     * @brief metodi che permettono lo spostamento tra i vari eventi contenuti nel container
     */
    void nextEvent() const;
    void previousEvent() const;
    void firstEvent() const;
    void lastEvent() const;
    /**
     * @brief getter evento in pos index
     * @param index, indice dell' evento da prelevare
     * @return evento prelevato o rilancia std::out_of_range
     */
    Event* getEvent(u_int index) const;
    /**
     * @brief getter current index
     */
    u_int getCurrent() const;
    /**
     * @brief getter per numero di elementi container
     */
    u_int getNumOfEvent() const;
    /**
     * @brief getter evento a seconda della data
     */
    Event* getEvent(const Date&)const;

    void removeAllEvent();

    Event* searchEvent (const std::string &) const;

    void write(QJsonObject &json) const;

    void read (QJsonObject jsonFile);

};

#endif // MODELEVENT_H
