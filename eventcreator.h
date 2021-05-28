#ifndef EVENTCREATOR_H
#define EVENTCREATOR_H

#include<commercialfair.h>
#include<bachelorparty.h>
#include<marriage.h>
#include<tournament.h>
#include<marathon.h>

class EventCreator
{
public:
    /**
     * @brief metodo che costruisce un oggetto di tipo CommercialFair
     * @return puntatore a CommercialFair
     */
    CommercialFair* createFair(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork);
    /**
     * @brief metodo che costruisce un oggetto di tipo BachelorParty
     * @return puntatore a BachelorParty
     */
    BachelorParty* createBachelor(std::string loc, std::string titl, std::string empl,
                                  u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance);
    /**
     * @brief metodo che costruisce un oggetto di tipo Marriage
     * @return puntatore a Marriage
     */
    Marriage* createMarriage(std::string loc, std::string titl, std::string empl,
                             u_int rating, u_int exp, Date d, bool bG, u_int gue, bool l, TypeChurch t, u_int fl, u_int nW);
    /**
     * @brief metodo che costruisce un oggetto di tipo Tournament
     * @return puntatore a Tournamnet
     */
    Tournament* createTournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int compNum, u_int tNumber, std::string name, typeSport tS);
    /**
     * @brief metodo che costruisce un oggetto di tipo Marathon
     * @return puntatore a Marathon
     */
    Marathon* createMarathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int part, std::string city, double len);

};

#endif // EVENTCREATOR_H
