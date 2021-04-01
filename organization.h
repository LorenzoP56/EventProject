#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include<deepptr.h>
#include<container.h>
#include<event.h>
#include<vector>
class Organization
{
private:
    std::vector<DeepPtr<Event>> Eventi;
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
    Event* removeEvent(std::string);
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
    Event* getEvent(u_int) const;
    u_int getCurrentEvent() const;
};

#endif // ORGANIZATION_H
