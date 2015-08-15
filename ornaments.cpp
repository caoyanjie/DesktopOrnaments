#include "ornaments.h"

Ornaments::Ornaments(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);
    this->setAttribute(Qt::WA_TranslucentBackground);
    QDesktopWidget desktop;
    this->resize(desktop.size());

    clock = new Clock(this);
    clock->move(1510, 180);

    calendar = new Calendar(this);
    calendar->move(960, 185);

    connect(clock, SIGNAL(updateDatetime()), calendar, SLOT(updateDatetime()));
}

Ornaments::~Ornaments()
{

}
