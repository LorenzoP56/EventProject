#ifndef BACHELORPARTY_H
#define BACHELORPARTY_H

#include<wedding.h>

class BachelorParty : public Wedding
{
private:
    u_int dancers;

    static double priceForDancer;
    static double priceForGuest;

public:
    BachelorParty(std::string loc, std::string titl, std::string empl,
                  u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance);

    /**
     * @brief funzione ritorna il numero di ballerine assunte per l'evento
     * @return numero ballerine
     */
    u_int getDancers() const;

    /**
     * @brief funzione polimorfa getter costo intero relativo all'evento da richiedere a committente
     * con sconto del 5% se l'organizzatore è uomo e il numero di invitati è maggiore di 10
     * @return costo evento
     */
    double getCosto() const;

    /**
     * @brief funzione polimorfa getter massima capienza dell'evento
     * compreso del numero di dipendenti assunti per l'evento
     * @return num. massimo di persone ospitate
     */
    u_int getMaxCap() const;

    /**
     * @brief funzione polimorfa che ritorna stringa contenente info più importanti sull'evento
     * @return info
     */
    std::string see() const;
    /**
     * @brief clona oggetto che la richiama
     * @return copia *this
     */
    virtual BachelorParty* clone() const;
    /**
     * @brief ridifinizione dell'operatore di uguaglianza
     * @return true se sono uguali
     */
    bool operator==(const BachelorParty&) const;
};

#endif // BACHELORPARTY_H
