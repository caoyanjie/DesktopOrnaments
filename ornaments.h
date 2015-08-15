#ifndef ORNAMENTS_H
#define ORNAMENTS_H

#include <QWidget>
#include <QDesktopWidget>

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
};

#endif // ORNAMENTS_H
