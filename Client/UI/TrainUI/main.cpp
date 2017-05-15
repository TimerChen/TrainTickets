#include <QApplication>
#include "login.h"
#include "mainwindow.h"
#include "uistructs.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
