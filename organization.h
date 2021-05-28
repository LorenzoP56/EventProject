#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include<deepptr.h>
#include<container.h>
#include<event.h>
#include<vector>
#include<QJsonArray>
#include<bachelorparty.h>
#include<commercialfair.h>
#include<marriage.h>
#include<marathon.h>
#include<tournament.h>

class Organization
{
private:
    //std::vector<DeepPtr<Event>> Eventi;
    Container<DeepPtr<Event>> Eventi;
    u_int currentEvent;
public:
    Organization();
    /**
     * @brief aggiunta di un evento all'interno del nostro vettore
     * @param DeepPtr<Event>, puntatore smart a Event
     */
    void addEvent(DeepPtr<Event>);
    /**
     * @brief rimozione di un evento all'interno del nostro vettore
     * @param std::string, stringa contenente il titolo univoco dell'evento
     */
    std::pair<int, int> removeEvent(std::string);

    /**
     * @brief va avanti di un evento
     */
    void next();
    /**
     * @brief va dietro di un evento
     */
    void prevoius();
    /**
     * @brief va al primo evento
     */
    void goToStart();
    /**
     * @brief va all'ultimo evento
     */
    void goToEnd();
    /**
     * @brief ritorna size del nostro vettore
     * @return size vettore
     */
    u_int getSize() const;
    /**
     * @brief getter evento in pos index
     * @param index, indice dell' evento da prelevare
     * @return evento prelevato o lancia std::out_of_range con relativo messaggio d'errore
     */
    Event* getEvent(u_int) const;
    /**
     * @brief getter pos current event
     * @return intero della posizione corrente
     */
    u_int getCurrentEvent() const;
    /**
     * @brief getter evento nella data passata
     */
    Event* getEvent(const Date&)const;

    void removeAllEvent();

    Event* searchEvent (const std::string&) const;

    void write(QJsonObject &json) const;

    void read (QJsonObject jsonFile);
};

#endif // ORGANIZATION_H
