#ifndef DATE_H
#define DATE_H
#include<stdexcept>
#include<string>

typedef unsigned int u_int;

class Date
{
private:
    u_int day, month, year, start;
    /**
     * @brief getter numero giorni a seconda del mese
     * @return num. giorni in month
     */
    u_int getMaxDayForMonth() const;
public:
    Date(u_int=1, u_int=1,u_int=2021, u_int=9);
    /**
     * @brief setter per il giorno dell'evento
     * @param day : giorno dell'evento
     */
    void setDay(u_int day);
    /**
     * @brief setter per il mese dell'evento
     * @param mon : mese dell'evento
     */
    void setMonth(u_int month);
    /**
     * @brief setter per l' anno dell'evento
     * @param year : anno dell'evento
     */
    void setYear(u_int year);
    /**
     * @brief setter per orario inizio dell'evento
     * @param start : inizio dell'evento
     */
    void setStart(u_int start);
    /**
     * @brief getter del giorno dell'evento
     * @return giorno evento
     */
    u_int getDay() const;
    /**
     * @brief getter del mese dell'evento
     * @return mese evento
     */
    u_int getMonth() const;
    /**
     * @brief getter del giorno dell'evento
     * @return giorno evento
     */
    u_int getYear() const;
    /**
     * @brief getter del giorno dell'evento
     * @return giorno evento
     */
    u_int getStart() const;
    /**
     * @brief ridefinizione operatore minore
     * @return se nostro oggetto è minore di d
     */
    bool operator<(const Date& d) const;
    /**
     * @brief ridefinizione operatore maggiore
     * @return se nostro oggetto è maggiore di d
     */
    bool operator>(const Date& d) const;
    /**
     * @brief ridefinizione operatore uguaglianza
     * @return nostro oggetto è uguale a d
     */
    bool operator==(const Date& d) const;
    /**
     * @brief funzioine che trasforma data in una data in versione stringa
     * @return data in versione stringa
     */
     std::string toString()const;
};

#endif // DATE_H
