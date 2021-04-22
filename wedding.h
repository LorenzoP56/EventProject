#ifndef WEDDING_H
#define WEDDING_H

#include<event.h>

class Wedding : public Event
{
private:
    bool isMale;
    u_int guest;
public:
    Wedding();
    Wedding(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool bG, u_int gue);
    u_int getGuest() const;
    bool getBossGender() const;

    void setBossGender(bool g);
    void setGuest(u_int g);
    /**
     * @brief ovveride funzione virtuale di event per leggere i dati di un wedding
     */
    void read (const QJsonObject &json);

    /**
     * @brief ovveride funzione virtuale di event per scrivere i dati di un wedding
     */
    void write (QJsonObject &json) const;
};

#endif // WEDDING_H
