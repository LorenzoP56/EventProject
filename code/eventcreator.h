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
    CommercialFair* createFair(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork);
    BachelorParty* createBachelor(std::string loc, std::string titl, std::string empl,
                                  u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance);
    Marriage* createMarriage(std::string loc, std::string titl, std::string empl,
                             u_int rating, u_int exp, Date d, bool bG, u_int gue, bool l, TypeChurch t, u_int fl, u_int nW);
    Tournament* createTournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int compNum, u_int tNumber, std::string name, typeSport tS);

    Marathon* createMarathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int part, std::string city, double len);

};

#endif // EVENTCREATOR_H
