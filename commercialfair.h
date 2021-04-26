#ifndef COMMERCIALFAIR_H
#define COMMERCIALFAIR_H

#include<company.h>
#include<event.h>

class CommercialFair : public Event
{
private:
    Company type;
    std::string companyName;
    u_int numWorkers;
    static double costByWorkerBig;
    static double costByWorkerSM;
public:
    CommercialFair();
    CommercialFair(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork);
    /**
     * @brief funzione polimorfa getter costo intero relativo all'evento da richiedere a committente
     * @return costo evento
     */
    double getCosto() const;
    /**
     * @brief funzione polimorfa getter massima capienza dell'evento
     * @return num. massimo di persone ospitate
     */
    u_int getMaxCap() const;
    /**
     * @brief funzione polimorfa che ritorna stringa contenente info più importanti sull'evento
     * @return info
     */
    std::string see() const;
    /**
     * @brief getter nome società che ci ha incaricati
     * @return nome società
     */
    std::string getCompany() const;
    /**
     * @brief clona oggetto che la richiama
     * @return copia *this
     */
    virtual CommercialFair* clone() const;
    /**
     * @brief ridifinizione dell'operatore di uguaglianza
     * @return true se sono uguali
     */
    bool operator==(const CommercialFair&) const;

    /**
     * @brief ovveride funzione virtuale di event per leggere i dati di una fiera
     */
    void read (const QJsonObject &json);

    /**
     * @brief ovveride funzione virtuale di event per scrivere i dati di una fiera
     */
    void write (QJsonObject &json) const;
};

#endif // COMMERCIALFAIR_H
