#include "eventcreator.h"

CommercialFair *EventCreator::createFair(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork)
{
    return new CommercialFair(loc, titl, empl, rating, exp, d, t, name, numWork);
}

BachelorParty *EventCreator::createBachelor(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance)
{
    return new BachelorParty(loc, titl, empl, rating, exp, d, bG, gue, dance);
}

Marriage *EventCreator::createMarriage(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool bG, u_int gue, bool l, TypeChurch t, u_int fl, u_int nW)
{
    return new Marriage(loc, titl, empl, rating, exp, d, bG, gue, l, t, fl, nW);
}

Tournament *EventCreator::createTournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int compNum, u_int tNumber, std::string name, typeSport tS)
{
    return new Tournament (loc, titl, empl,rating, exp, d, pro, compNum, tNumber,name, tS);
}

Marathon *EventCreator::createMarathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int part, std::string city, double len)
{
    return new Marathon (loc, titl, empl, rating, exp, d, pro, part, city, len);
}
