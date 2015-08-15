#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDateTime>
#include <QMouseEvent>

class Calendar : public QWidget
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = 0);

private:
    QLabel *lab_calendar;
    QLabel *lab_week;
    QLabel *lab_day;
    QLabel *lab_year_month;

    QVBoxLayout *layout_v;
    QGridLayout *layout_top;

    const int calendarWidth;
    const int calendarHeight;

    void setDatetime();

    QPoint offset;

protected:
    void mousePressEvent(QMouseEvent *event);       //重写鼠标按下事件
    void mouseMoveEvent(QMouseEvent *event);        //重写鼠标移动事件

signals:

public slots:
    void updateDatetime();
};

#endif // CALENDAR_H
