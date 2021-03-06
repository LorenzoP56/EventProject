#include "eventviewer.h"
#include<iostream>
#include "controller.h"

EventViewer::EventViewer(QWidget *parent) : QWidget(parent){

    mainLayout = new QVBoxLayout;
    lblCalendarLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;
    lineLayout = new QVBoxLayout;

    addMenus();

    addLabel();

    addCalendar();

    addLine();

    addControls();



    setLayout(mainLayout);
    resize(QSize(1024, 720));
}

void EventViewer::showWarning(const QString & message) const
{
    QDialog* error = new QDialog();
    error->setLayout(new QHBoxLayout);
    error->layout()->addWidget(new QLabel(message, error));
    error->layout()->setAlignment(Qt::AlignCenter);
    error->setMinimumWidth(120);
    error->setMaximumWidth(450);
    error->setStyleSheet("color:red");

    error->show();
}

void EventViewer::showEvento(Event *event)
{
    QString visualizza = QString::fromStdString(event->see() + "\nAl prezzo di: " +
                                                std::to_string(event->getCosto()) + "\nCon capienza massima: " +
                                                std::to_string(event->getMaxCap()));
    label->setText(visualizza);
}

void EventViewer::showAddEvent(){
    InputDialog* dialog = new InputDialog(this);
    dialog->show();
}

void EventViewer::showAddEventB()
{
    InputDialogB* dialog = new InputDialogB(this);
    dialog->show();
}

void EventViewer::showAddEventMarriage()
{
    InputDialogMarriage* dialog = new InputDialogMarriage(this);
    dialog->show();
}

void EventViewer::showAddEventMarathon()
{
    InputDialogMarathon* dialog = new InputDialogMarathon(this);
    dialog->show();
}

void EventViewer::showAddEventTournament()
{
    InputDialogT* dialog = new InputDialogT(this);
    dialog->show();
}

QString EventViewer::showRemoveEvent()
{
    QString titolo = QInputDialog::getText(this, "Rimuovi Evento", "Titolo evento che vuoi rimuovere");
    return titolo;
}

void EventViewer::finish(std::pair<int, std::vector<QString>> aux) const
{
    try {
        controller->addEvent(aux);
        calendar->addEvent(QDate(2021, aux.second[6].toInt(), aux.second[5].toInt()));
    } catch (RatingError* e) {
        showWarning(e->what());
    }
    catch (std::logic_error* e) {
        showWarning(e->what());
    }
}

void EventViewer::clean()
{
    label->setText("");
}

void EventViewer::addMenus(){
    menuBar = new QMenuBar(this);
    file = new QMenu("File", menuBar);
    exit = new QMenu("Calendario", menuBar);
    control = new QMenu("Controlli", menuBar);

    menuBar->addMenu(exit);
    menuBar->addMenu(file);
    menuBar->addMenu(control);

    inserisci = file->addMenu("Inserisci nuovo evento");
    file->addAction(new QAction("Elimina"));

    inserisci->addAction(new QAction("Fiera"));
    inserisci->addAction(new QAction("Bachelor"));
    inserisci->addAction(new QAction("Marriage"));
    inserisci->addAction(new QAction("Tournament"));
    inserisci->addAction(new QAction("Marathon"));

    exit->addAction(new QAction("Esporta eventi"));
    exit->addAction(new QAction("Importa eventi"));
    exit->addAction(new QAction("Termina programma"));

    control->addAction(new QAction("Prossimo"));
    control->addAction(new QAction("Precedente"));
    control->addAction(new QAction("Primo"));
    control->addAction(new QAction("Ultimo"));

    menuBar->setStyleSheet("background:#f3efe8; color:#383232;");

    mainLayout->addWidget(menuBar);
}

void EventViewer::addCalendar()
{

    calendar = new MyCalendarWidget(this);

    calendar->setMinimumDate(QDate(2021, 1, 1));
    calendar->setMaximumDate(QDate(2021, 12, 31));
    calendar->setStyleSheet("background:#f3efe8; color:#383232;");

    lblCalendarLayout->addWidget(calendar);

    mainLayout->addLayout(lblCalendarLayout);


}

void EventViewer::addLabel(){

    QHBoxLayout* headerHLayout = new QHBoxLayout;

    QVBoxLayout* headerVLayout = new QVBoxLayout;

    QVBoxLayout* lblVLayout = new QVBoxLayout;

    QFont font;

    QLabel* lblDay = new QLabel(this);
    lblDay->setText("1");
    font = lblDay->font();
    font.setPointSize(72);
    font.setBold(true);
    lblDay->setContentsMargins(25,0,0,0);
    lblDay->setFont (font);

    QLabel* lblMounth = new QLabel(this);
    lblMounth->setText("APRILE 2021");
    font = lblMounth->font();
    font.setPointSize(24);
    lblMounth->setFont(font);

    QLabel* lblWeekDay = new QLabel(this);
    lblWeekDay->setText("GIOVEDI'");
    font = lblMounth->font();
    font.setPointSize(32);
    lblWeekDay->setFont(font);


    headerVLayout->addWidget(lblWeekDay,60);
    headerVLayout->addWidget(lblMounth,40);
    headerVLayout->setMargin(0);
    headerVLayout->setContentsMargins(0,0,25,0);

    headerHLayout->addWidget(lblDay);

    headerHLayout->addLayout(headerVLayout);

    lblVLayout->addLayout(headerHLayout,20);

    label = new QLabel(this);

    label->setMargin(25);
    label->setStyleSheet("background:#383232; color: #f3efe8; font-size: 15px;");

    lblVLayout->addWidget(label,80);

    lblCalendarLayout->addLayout(lblVLayout);
}

void EventViewer::addControls()
{

    previuosEvent = new QPushButton("Precedente evento", this);
    nextEvent = new QPushButton("Prossimo evento", this);
    firstEvent = new QPushButton("Primo evento dell'anno", this);
    lastEvent = new QPushButton("Ultimo evento dell'anno", this);
    download = new QPushButton("Scarica calendario", this);
    upload = new QPushButton("Inserisci calendario", this);

    buttonLayout->addWidget(previuosEvent);
    buttonLayout->addWidget(nextEvent);
    buttonLayout->addWidget(firstEvent);
    buttonLayout->addWidget(lastEvent);
    buttonLayout->addWidget(download);
    buttonLayout->addWidget(upload);

    buttonLayout->setSpacing(25);
    buttonLayout->setContentsMargins(25,20,25,20);



    mainLayout->addLayout(buttonLayout);
}

void EventViewer::addLine(){

    line = new QFrame();
    line->setFixedHeight(2);
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    line->setStyleSheet(QString("background-color: #c0c0c0;"));

    lineLayout->addWidget(line);
    lineLayout->setContentsMargins(75,10,75,0);
    mainLayout->addLayout(lineLayout);
}

void EventViewer::cleanCalendar(const QDate & d) const
{
    calendar->cleanCalendar(d);
}

void EventViewer::setController(Controller *c)
{
    controller = c;
    connect(firstEvent, SIGNAL(clicked()), controller, SLOT(begin()));
    connect(previuosEvent, SIGNAL(clicked()), controller, SLOT(previousEvent()));
    connect(nextEvent, SIGNAL(clicked()), controller, SLOT(nextEvent()));
    connect(lastEvent, SIGNAL(clicked()), controller, SLOT(last()));
    //connect(download, SIGNAL(clicked()), controller, SLOT(begin()));
    //connect(upload, SIGNAL(clicked()), controller, SLOT(begin()));

    connect(control->actions()[0], SIGNAL(triggered()), controller, SLOT(nextEvent()));
    connect(control->actions()[1], SIGNAL(triggered()), controller, SLOT(previousEvent()));
    connect(control->actions()[2], SIGNAL(triggered()), controller, SLOT(begin()));
    connect(control->actions()[3], SIGNAL(triggered()), controller, SLOT(last()));
    //connect(download, SIGNAL(clicked()), controller, SLOT(begin()));
    //connect(upload, SIGNAL(clicked()), controller, SLOT(begin()));

    connect(inserisci->actions()[0], SIGNAL(triggered()), this,SLOT(showAddEvent()));
    connect(inserisci->actions()[1], SIGNAL(triggered()), this,SLOT(showAddEventB()));
    connect(inserisci->actions()[2], SIGNAL(triggered()), this,SLOT(showAddEventMarriage()));
    connect(inserisci->actions()[3], SIGNAL(triggered()), this,SLOT(showAddEventTournament()));
    connect(inserisci->actions()[4], SIGNAL(triggered()), this,SLOT(showAddEventMarathon()));
    connect(file->actions()[1], SIGNAL(triggered()), controller, SLOT(removeEvent()));

    connect(exit->actions()[2],SIGNAL(triggered()),this,SLOT(close()));
    /*connect(exit->actions()[0],SIGNAL(triggered()),this,SLOT(close()));
    connect(exit->actions()[1],SIGNAL(triggered()),this,SLOT(close()));*/

    connect(calendar, SIGNAL(ShowEventAux(const QDate&)), controller, SLOT(takeEvent(const QDate&)));


}

