#include "eventviewer.h"
#include<iostream>

EventViewer::EventViewer(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    secondLayout = new QHBoxLayout;
    thirdLayout = new QVBoxLayout;
    fourthLayout = new QVBoxLayout;

    addMenus();

    mainLayout->addLayout(secondLayout);
    secondLayout->addLayout(thirdLayout);
    secondLayout->addLayout(fourthLayout);

    addCalendar();

    addLabel();

    addControls();

    setLayout(mainLayout);
    resize(QSize(1024, 720));

    showAddEvent();
    //std::cout<<showRemoveEvent().toUtf8().constData()<<std::endl;
}

void EventViewer::showThisEvent(Event *e) const{

}

void EventViewer::showWarning(const QString & message)
{
    QDialog* error = new QDialog(this);
    error->setLayout(new QHBoxLayout);
    error->layout()->addWidget(new QLabel(message, error));
    error->layout()->setAlignment(Qt::AlignCenter);
    error->setMinimumWidth(120);
    error->setMaximumWidth(450);
    error->setStyleSheet("color:red");

    error->show();
}

std::pair<int, QString *> EventViewer::showAddEvent(){

    /*QString a = QInputDialog::getMultiLineText(this, "Aggiungi Evento", "Titolo: ");
    return a;//creare classe derivata da QDialog*/
    bool ok;
    QStringList list = InputDialog::getStrings(this,&ok,1);
    label->setText(list[0]+"\n"+list[1]);
}

QString EventViewer::showRemoveEvent()
{
    QString titolo = QInputDialog::getText(this, "Rimuovi Evento", "Titolo Evento");
    return titolo;
}

void EventViewer::addMenus()
{
    menuBar = new QMenuBar(this);
    QMenu* file = new QMenu("File", menuBar);
    QMenu* exit = new QMenu("Exit", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(exit);

    file->addAction(new QAction("inserisci", file));
    file->addAction(new QAction("elimina", file));

    exit->addAction(new QAction("exit", exit));

    menuBar->setStyleSheet("background:#f3efe8; color:#383232;");

    mainLayout->addWidget(menuBar);
}

void EventViewer::addCalendar()
{
    calendar = new QCalendarWidget(this);
    calendar->setMinimumDate(QDate(2021, 1, 1));
    calendar->setMaximumDate(QDate(2021, 12, 31));
    calendar->setStyleSheet("background:#f3efe8; color:#383232;");
    QTextCharFormat a = QTextCharFormat();
    a.setFont(QFont("Comic Sans MS"), QTextCharFormat::FontPropertiesAll);
    calendar->setDateTextFormat(QDate(2021, 2,1), a);
    fourthLayout->addWidget(calendar);
}

void EventViewer::addLabel()
{
    label = new QLabel(this);
    label->setText("Evento dell'anno\nPer la compagnia Apple\ninvitati: 500\nPrezzo: 300€\nResponsabile: Nome Cognome");
    label->setStyleSheet("background:#383232; color: #f3efe8; font-size: 15px;");
    fourthLayout->addWidget(label);
}

void EventViewer::addControls()
{
    QPushButton* insertEvent = new QPushButton("inserisci Evento", this);
    QPushButton* dropEvent = new QPushButton("elimina Evento", this);
    QPushButton* nextEvent = new QPushButton("prossimo Evento", this);
    QPushButton* previuosEvent = new QPushButton("precedente Evento", this);
    QPushButton* firstEvent = new QPushButton("primo Evento dell'anno", this);
    QPushButton* lastEvent = new QPushButton("ultimo Evento dell'anno", this);
    QPushButton* download = new QPushButton("scarica calendario", this);
    QPushButton* upload = new QPushButton("inserisci calendario", this);

    thirdLayout->addWidget(insertEvent);
    thirdLayout->addWidget(dropEvent);
    thirdLayout->addWidget(nextEvent);
    thirdLayout->addWidget(previuosEvent);
    thirdLayout->addWidget(firstEvent);
    thirdLayout->addWidget(lastEvent);
    thirdLayout->addWidget(download);
    thirdLayout->addWidget(upload);
}
