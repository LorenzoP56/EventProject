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
#include<container.h>
#include<deepptr.h>
#include<utility>

using namespace std;

int main(int argc, char *argv[])
{
    Date a;
    Event* p = new CommercialFair("milano centro", "Evento dell'anno", "Lorenzo Pillon", 4, 5, a, BC, "Apple", 500);
    //CommercialFair b("milano centro", "Evento dell'anno", "Lorenzo Pillon", 4, 5, a, BC, "Apple", 500);
    /*cout<<p->see()<<endl;
    cout<<"con costo: "<<p->getCosto()<<" euro"<<endl;
    cout<<"massima capienza = "<<p->getMaxCap()<<endl;

    Event* q = new BachelorParty("New York", "Ultima serata scapolo", "Matteo Piran",5, 5, a, true, 11, 20);
    cout<<q->see()<<endl;
    cout<<"massima capienza bachelor = "<<q->getMaxCap()<<endl;
    cout<<"con costo totale: "<<q->getCosto()<<" euro"<<endl;*/

    Event* m = new Marriage("Dubai","Matrimonio da sogno","Ciccio Pasticcio", 3, 3, a,true, 100, true, cristiana, 30, 50);
    /*cout<<m->see()<<endl;
    cout<<"con costo: "<<m->getCosto()<<" euro"<<endl;
    cout<<"massima capienza = "<<m->getMaxCap()<<endl;*//*

    EventCreator creatore;
    try{
        Event* cre = creatore.createFair("Empoli", "Titolo di Prova", "Billy", 5, 2, a, BC, "Appple", 500);
    cout<<cre->getExperience()<<endl;
    }
    catch (RatingError* error) {
        cout<<error->what()<<endl;
        cout<<error->Employee()<<endl;
    }

    Event* mar = new Marathon("Padova","Corsa della pace","Filè Gilberto", 1, 4, a, true, 100, "Prato della valle", 12.75);
    cout<<mar->see()<<endl;
    cout<<"massima capienza: "<<mar->getMaxCap()<<endl;

    Event* t = new Tournament("Tokyo","Olimpiadi","Kim Jong Yu", 1, 4, a, true, 11, 19, "ASD TOKYO", football);
    cout<<t->see()<<endl;
    cout<<" massima capienza: "<<t->getMaxCap()<<endl;*/

    Container<DeepPtr<Event>> z;
    vector<DeepPtr<Event>> zreal;
    DeepPtr<Event> zz(p);
    //z.push_back(zz);
    zreal.push_back(zz);
    cout<<zreal[0]->see()<<endl;
    //cout<<z[0]->see();
    DeepPtr<Event> zz2(m);
    if(zz != zz2)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    cout<<zz2->see();

    return 0;//da togliere
}
