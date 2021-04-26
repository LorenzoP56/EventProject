#include "sport.h"

Sport::Sport():Event(){}

Sport::Sport(std::string loc, std::string titl, std::string empl, u_int rating, u_int exp, Date d, bool pro)
            : Event(loc, titl, empl, rating, exp, d), isPro(pro) {}

bool Sport::getPro() const {
    return isPro;
}

void Sport::setPro (bool pro){
    isPro = pro;
}
double Sport::getSecurityPolicyCost() const {
    return securityPolicyCost;
}

void Sport::read(const QJsonObject &json){
    if(json.contains("isPro")){
        isPro = json["isPro"].toBool();
    }
}

void Sport::write(QJsonObject &json) const{
    json["isPro"] = isPro;
}

double Sport::securityPolicyCost = 1250;
