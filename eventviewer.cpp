#include "eventviewer.h"
#include<iostream>

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

    //showAddEvent();
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
    //label->setText(list[0]+"\n"+list[1]);
}

QString EventViewer::showRemoveEvent()
{
    QString titolo = QInputDialog::getText(this, "Rimuovi Evento", "Titolo Evento");
    return titolo;
}

void EventViewer::addMenus(){
    menuBar = new QMenuBar(this);
    QMenu* file = new QMenu("File", menuBar);
    QMenu* exit = new QMenu("Calendario", menuBar);
    QMenu* control = new QMenu("Controlli", menuBar);

    menuBar->addMenu(exit);
    menuBar->addMenu(file);
    menuBar->addMenu(control);

    QMenu* inserisci = file->addMenu("Inserisci nuovo evento");
    QAction* elimina = file->addAction("Elimina");

    QAction* actionInsertFiera = inserisci->addAction("Fiera");
    QAction* actionInsertBachelor = inserisci->addAction("Bachelor");
    QAction* actionInsertMarriage = inserisci->addAction("Marriage");
    QAction* actionInserisciTournament = inserisci->addAction("Tournament");
    QAction* actionInserisciMarathon = inserisci->addAction("Marathon");

    QAction* actionExport = exit->addAction("Esporta eventi");
    QAction* actionImport = exit->addAction("Importa eventi");
    QAction* actionClose = exit->addAction("Termina programma");

    QAction* actionNext = control->addAction("Prossimo");
    QAction* actionPrevious = control->addAction("Precedente");
    QAction* actionFirst = control->addAction("Primo");
    QAction* actionLast = control->addAction("Ultimo");


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
    calendar->setVerticalHeaderFormat(calendar->NoVerticalHeader);

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
    label->setText("Evento dell'anno\nPer la compagnia Apple\ninvitati: 500\nPrezzo: 300€\nResponsabile: Nome Cognome");
    label->setStyleSheet("background:#383232; color: #f3efe8; font-size: 15px;");

    lblVLayout->addWidget(label,80);

    lblCalendarLayout->addLayout(lblVLayout);

}

void EventViewer::addControls()
{

    QPushButton* previuosEvent = new QPushButton("Precedente evento", this);
    QPushButton* nextEvent = new QPushButton("Prossimo evento", this);
    QPushButton* firstEvent = new QPushButton("Primo evento dell'anno", this);
    QPushButton* lastEvent = new QPushButton("Ultimo evento dell'anno", this);
    QPushButton* download = new QPushButton("Scarica calendario", this);
    QPushButton* upload = new QPushButton("Inserisci calendario", this);

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
