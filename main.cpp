#include<iostream>
#include <QApplication>
#include<date.h>
#include<event.h>
#include<commercialfair.h>
#include<bachelorparty.h>
#include<marriage.h>
#include<eventcreator.h>
#include<marathon.h>
#include<tournament.h>
#include<deepptr.h>
#include<utility>
#include<organization.h>

using namespace std;

int main(int argc, char *argv[])
{
    Date a;
    Date b(1,2);
    Event* p = new CommercialFair("milano centro", "Evento dell'anno", "Lorenzo Pillon", 4, 5, b, BC, "Apple", 500);

    Event* m = new Marriage("Dubai","Matrimonio da sogno","Ciccio Pasticcio", 3, 3, a,true, 100, true, cristiana, 30, 50);

    vector<DeepPtr<Event>> z;
    Organization pp;
    pp.addEvent(DeepPtr<Event>(p));
    pp.addEvent(DeepPtr<Event>(m));
    /*cout<<pp.Eventi[0]->see()<<endl;
    cout<<pp.Eventi[1]->see()<<endl;*/
    pp.removeEvent("Evento dell'anno");
    cout<<"ELIMINAZIONE"<<endl;
    //cout<<pp.Eventi[0]->see()<<endl;
    //cout<<pp.Eventi[1]->see()<<endl;

    return 0;//da togliere
}
