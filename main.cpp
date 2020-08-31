#include <QApplication>
#include <QIcon>
#include <QProcess>
#include <QSystemTrayIcon>

void exec()
{
    QProcess *process = new QProcess();
    QStringList arguments = QCoreApplication::arguments();
    QString program = arguments.at(1);
    arguments.removeFirst();
    arguments.removeFirst();
    process->start(program, arguments);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon();
    trayIcon->setIcon(QIcon(":/images/heart.png"));
    trayIcon->show();
    QObject::connect(trayIcon, &QSystemTrayIcon::activated, exec);
    return app.exec();
}

