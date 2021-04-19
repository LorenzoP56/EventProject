#include "bachelorparty.h"

BachelorParty::BachelorParty(std::string loc, std::string titl, std::string empl,
    u_int rating, u_int exp, Date d, bool bG, u_int gue, u_int dance):
    Wedding(loc,titl,empl,rating,exp,d,bG,gue),dancers(dance)
{}

u_int BachelorParty::getDancers() const{return dancers;}

double BachelorParty::getCosto() const{
    double total = getGuest()*priceForGuest + getDancers()*priceForDancer;

    if(getBossGender() && getGuest() > 10){ //applica sconto 5% se l'organizzatore è uomo e il numero di invitati è maggiore di 10
        return total-(total*5)/100;
    }
    else return total;
}

u_int BachelorParty::getMaxCap() const{
    return getDancers() + getGuest() + 1;//più il festeggiato
}

std::string BachelorParty::see() const{
    return getTitle() + "\nSi terra' a " + getLocation() + ", in data " +
            getDate().toString() + " con responsabile organizzazione: " + getEmployee() +
            "\n Numero invitati: " + std::to_string(getGuest()) +
            "\n Numero ballerine: " + std::to_string(getDancers()) +
            "\n Costo per invitato: " + std::to_string(priceForGuest) +
            "\n Costo per ballerina: " + std::to_string(priceForDancer);
}

BachelorParty *BachelorParty::clone() const
{
    return new BachelorParty(*this);
}

bool BachelorParty::operator==(const BachelorParty & b) const
{
    return Event::operator==(b) && b.dancers == dancers;
}

void BachelorParty::read(const QJsonObject &json){
    if(json.contains("dancers")){
        dancers = json["dancers"].toInt();
    }
}

void BachelorParty::write(QJsonObject &json) const{
    json["dancers"] = (int) dancers;
}

double BachelorParty::priceForDancer = 20.50;
double BachelorParty::priceForGuest = 9.90;
