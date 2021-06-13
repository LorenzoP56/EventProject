#include "controller.h"
#include<iostream>

void Controller::showEvent() const
{
    view->updateLabel();
    view->showEvento(model->getEvent(model->getCurrent()));
}

Controller::Controller(QObject *parent) : QObject(parent)
{}

void Controller::setModel(ModelEvent *m){
    model = m;
}

void Controller::setView(EventViewer *v){
    view = v;
}

void Controller::nextEvent() const
{
    if(!checkEmpty()){
        model->nextEvent();
        showEvent();
    }
}

void Controller::previousEvent() const
{
    if(!checkEmpty()){
        model->previousEvent();
        showEvent();
    }
}

void Controller::begin()
{
    if(!checkEmpty()){
        model->firstEvent();
        showEvent();
    }
}

void Controller::last() const
{
    if(!checkEmpty()){
        model->lastEvent();
        showEvent();
    }
}

void Controller::addEvent(std::pair<int, std::vector<QString>> aux) const
{
        switch (aux.first) {
            case 1:
                    model->addNewEventFair(aux.second[0].toStdString(), aux.second[1].toStdString()
                    , aux.second[2].toStdString(), aux.second[3].toInt(), aux.second[4].toInt(),
                    Date(aux.second[5].toInt(), aux.second[6].toInt()), aux.second[7].toStdString() == "Piccola" ? SC : aux.second[7].toStdString() == "Media" ? MC : BC ,
                    aux.second[8].toStdString(), aux.second[9].toInt());
            break;
            case 2: model->addNewEventBachelor(aux.second[0].toStdString(), aux.second[1].toStdString()
                    , aux.second[2].toStdString(), aux.second[3].toInt(), aux.second[4].toInt(),
                    Date(aux.second[5].toInt(), aux.second[6].toInt()), aux.second[8].toStdString() == "Uomo" ? true : false,
                    aux.second[7].toInt(), aux.second[9].toInt());
            break;
            case 3: model->addNewMarriage(aux.second[0].toStdString(), aux.second[1].toStdString()
                    , aux.second[2].toStdString(), aux.second[3].toInt(), aux.second[4].toInt(),
                    Date(aux.second[5].toInt(), aux.second[6].toInt()), aux.second[8].toStdString() == "Uomo" ? true : false,
                    aux.second[7].toInt(), aux.second[9].toStdString() == "yes" ?  true : false ,
                    aux.second[12].toStdString() == "Cristiana" ? cristiana : ortodossa, aux.second[10].toInt(), aux.second[11].toInt());
            break;
            case 4: model->addNewMarathon(aux.second[0].toStdString(), aux.second[1].toStdString()
                    , aux.second[2].toStdString(), aux.second[3].toInt(), aux.second[4].toInt(),
                    Date(aux.second[5].toInt(), aux.second[6].toInt()), aux.second[7].toStdString() == "yes" ?  true : false,
                    aux.second[8].toInt(), aux.second[9].toStdString(), aux.second[10].toDouble());
            break;
            case 5: model->addNewTournament(aux.second[0].toStdString(), aux.second[1].toStdString()
                    , aux.second[2].toStdString(), aux.second[3].toInt(), aux.second[4].toInt(),
                    Date(aux.second[5].toInt(), aux.second[6].toInt()), aux.second[7].toStdString() == "yes" ?  true : false,
                    aux.second[10].toInt(), aux.second[11].toInt(), aux.second[9].toStdString(),
                    aux.second[8].toStdString() == "basket" ? basket : football);
            break;
        }
}

void Controller::removeEvent() const
{
    try {
        if(!checkEmpty()){
            QString title = view->showRemoveEvent();
            std::pair<int, int> aux = model->remove(title.toStdString());
            view->cleanCalendar(QDate(2021, aux.second, aux.first));
            view->clean();
        }
    } catch (std::logic_error* e) {
        view->showWarning(e->what());
    }
}

bool Controller::checkEmpty () const {
    bool empty = false;
    if(model->getNumOfEvent() == 0){
        view -> showWarning("Il calendario è vuoto! Impossibile eseguire operazione richiesta");
        empty = true;
    }
    return empty;
}
void Controller::searchEvent() const{
    try {
        if(!checkEmpty()){
            QString title = view->searchEvent();
            Event* e = model->searchEvent(title.toStdString());
            if(e)
                view->showEvento(e);
            else
                view->showWarning("Nessun evento presente con questo titolo");
        }
    }  catch (std::logic_error* d) {
        view->showWarning(d->what());
    }
}

void Controller::removeAllEvent()
{
    try {
        if(!checkEmpty()){
            model->removeAllEvent();
            view->cleanAllEvent();
        }
    }  catch (std::logic_error* e) {
        view->showWarning(e->what());
    }
}

void Controller::takeEvent(const QDate & d)
{
    Event* aux = model->getEvent(Date(d.day(), d.month()));
    if(aux)
        view->showEvento(aux);
}

void Controller::download() const{

    if(!checkEmpty()){


    QString fileName = QFileDialog::getExistingDirectory(view, tr("Open Directory"),
                                                         "/home",
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    fileName.append("/eventi.json");
    QFile saveFile(fileName);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        view->showWarning("IMPOSSIBILE SALVARE IL FILE");
    }

    QJsonObject eventObject;
    model->write(eventObject);

    QJsonDocument saveDoc(eventObject);
    saveFile.write(saveDoc.toJson());

    view->showWell("Download eventi calendario avvenuto con successo");

    }

}

void Controller::upload(){

    if(model->getNumOfEvent() != 0){
        view->showWarning("Ci sono eventi già salvati nel tuo calendario \nCancellali e riprova");
    }

    else{

        QString fileName = QFileDialog::getOpenFileName(view,tr("File json da importare"),"",tr("Eventi (*.json)"));

        QFile loadFile(fileName);

        if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Errore durante l'importazione del file");
        }

        QByteArray saveData = loadFile.readAll();

        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

        QJsonObject jsonFile = loadDoc.object();

        if(jsonFile.empty()){
            view->showWarning("ERRORE DURANTE L'UPLOAD: file json vuoto");
        }

        else {
            model->read(jsonFile);
            for (unsigned int i = 0; i<model->getNumOfEvent(); ++i){

                view->updateCalendar(QDate(
                                         model->getEvent(i)->getDate().getYear(),
                                         model->getEvent(i)->getDate().getMonth(),
                                         model->getEvent(i)->getDate().getDay()
                                         ));
            }

            if(model->getNumOfEvent() != 0){
                view->showWell("Importazione eventi avvenuta con successo");
                model->lastEvent();
                view->changeCalendarPage(model->getEvent(model->getNumOfEvent()-1)->getDate());
            }
        }
    }
}
