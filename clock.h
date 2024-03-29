#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
//#include <time.h>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = 0);

private:
    QLabel *lab_clock;
    QLabel *lab_hour;
    QLabel *lab_min;
    QLabel *lab_sec;

    const int clockSize;
    const int hourWith;
    const int hourHeight;
    const int minWith;
    const int minHeight;
    const int secWith;
    const int secHeight;

    QTimer *timer_sec;

    float hourAngle;
    float minAngle;
    int secAngle;
    const int secOffset;
    const float minOffset;
    const float hourOffset;

    QPoint offset;


protected:
    void mousePressEvent(QMouseEvent *event);       //重写鼠标按下事件
    void mouseMoveEvent(QMouseEvent *event);        //重写鼠标移动事件

signals:
    void updateDatetime();

public slots:
    void sec_timeout();
};

#endif // CLOCK_H
