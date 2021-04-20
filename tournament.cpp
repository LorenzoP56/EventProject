#include "tournament.h"

Tournament::Tournament(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro, u_int compNum, u_int tNumber, std::string name, typeSport tS):
                       Sport(loc, titl,empl,rating,exp,d,pro), componentsNumber(compNum), teamNumber(tNumber), organizationTeam(name), tSport(tS)
{}

u_int Tournament::getComponentsNumber() const{
    return componentsNumber;
}

u_int Tournament::getNumberTeams() const {
    return teamNumber;
}

std::string Tournament::getOrganizationTeam() const{
    return organizationTeam;
}

typeSport Tournament::getTypeSport() const{
    return tSport;
}

double Tournament::getCosto() const{
    return getNumberTeams()*teamSubPrice;
}

u_int Tournament::getMaxCap() const{
    return getNumberTeams()*getComponentsNumber();
}

std::string Tournament::see() const{
    std::string tySport = getTypeSport() == 0 ? "basket" : "football";

    return  "\n" + getTitle() +
            "\n Torneo di: " + tySport +
            "\n Si terra' a " + getLocation() + ", in data " +
            getDate().toString() + " con responsabile organizzazione: " + getEmployee() +
            "\n Numero totale squadre iscritte al torneo: " + std::to_string(getNumberTeams()) +
            "\n Costo iscrizione singola squadra: " + std::to_string(teamSubPrice) +
            "\n Costo totale evento: " + std::to_string(getCosto());
}

Tournament *Tournament::clone() const
{
    return new Tournament(*this);
}

bool Tournament::operator==(const Tournament & t) const
{
    return Event::operator==(t) && t.componentsNumber == componentsNumber && t.teamNumber == teamNumber
            && t.organizationTeam == organizationTeam && t.tSport == tSport;
}

void Tournament::read(const QJsonObject &json)
{
    /*
    u_int componentsNumber;
    u_int teamNumber;
    std::string organizationTeam;
    typeSport tSport;*/

    if(json.contains("componentsNumber")){
        componentsNumber = json["componentsNumber"].toInt();
    }

    if(json.contains("teamNumber")){
        teamNumber = json["teamNumber"].toInt();
    }

    if(json.contains("organizationTeam")){
        organizationTeam = json["organizationTeam"].toString().toStdString();
    }

    if(json.contains("tSport")){
        tSport = typeSport(json["tSport"].toInt());
    }
}

void Tournament::write(QJsonObject &json) const{
    json["location"] = QString::fromStdString(getLocation());
    json["title"] = QString::fromStdString(getTitle());
    json["employee"] = QString::fromStdString(getEmployee());

    json["ratingStars"] = (int) getRating(); //non so se è corretto fare una conversione di questo genere da controllare
    json["experienceEmployee"] = (int) getExperience();

    json["day"] = (int) getDate().getDay();
    json["month"] = (int) getDate().getMonth();
    json["year"] = (int) getDate().getYear();

    json["isPro"] = getPro();

    json["componentsNumber"] = (int) componentsNumber;
    json["teamNumber"] = (int) teamNumber;
    json["organizationTeam"] = QString::fromStdString(organizationTeam);
    json["tSport"] = tSport;
}

double Tournament::teamSubPrice = 125;
