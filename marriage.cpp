#include "marriage.h"
Marriage::Marriage():Wedding(){}

Marriage::Marriage(std::string loc, std::string titl, std::string empl,
                   u_int rating, u_int exp, Date d,bool bG, u_int gue, bool l, TypeChurch t, u_int fl, u_int nW):
    Wedding(loc,titl,empl,rating,exp,d,bG,gue), lunch(l), church(t), numFlower(fl), numWaiters(nW)
{}

TypeChurch Marriage::getChurch() const{
    return church;
}

bool Marriage::isLunch() const{
    return lunch;
}

double Marriage::getFlowerPrice() const{
    return flowerPrice;
}

double Marriage::getBandPrice() const{
    return bandPrice;
}

u_int Marriage::getNumFlower() const {
    return numFlower;
}

u_int Marriage::getNumWaiters() const{
    return numWaiters;
}

double Marriage::getCosto() const{
    double totale = flowerPrice*numFlower + bandPrice + numWaiters*waitersPrice + getGuest()*priceForGuest;
    if(getGuest()>20)//
        return totale-(totale*10)/100;
    else
        return totale;
}

u_int Marriage::getMaxCap() const{
    return getGuest()+getNumWaiters() + 3;//più aggiunta di sposi e parroco
}

std::string Marriage::see() const{
    std::string typeChurch = getChurch() == 0 ? "cristiana" : "ortodossa";
    return getTitle() + "\nSi terra' a " + getLocation() + ", in data " +
            getDate().toString() + " con responsabile organizzazione: " + getEmployee() +
            "\n Numero invitati: " + std::to_string(getGuest()) +
            "\n Chiesa scelta: " + typeChurch +
            "\n Pranzo: " + std::to_string(isLunch()) +
            "\n Costo fiori: " + std::to_string(flowerPrice) +
            "\n Costo camerieri: " + std::to_string(waitersPrice) +
            "\n Costo per invitato: " + std::to_string(priceForGuest) +
            "\n Costo band: " + std::to_string(bandPrice);
}

Marriage *Marriage::clone() const
{
    return new Marriage(*this);
}

bool Marriage::operator==(const Marriage & c) const
{
    return  Event::operator==(c) && c.lunch == lunch &&
            c.church == church &&
            c.numFlower == numFlower && c.numWaiters == numWaiters;
}

void Marriage::read(const QJsonObject &json){

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

    if(json.contains("lunch")){
        lunch = json["lunch"].toBool();
    }

    if(json.contains("church")){
        church = TypeChurch(json["church"].toInt());
    }

    if(json.contains("numFlower")){
        numFlower = json["numFlower"].toInt();
    }

    if(json.contains("numWaiters")){
        numWaiters = json["numWaiters"].toInt();
    }
}

void Marriage::write(QJsonObject &json) const{
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

    json["lunch"] = lunch;
    json["church"] = church;
    json["numFlower"] = (int) numFlower;
    json["numWaiters"] = (int) numWaiters;
}

double Marriage::flowerPrice = 4.95;
double Marriage::bandPrice = 890;
double Marriage::waitersPrice = 24.90;
double Marriage::priceForGuest = 45;
