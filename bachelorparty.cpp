#include "bachelorparty.h"

BachelorParty::BachelorParty() : Wedding(){}

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
    if(json.contains("location")){
        this->setLocation(json["location"].toString().toStdString());
    }

    if(json.contains("title")){
        this->setTitle(json["title"].toString().toStdString());
    }

    if(json.contains("employee")){
        this->setEmployee(json["employee"].toString().toStdString());
    }

    if(json.contains("ratingStars")){
        this->setRating(json["ratingStars"].toInt());
    }

    if(json.contains("experienceEmployee")){
        this->setExp(json["experienceEmployee"].toInt());
    }

    if(json.contains("day") && json.contains("month") && json.contains("year")){
        Date d;
        d.setDay(json["day"].toInt());
        d.setMonth(json["month"].toInt());
        d.setYear(json["year"].toInt());
        this->setDate(d);
    }

    if(json.contains("isMale")){
        setBossGender(json["isMale"].toBool());
    }

    if(json.contains("guest")){
        setGuest(json["guest"].toInt());
    }

    if(json.contains("dancers")){
        this->dancers = json["dancers"].toInt();
    }
}

void BachelorParty::write(QJsonObject &json) const{

    json["location"] = QString::fromStdString(getLocation());
    json["title"] = QString::fromStdString(getTitle());
    json["employee"] = QString::fromStdString(getEmployee());

    json["ratingStars"] = (int) getRating(); //non so se è corretto fare una conversione di questo genere da controllare
    json["experienceEmployee"] = (int) getExperience();

    json["day"] = (int) getDate().getDay();
    json["month"] = (int) getDate().getMonth();
    json["year"] = (int) getDate().getYear();

    json["isMale"] = getBossGender();
    json["guest"] = (int) getGuest();

    json["dancers"] = (int) dancers;
}

double BachelorParty::priceForDancer = 20.50;
double BachelorParty::priceForGuest = 9.90;
