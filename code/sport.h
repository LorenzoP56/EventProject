#ifndef SPORT_H
#define SPORT_H

#include<event.h>

class Sport : public Event
{
private:
    bool isPro;
    static double securityPolicyCost;
public:
    Sport(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro);

    bool getPro() const;
    double getSecurityPolicyCost() const;
};

#endif // SPORT_H
