#ifndef MARRIAGE_H
#define MARRIAGE_H

#include <wedding.h>
#include <TypeChurch.h>

class Marriage : public Wedding
{
private:
    bool lunch;
    TypeChurch church;
    u_int numFlower;
    u_int numWaiters;

    static double flowerPrice;
    static double bandPrice;
    static double waitersPrice;
    static double priceForGuest;

public:
    Marriage(std::string loc, std::string titl, std::string empl,
                       u_int rating, u_int exp, Date d, bool bG, u_int gue, bool l, TypeChurch t, u_int fl, u_int nW);

    TypeChurch getChurch() const;
    bool isLunch() const;
    u_int getNumFlower() const;
    u_int getNumWaiters() const;
    double getFlowerPrice() const;
    double getBandPrice() const;

    /**
     * @brief funzione polimorfa getter costo intero relativo all'evento da richiedere a committente
     * con sconto del 5% se il numero di invitati è maggiore di 20
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
    virtual Marriage* clone() const;
    /**
     * @brief ridifinizione dell'operatore di uguaglianza
     * @return true se sono uguali
     */
    bool operator==(const Marriage&) const;
};

#endif // MARRIAGE_H
