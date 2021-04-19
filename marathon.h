#ifndef MARATHON_H
#define MARATHON_H

#include <sport.h>

class Marathon : public Sport
{
private:

    u_int partecipants;
    std::string town;
    double length;

    static double subPrice;

public:
    Marathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int part, std::string city, double len);

    /**
     * @brief funzione che ritorna il numero di partecipanti iscritti alla maratona
     * @return partecipants
     */
    u_int getPartecipants() const;

    /**
     * @brief funzione che ritorna la città in cui si svolgerà la maratona
     * @return town
     */
    std::string getTown() const;

    /**
     * @brief funzione che ritorna la lunghezza totale del percorso previsto dalla maratona
     * @return length
     */
    double getLength() const;

    /**
     * @brief funzione polimorfa getter costo intero relativo all'evento da richiedere a committente
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
    virtual Marathon* clone() const;
    /**
     * @brief ridifinizione dell'operatore di uguaglianza
     * @return true se sono uguali
     */
    bool operator==(const Marathon&) const;

    /**
     * @brief ovveride funzione virtuale di event per leggere i dati di evento sportivo
     */
    void read (const QJsonObject &json);

    /**
     * @brief ovveride funzione virtuale di event per scrivere i dati di un evento sportivo
     */
    void write (QJsonObject &json) const;
};

#endif // MARATHON_H
