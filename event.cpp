#include "event.h"

Event::Event(){}

Event::Event(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d): location(isEmpty(loc) ? "milano": loc),
    title(isEmpty(titl)? "evento generico" : titl), employee(isEmpty(empl) ? "Lorenzo Pillon" : empl),
    ratingStars(rating > 5? 5 : rating), experienceEmployee(exp > 5? 5 : exp), date(d)
{
    checkExp();//controllo esperienza lavoratore lancio eccezione se non sufficiente
}

std::string Event::getLocation() const
{
    return location;
}

u_int Event::getRating() const
{
    return ratingStars;
}

Date Event::getDate() const
{
    return date;
}

std::string Event::getTitle() const
{
    return title;
}

void Event::setLocation(std::string loc)
{
    location = loc;
}

void Event::setRating(u_int rating)
{
    if(rating > 5)
        throw std::logic_error("numero di stelle inserite eccedenti il range da 0 a 5");
    ratingStars = rating;
}

void Event::setTitle(std::string titl)
{
    if(isEmpty(titl))
        throw std::logic_error("titolo non puo essere vuoto");
    title = titl;
}

void Event::setDate(Date d)
{
    date = d;
}

std::string Event::getEmployee() const
{
    return employee;
}

u_int Event::getExperience() const
{
    return experienceEmployee;
}

void Event::setEmployee(std::string imp)
{
    if(isEmpty(imp))
        throw std::logic_error("nome organizzatore non puo essere vuoto");
    employee = imp;
}

void Event::setExp(u_int exp)
{
    if(exp < getRating())
        throw new RatingError(getEmployee(), getRating() - getExperience());
    experienceEmployee = exp > 5 ? 5 : exp;
}

bool Event::equals(const Event & e) const
{
    return e.location == location && e.title == title && e.employee == employee &&
            e.ratingStars == ratingStars && e.experienceEmployee == experienceEmployee &&
            e.date == date;
}

bool Event::operator==(const Event &e) const
{
    return location == e.location && title == e.title && e.employee == employee
            && e.ratingStars == ratingStars && e.experienceEmployee == experienceEmployee
            && e.date == date;
}

bool Event::isEmpty(std::string s)
{
    return s.size() == 0;
}

void Event::checkExp() const
{
    if(getExperience() < getRating())
        throw new RatingError(getEmployee(), getRating() - getExperience());
}


void Event::read(const QJsonObject &json){

    if(json.contains("location")){
        location = json["location"].toString().toStdString();
    }

    if(json.contains("title")){
        title = json["title"].toString().toStdString();
    }

    if(json.contains("employee")){
        employee = json["employee"].toString().toStdString();
    }

    if(json.contains("ratingStars")){
        ratingStars = json["ratingStars"].toInt();
    }

    if(json.contains("experienceEmployee")){
        experienceEmployee = json["experienceEmployee"].toInt();
    }

    if(json.contains("day")){
        date.setDay(json["day"].toInt());
    }

    if(json.contains("month")){
        date.setMonth(json["month"].toInt());
    }

    if(json.contains("year")){
        date.setYear(json["year"].toInt());
    }
}


void Event::write(QJsonObject &json) const{

    json["location"] = QString::fromStdString(location);
    json["title"] = QString::fromStdString(title);
    json["employee"] = QString::fromStdString(employee);

    json["ratingStars"] = (int) ratingStars; //non so se è corretto fare una conversione di questo genere da controllare
    json["experienceEmployee"] = (int) experienceEmployee;

    json["day"] = (int) date.getDay();
    json["month"] = (int) date.getMonth();
    json["year"] = (int) date.getYear();
}

