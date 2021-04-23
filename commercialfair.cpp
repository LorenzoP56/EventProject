#include "commercialfair.h"

CommercialFair::CommercialFair():Event(){}

CommercialFair::CommercialFair(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, Company t, std::string name, u_int numWork):
    Event(loc, titl, empl, rating, exp, d),
    type(t), companyName(name), numWorkers(numWork)
{}

double CommercialFair::getCosto() const
{
    return type==0 || type==1 ? costByWorkerSM*numWorkers + costByWorkerSM*numWorkers*30/100 :
                                costByWorkerBig*numWorkers + costByWorkerBig*numWorkers*30/100;//più commissione del 30%
}

u_int CommercialFair::getMaxCap() const
{
    return numWorkers + 2;//lavoratori + organizzatore evento + insegnante
}

std::string CommercialFair::see() const
{
    return getTitle() + "\nSi terra' a " + getLocation() + ", in data " +
            getDate().toString() + " con responsabile organizzazione: " + getEmployee()
            + "\nDa parte della compagnia: " + getCompany();
}

std::string CommercialFair::getCompany() const
{
    return companyName;
}

CommercialFair *CommercialFair::clone() const
{
    return new CommercialFair(*this);
}

bool CommercialFair::operator==(const CommercialFair & c) const
{
    return Event::operator==(c) &&
            c.type == type && c.companyName == companyName && c.numWorkers == numWorkers;
}

void CommercialFair::read (const QJsonObject &json){

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

    if(json.contains("type")){
        type = Company(json["type"].toInt());
    }

    if(json.contains("companyName")){
        companyName = json["companyName"].toString().toStdString();
    }

    if(json.contains("numWorkers")){
        numWorkers = json["numWorkers"].toInt();
    }
}

void CommercialFair::write(QJsonObject &json) const{
    json["location"] = QString::fromStdString(getLocation());
    json["title"] = QString::fromStdString(getTitle());
    json["employee"] = QString::fromStdString(getEmployee());

    json["ratingStars"] = (int) getRating(); //non so se è corretto fare una conversione di questo genere da controllare
    json["experienceEmployee"] = (int) getExperience();

    json["day"] = (int) getDate().getDay();
    json["month"] = (int) getDate().getMonth();
    json["year"] = (int) getDate().getYear();

    json["type"] = type;
    json["companyName"] = QString::fromStdString(companyName);
    json["numWorkers"] = (int) numWorkers;
}

double CommercialFair::costByWorkerBig = 5.80;
double CommercialFair::costByWorkerSM = 3.90;
