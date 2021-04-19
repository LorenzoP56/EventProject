#include "marathon.h"

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
    json["partecipants"] = (int) partecipants;
    json["town"] = QString::fromStdString (town);
    json["length"] = length;
}

double Marathon::subPrice = 5.90;

