#ifndef EVENT_H
#define EVENT_H
#include<string>
#include<date.h>
#include<ratingerror.h>
#include <QJsonObject>

class Event
{
private:
    std::string location, title, employee;
    u_int ratingStars, experienceEmployee;
    Date date;
    /**
     * @brief funzione statica che ritorna true se la stringa passatale è vuota
     * @param s: stringa su cui avviene il controllo
     * @return true nel caso la stringa sia vuota else viceversa
     */
    static bool isEmpty(std::string s);
    void checkExp() const;
public:
    virtual double getCosto() const = 0;
    virtual u_int getMaxCap() const = 0;
    virtual std::string see() const = 0;

    Event();
    Event(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d);

    virtual ~Event() = default;
    /**
     * @brief getter nome location dell'evento
     * @return location
     */
    std::string getLocation() const;
    /**
     * @brief getter numero stelle di valutazione gestione evento
     * @return rating evento
     */
    u_int getRating() const;
    /**
     * @brief getter data evento(DD,MM,YY,HH);
     * @return data evento
     */
    Date getDate() const;
    /**
     * @brief getter titolo univoco evento
     * @return titolo
     */
    std::string getTitle() const;
    /**
     * @brief setter location evento
     * @param loc: location in cui avviene evento
     */
    void setLocation(std::string loc);
    /**
     * @brief setter rating di valutazione dell' evento
     * @param rating: numero stelle di difficoltà organizzazione e gestione dell'evento
     */
    void setRating(u_int rating);
    /**
     * @brief setter titolo evento
     * @param titl: titolo dell' evento organizzato
     */
    void setTitle(std::string titl);
    /**
     * @brief setter data evento
     * @param d: data evento
     */
    void setDate(Date d);
    /**
     * @brief getter impiegato incaricato di gestire l'evento
     * @return impiegato incaricato
     */
    std::string getEmployee() const;
    /**
     * @brief getter esperienza dell'impiegato organizzatore dell'evento
     * @return esperienza dell'impiegato
     */
    u_int getExperience() const;
    /**
     * @brief setter impiegato organizzatore dell'evento
     * @param imp: impiegato
     */
    void setEmployee(std::string imp);
    /**
     * @brief setter esperienza organizzatore dell'evento
     * @param exp: esperienza impiegato
     */
    void setExp(u_int exp);
    /**
     * @brief clona oggetto che la richiama
     * @return copia *this
     */
    virtual Event* clone() const = 0;
    /**
     * @brief controllo su uguaglianza
     * @return true se sono uguali
     */
    bool equals(const Event&) const;
    /**
     * @brief ridifinizione dell'operatore di uguaglianza
     * @return true se sono uguali
     */
    virtual bool operator==(const Event&) const;

    /**
     * @brief funzione virtuale per la lettura di un file json degli eventi
     */
    virtual void read (const QJsonObject &json);

    /**
     * @brief funzione virtuale per la scrittura in un file json degli eventi
     */
    virtual void write (QJsonObject &json) const;
};

#endif // EVENT_H
