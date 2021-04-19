#include "marriage.h"

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
    json["lunch"] = lunch;
    json["church"] = church;
    json["numFlower"] = (int) numFlower;
    json["numWaiters"] = (int) numWaiters;
}

double Marriage::flowerPrice = 4.95;
double Marriage::bandPrice = 890;
double Marriage::waitersPrice = 24.90;
double Marriage::priceForGuest = 45;
