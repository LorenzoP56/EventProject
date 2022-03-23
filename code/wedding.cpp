#include "wedding.h"

Wedding::Wedding(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool bG, u_int gue):
    Event(loc, titl, empl, rating, exp, d),
    isMale(bG), guest(gue)
{}

bool Wedding::getBossGender() const {return isMale;}

u_int Wedding::getGuest() const {return guest;}
