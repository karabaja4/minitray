#include <QApplication>
#include <QIcon>
#include <QDebug>
#include <QProcess>
#include <QSystemTrayIcon>

void exec()
{
    QStringList arguments = QCoreApplication::arguments();
    if (arguments.count() > 1)
    {
        QProcess *process = new QProcess();
        QString program = arguments.at(1);
        arguments.removeFirst();
        arguments.removeFirst();
        process->start(program, arguments);
    }
    else
    {
        qInfo("no arguments passed");
    }
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

