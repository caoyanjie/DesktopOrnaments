#include "clock.h"
#include <QDebug>

Clock::Clock(QWidget *parent) : QWidget(parent)
  ,clockSize(110)
  ,hourWith(100)
  ,hourHeight(5)
  ,minWith(100)
  ,minHeight(5)
  ,secWith(100)
  ,secHeight(5)
  ,hourAngle(0.0)
  ,minAngle(0.0)
  ,secAngle(0.0)
  ,secOffset(6)
  ,minOffset(6/360)
  ,hourOffset(6/3600)

{
    this->resize(clockSize, clockSize);
    this->setObjectName("clock");

    lab_clock = new QLabel(this);
    lab_hour = new QLabel(this);
    lab_min = new QLabel(this);
    lab_sec = new QLabel(this);

    lab_clock->setGeometry(0, 0, clockSize, clockSize);
    lab_hour->setGeometry(0, 0, clockSize, clockSize);
    lab_min->setGeometry(0, 0, clockSize, clockSize);
    lab_sec->setGeometry(0, 0, clockSize, clockSize);

    lab_clock->setObjectName("lab_clock");
    lab_hour->setObjectName("lab_hour");
    lab_min->setObjectName("lab_min");
    lab_sec->setObjectName("lab_sec");

    lab_clock->setAlignment(Qt::AlignCenter);
    lab_hour->setAlignment(Qt::AlignCenter);
    lab_min->setAlignment(Qt::AlignCenter);
    lab_sec->setAlignment(Qt::AlignCenter);

    this->setStyleSheet("#lab_clock{border-image: url(:/Images/clock.png);}");

    //获取当前时间
    int hour = QTime::currentTime().hour();
    float minute = QTime::currentTime().minute();
    float second = QTime::currentTime().second();

    //
    float hour_step = (hour + (minute / 60) + (second / 3600)) * 5;
    float min_step = minute + (second / 60);
    int sec_step = second;

    //初始化时针位置
    QMatrix hourMatrix;
    hourMatrix.rotate(hourAngle += (hour_step * 6));
    lab_hour->setPixmap(QPixmap(":/Images/hour.png").transformed(hourMatrix, Qt::SmoothTransformation).scaled(clockSize, clockSize));

    //初始化分针位置
    QMatrix minMatrix;
    minMatrix.rotate(minAngle += (min_step * 6));
    lab_min->setPixmap(QPixmap(":/Images/min.png").transformed(minMatrix, Qt::SmoothTransformation).scaled(clockSize, clockSize));

    //初始化秒针位置
    QMatrix secMatrix;
    secMatrix.rotate(secAngle += (sec_step * 6));
    lab_sec->setPixmap(QPixmap(":/Images/sec.png").transformed(secMatrix, Qt::SmoothTransformation).scaled(clockSize, clockSize));

    //设置一秒定时器
    timer_sec = new QTimer(this);
    connect(timer_sec, SIGNAL(timeout()), this, SLOT(sec_timeout()));
    timer_sec->start(1000);
}

void Clock::mousePressEvent(QMouseEvent *event)
{
    if (event ->button() == Qt::LeftButton)
    {
        offset = event ->globalPos() - pos();
    }
}

void Clock::mouseMoveEvent(QMouseEvent *event)
{
    if (event ->buttons() & Qt::LeftButton)
    {
        QPoint temp;
        temp = event ->globalPos() - offset;
        move(temp);
    }
}

void Clock::sec_timeout()
{
    QMatrix hourMatrix;
    hourMatrix.rotate(hourAngle += hourOffset);
    lab_hour->setPixmap(QPixmap(":/Images/hour.png").transformed(hourMatrix, Qt::SmoothTransformation).scaled(clockSize, clockSize));

    QMatrix minMatrix;
    minMatrix.rotate(minAngle += minOffset);
    lab_min->setPixmap(QPixmap(":/Images/min.png").transformed(minMatrix, Qt::SmoothTransformation).scaled(clockSize, clockSize));

    QMatrix secMatrix;
    secMatrix.rotate(secAngle += secOffset);
    lab_sec->setPixmap(QPixmap(":/Images/sec.png").transformed(secMatrix, Qt::SmoothTransformation).scaled(clockSize, clockSize));

    int hour = QTime::currentTime().hour();
    if (hour == 0)
    {
        emit updateDatetime();
    }
}

