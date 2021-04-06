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
#include<eventviewer.h>
#include<container.h>

using namespace std;

int main(int argc, char *argv[])
{
    /*Date a;
    Date b(1,2);
    Event* p = new CommercialFair("milano centro", "Evento dell'anno", "Lorenzo Pillon", 4, 5, b, BC, "Apple", 500);

    Event* m = new Marriage("Dubai","Matrimonio da sogno","Ciccio Pasticcio", 3, 3, a,true, 100, true, cristiana, 30, 50);

    Container<DeepPtr<Event>> z;
    z.push_back(DeepPtr<Event>(p));
    z.push_back(DeepPtr<Event>(m));
    cout<<z[0]->see()<<endl;
    cout<<z[1]->see()<<endl;
    Container<DeepPtr<Event>>::Iterator i = z.begin();
    z.erase(i++);
    //z.remove(0);
    cout<<z[0]->see()<<endl;
    //pp.removeEvent("Evento dell'anno");
    //cout<<"ELIMINAZIONE"<<endl;
    //cout<<pp.Eventi[0]->see()<<endl;
    //cout<<pp.Eventi[1]->see()<<endl;*/

    QApplication a(argc, argv);
    EventViewer w;
    w.show();

    return a.exec();
    //return 0;
}
