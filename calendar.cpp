#include "calendar.h"
#include <QDebug>

Calendar::Calendar(QWidget *parent) : QWidget(parent),
    calendarWidth(90),
    calendarHeight(105)
{
    this->resize(calendarWidth, calendarHeight);

    lab_calendar = new QLabel;
    lab_week = new QLabel;
    lab_day = new QLabel;
    lab_year_month = new QLabel;
    lab_calendar->setFixedSize(calendarWidth, calendarHeight);

    lab_week->setAlignment(Qt::AlignCenter);
    lab_day->setAlignment(Qt::AlignCenter);
    lab_year_month->setAlignment(Qt::AlignCenter);

    layout_v = new QVBoxLayout;
    layout_v->addWidget(lab_week);
    layout_v->addWidget(lab_day);
    layout_v->addWidget(lab_year_month);
    layout_v->setSpacing(0);
    layout_v->setContentsMargins(15, 15, 15, 5);

    layout_top = new QGridLayout;
    layout_top->addWidget(lab_calendar, 0, 0, 1, 1);
    layout_top->addLayout(layout_v, 0, 0, 1, 1);
    layout_top->setSpacing(0);
    layout_top->setMargin(0);
    this->setLayout(layout_top);

    lab_calendar->setObjectName("lab_calendar");
    lab_week->setObjectName("lab_week");
    lab_day->setObjectName("lab_day");
    lab_year_month->setObjectName("lab_year_month");

    this->setStyleSheet(
                "#lab_calendar{border-image: url(:/Images/calendar);}"
                "#lab_week{color: #f0dfb6;}"
                "#lab_day{color: white; font-size: 43pt}"
                "#lab_year_month{color: #f0dfb6;}"
                );
    setDatetime();
}

void Calendar::setDatetime()
{
    //获取当前时间
    int week = QDateTime::currentDateTime().date().dayOfWeek();                 // 获得星期几
    QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString date = datetime.split("-")[2];                                      // 获得日期
    QString year = datetime.split("-")[0];                                      // 获得年份
    int month = datetime.split("-")[1].toInt();                                     // 获得月份

    QStringList integer;
    integer << "一" << "二" << "三" << "四" << "五" << "六" << "七" << "八" << "九" << "十" << "十一" << "十二";


    // 设置日历上的星期
    for (int i=1; i<8; ++i)
    {
        if (week == 7)
        {
            lab_week->setText(tr("星期日"));
            break;
        }
        else if (week == i)
        {
            lab_week->setText(tr("星期%1").arg(integer[i-1]));
            break;
        }
    }

    // 设置日历上的日期
    lab_day->setText(date);

    // 设置日历上的年月
    for (int i=1; i<13; ++i)
    {
        if (month == i)
        {
            lab_year_month->setText(tr("%1 %2月").arg(year).arg(integer[i-1]));
            break;
        }
    }
}

void Calendar::updateDatetime()
{
    setDatetime();
}

