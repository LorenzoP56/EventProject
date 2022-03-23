#ifndef WEDDING_H
#define WEDDING_H

#include<event.h>

class Wedding : public Event
{
private:
    bool isMale;
    u_int guest;
public:
    Wedding(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool bG, u_int gue);
    u_int getGuest() const;
    bool getBossGender() const;
};

#endif // WEDDING_H
