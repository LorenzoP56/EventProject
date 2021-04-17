#include<QApplication>
#include<eventviewer.h>
#include<modelevent.h>
#include<controller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EventViewer w;
    Controller c;
    ModelEvent m;

    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);
    w.show();

    return a.exec();
}
