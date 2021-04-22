#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include<sport.h>
#include<typesport.h>

class Tournament : public Sport
{
private:
    u_int componentsNumber;
    u_int teamNumber;
    std::string organizationTeam;
    typeSport tSport;

public:

    Tournament();
    Tournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int compNum, u_int tNumber, std::string name, typeSport tS);

    u_int getComponentsNumber() const;
    u_int getNumberTeams() const;
    std::string getOrganizationTeam () const;
    typeSport getTypeSport () const;

    static double teamSubPrice;

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
    virtual Tournament* clone() const;
    /**
     * @brief ridifinizione dell'operatore di uguaglianza
     * @return true se sono uguali
     */
    bool operator==(const Tournament&) const;

    /**
     * @brief ovveride funzione virtuale di event per leggere i dati di torneo sportivo
     */
    void read (const QJsonObject &json);

    /**
     * @brief ovveride funzione virtuale di event per scrivere i dati di torneo sportivo
     */
    void write (QJsonObject &json) const;
};

#endif // TOURNAMENT_H
