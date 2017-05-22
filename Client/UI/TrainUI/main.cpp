#include <QApplication>
#include "login.h"
#include "mainwindow.h"
#include "uistructs.h"
#include <QFile>
#include <QtGlobal>

int main(int argc, char *argv[]) {
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
