#include "commercialfair.h"

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
            + "\nDa parte della compagnia " + getCompany();
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


double CommercialFair::costByWorkerBig = 5.80;
double CommercialFair::costByWorkerSM = 3.90;
