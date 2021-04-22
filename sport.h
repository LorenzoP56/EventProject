#ifndef SPORT_H
#define SPORT_H

#include<event.h>

class Sport : public Event
{
private:
    bool isPro;
    static double securityPolicyCost;
public:
    Sport();
    Sport(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro);

    bool getPro() const;
    double getSecurityPolicyCost() const;

    /**
     * @brief ovveride funzione virtuale di event per leggere i dati di evento sportivo
     */
    void read (const QJsonObject &json);

    /**
     * @brief ovveride funzione virtuale di event per scrivere i dati di un evento sportivo
     */
    void write (QJsonObject &json) const;
};

#endif // SPORT_H
