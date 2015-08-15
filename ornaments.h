#ifndef ORNAMENTS_H
#define ORNAMENTS_H

#include <QWidget>
#include <QDesktopWidget>
#include <QSystemTrayIcon>
#include <QMenu>

#include "clock.h"
#include "calendar.h"

class Ornaments : public QWidget
{
    Q_OBJECT

public:
    Ornaments(QWidget *parent = 0);
    ~Ornaments();

private:
    Clock *clock;
    Calendar *calendar;
    QMenu *menu;
//    QAction *actionCalendar;
//    QAction *actionClock;

    QSystemTrayIcon *trayIcon;

private slots:
    void hideCalendar();
    void hideClock();
};

#endif // ORNAMENTS_H
