#include "marathon.h"

Marathon::Marathon():Sport(){}

Marathon::Marathon(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int part, std::string city, double len)
    :Sport(loc, titl, empl,rating,exp,d,pro), partecipants(part), town(city),length(len)
{}

u_int Marathon::getPartecipants() const{
    return partecipants;
}

std::string Marathon::getTown() const{
    return town;
}

double Marathon::getLength() const {
    return length;
}

double Marathon::getCosto() const{
    return subPrice*getPartecipants();
}

u_int Marathon::getMaxCap() const{
    return getPartecipants()+20; //dipendenti assunti per organizzare l'evento
}

std::string Marathon::see() const{
    return getTitle() + "\nSi terra' a " + getLocation() + ", "+ getTown() +", in data " +
            getDate().toString() + " con responsabile organizzazione: " + getEmployee() +
            "\n Numero totale iscritti alla corsa: " + std::to_string(getPartecipants()) +
            "\n Costo iscrizione singolo: " + std::to_string(subPrice) +
            "\n Costo totale evento: " + std::to_string(getCosto()) +
            "\n Chilometri totali da percorrere: " + std::to_string(getLength());
}

Marathon *Marathon::clone() const
{
    return new Marathon(*this);
}

bool Marathon::operator==(const Marathon & m) const
{
    return Event::operator==(m) && m.partecipants == partecipants && m.town == town && m.length == length;
}

void Marathon::read(const QJsonObject &json){
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

    if(json.contains("isPro")){
        setPro(json["isPro"].toBool());
    }

    if(json.contains("partecipants")){
        partecipants = json["partecipants"].toInt();
    }

    if(json.contains("town")){
        town = json["town"].toString().toStdString();
    }

    if(json.contains("length")){
        length = json["length"].toDouble();
    }
}

void Marathon::write(QJsonObject &json) const{
    json["location"] = QString::fromStdString(getLocation());
    json["title"] = QString::fromStdString(getTitle());
    json["employee"] = QString::fromStdString(getEmployee());

    json["ratingStars"] = (int) getRating(); //non so se è corretto fare una conversione di questo genere da controllare
    json["experienceEmployee"] = (int) getExperience();

    json["day"] = (int) getDate().getDay();
    json["month"] = (int) getDate().getMonth();
    json["year"] = (int) getDate().getYear();

    json["isPro"] = getPro();
    json["partecipants"] = (int) partecipants;
    json["town"] = QString::fromStdString (town);
    json["length"] = length;
}

double Marathon::subPrice = 5.90;

