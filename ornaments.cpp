#include "ornaments.h"
#include <QAction>

Ornaments::Ornaments(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::SubWindow);
    this->setAttribute(Qt::WA_TranslucentBackground);
    QDesktopWidget desktop;
    this->resize(desktop.size());

    calendar = new Calendar(this);
    calendar->move(1039, 60);

    clock = new Clock(this);
    clock->move(1434, 48);

    connect(clock, SIGNAL(updateDatetime()), calendar, SLOT(updateDatetime()));

    //初始化 工具栏 图标
    trayIcon = new QSystemTrayIcon(QIcon(":/Images/myicon.ico"), this);
//    trayIcon->setToolTip(tr("兔兔音乐播放器"));

    // 创建菜单
    menu = new QMenu;
    menu->addAction(QIcon(tr(":/Images/%1").arg(calendar->isHidden() ? "" : "ok.png")), tr("%1日历").arg(calendar->isHidden() ? "显示" : "隐藏"), this, SLOT(hideCalendar()));
    menu->addAction(QIcon(tr(":/Images/%1").arg(clock->isHidden() ? "" : "ok.png")), tr("%1时钟").arg(clock->isHidden() ? "显示" : "隐藏"), this, SLOT(hideClock()));
    menu->addAction(tr("退出"), this, SLOT(deleteLater()));
    trayIcon->setContextMenu(menu);
    // 托盘图标被激活后进行处理
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
    // 显示托盘图标
    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(trayIcon_clicked(QSystemTrayIcon::ActivationReason)));
}

Ornaments::~Ornaments()
{

}

void Ornaments::hideCalendar()
{
    if (calendar->isHidden())
    {
        calendar->show();
        menu->deleteLater();
        menu = new QMenu;
        menu->addAction(QIcon(tr(":/Images/%1").arg(calendar->isHidden() ? "" : "ok.png")), tr("%1日历").arg(calendar->isHidden() ? "显示" : "隐藏"), this, SLOT(hideCalendar()));
        menu->addAction(QIcon(tr(":/Images/%1").arg(clock->isHidden() ? "" : "ok.png")), tr("%1时钟").arg(clock->isHidden() ? "显示" : "隐藏"), this, SLOT(hideClock()));
        menu->addAction(tr("退出"), this, SLOT(deleteLater()));
        trayIcon->setContextMenu(menu);
    }
    else
    {
        calendar->hide();
        menu->deleteLater();
        menu = new QMenu;
        menu->addAction(QIcon(tr(":/Images/%1").arg(calendar->isHidden() ? "" : "ok.png")), tr("%1日历").arg(calendar->isHidden() ? "显示" : "隐藏"), this, SLOT(hideCalendar()));
        menu->addAction(QIcon(tr(":/Images/%1").arg(clock->isHidden() ? "" : "ok.png")), tr("%1时钟").arg(clock->isHidden() ? "显示" : "隐藏"), this, SLOT(hideClock()));
        menu->addAction(tr("退出"), this, SLOT(deleteLater()));
        trayIcon->setContextMenu(menu);
    }
}

void Ornaments::hideClock()
{
    if (clock->isHidden())
    {
        clock->show();
        menu->deleteLater();
        menu = new QMenu;
        menu->addAction(QIcon(tr(":/Images/%1").arg(calendar->isHidden() ? "" : "ok.png")), tr("%1日历").arg(calendar->isHidden() ? "显示" : "隐藏"), this, SLOT(hideCalendar()));
        menu->addAction(QIcon(tr(":/Images/%1").arg(clock->isHidden() ? "" : "ok.png")), tr("%1时钟").arg(clock->isHidden() ? "显示" : "隐藏"), this, SLOT(hideClock()));
        menu->addAction(tr("退出"), this, SLOT(deleteLater()));
        trayIcon->setContextMenu(menu);
    }
    else
    {
        clock->hide();
        menu->deleteLater();
        menu = new QMenu;
        menu->addAction(QIcon(tr(":/Images/%1").arg(calendar->isHidden() ? "" : "ok.png")), tr("%1日历").arg(calendar->isHidden() ? "显示" : "隐藏"), this, SLOT(hideCalendar()));
        menu->addAction(QIcon(tr(":/Images/%1").arg(clock->isHidden() ? "" : "ok.png")), tr("%1时钟").arg(clock->isHidden() ? "显示" : "隐藏"), this, SLOT(hideClock()));
        menu->addAction(tr("退出"), this, SLOT(deleteLater()));
        trayIcon->setContextMenu(menu);
    }
}
