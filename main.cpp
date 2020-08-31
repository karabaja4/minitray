#include <QApplication>
#include <QIcon>
#include <QProcess>
#include <QSystemTrayIcon>

void exec()
{
    QProcess *process = new QProcess();
    process->start("gsimplecal", QCoreApplication::arguments());
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon();
    trayIcon->setIcon(QIcon(":/images/calendar.svg"));
    trayIcon->show();
    QObject::connect(trayIcon, &QSystemTrayIcon::activated, exec);
    return app.exec();
}

