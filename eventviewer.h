#ifndef EVENTVIEWER_H
#define EVENTVIEWER_H

#include<QWidget>
#include<QBoxLayout>
#include<QMenuBar>
#include<QPushButton>
#include<QCalendarWidget>
#include<QLabel>
#include<QDialog>
#include<vector>
#include<QInputDialog>
#include<QDate>
#include<event.h>
#include<inputdialog.h>
#include<QGroupBox>
#include<QLine>
#include<string>
#include<QString>
#include<inputdialogb.h>
#include<mycalendarwidget.h>
#include<inputdialogmarriage.h>
#include<inputdialogmarathon.h>
#include<inputdialogt.h>

class Controller;
class MyCalendarWidget;

class EventViewer : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* lblCalendarLayout;
    QHBoxLayout* buttonLayout;
    QVBoxLayout* lineLayout;

    QMenuBar* menuBar;
    QMenu* inserisci;
    QMenu* file;
    QMenu* exit;
    QMenu* control;

    MyCalendarWidget* calendar;
    QLabel* label;
    QFrame* line;

    Controller* controller;

    QPushButton* previuosEvent;
    QPushButton* nextEvent;
    QPushButton* firstEvent;
    QPushButton* lastEvent;
    QPushButton* download;
    QPushButton* upload;

    QLabel* lblDay;
    QLabel* lblMounth;
    QLabel* lblWeekDay;

    void addMenus();
    void addCalendar();
    void addLabel();
    void addControls();
    void addLine();


public:
    /**
     * @brief metodo che setta il controller
     */
    void setController(Controller* c);
    explicit EventViewer(QWidget *parent = nullptr);
    /**
     * @brief metodo che mostra una finestra di errore con relativo messaggio d'errore
     */
    void showWarning(const QString&) const;
    /**
     * @brief metodo che mostra una finestra di avvenuta operazione con correttezza con relativo messaggio di conferma
     */
    void showWell(const QString&) const;
    /**
     * @brief metodo che mostra una finestra che richiede il titolo dell'evento da eliminare e lo ritorna una volta inviato
     */
    QString showRemoveEvent();
    /**
     * @brief metodo che mostra nella label il relativo evento
     * @param event, evento da mostrare sulla label
     */
    void showEvento(Event* event);
    /**
     * @brief metodo richiamato da i vari costum Dialog di inserimento, per inserire tramite il controller l'evento
     */
    void finish(std::pair<int, std::vector<QString>>) const;
    /**
     * @brief metodo che pulisce la label dopo aver fatto l'eliminazione
     */
    void clean();
    /**
     * @brief metodo che pulisce ed elima logo azienda nella data passata
     */
    void cleanCalendar(const QDate&) const;
    /**
     * @brief metodo che aggiorna la data a seconda del giorno, premuto
     */
    void updateLabel();
    /**
     * @brief metodo che aggiunge evnto all'interno del calendario
     */
    void updateCalendar (const QDate&) const;

public slots:
    /**
     * @brief metodi che creano e mostrano i nostri custom Dialog, per l'inserimento dei vari eventi nel calendario
     */
    void showAddEvent();
    void showAddEventB();
    void showAddEventMarriage();
    void showAddEventMarathon();
    void showAddEventTournament();
};

#endif // EVENTVIEWER_H
