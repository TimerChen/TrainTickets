/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *loginBtn;
    QPushButton *regBtn;
    QSplitter *splitter;
    QPushButton *stationToStationSearch;
    QPushButton *Trainsearch;
    QPushButton *stationSearch;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *myticketBtn;
    QPushButton *modifyAccountBtn;
    QPushButton *logoutBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(823, 802);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 840, 82, 351));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 241, 251));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../../mnt/hgfs/share/12308.png")));
        label->setScaledContents(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(127, 240, 129, 32));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(340, 50, 411, 191));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        loginBtn = new QPushButton(widget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        verticalLayout_2->addWidget(loginBtn);

        regBtn = new QPushButton(widget);
        regBtn->setObjectName(QStringLiteral("regBtn"));

        verticalLayout_2->addWidget(regBtn);

        regBtn->raise();
        loginBtn->raise();
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(60, 300, 691, 351));
        splitter->setOrientation(Qt::Vertical);
        stationToStationSearch = new QPushButton(splitter);
        stationToStationSearch->setObjectName(QStringLiteral("stationToStationSearch"));
        splitter->addWidget(stationToStationSearch);
        Trainsearch = new QPushButton(splitter);
        Trainsearch->setObjectName(QStringLiteral("Trainsearch"));
        splitter->addWidget(Trainsearch);
        stationSearch = new QPushButton(splitter);
        stationSearch->setObjectName(QStringLiteral("stationSearch"));
        splitter->addWidget(stationSearch);
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(60, 680, 691, 60));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        myticketBtn = new QPushButton(widget1);
        myticketBtn->setObjectName(QStringLiteral("myticketBtn"));

        horizontalLayout->addWidget(myticketBtn);

        modifyAccountBtn = new QPushButton(widget1);
        modifyAccountBtn->setObjectName(QStringLiteral("modifyAccountBtn"));

        horizontalLayout->addWidget(modifyAccountBtn);

        logoutBtn = new QPushButton(widget1);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));

        horizontalLayout->addWidget(logoutBtn);

        MainWindow->setCentralWidget(centralWidget);
        loginBtn->raise();
        label_2->raise();
        label->raise();
        label_3->raise();
        stationToStationSearch->raise();
        Trainsearch->raise();
        stationSearch->raise();
        regBtn->raise();
        modifyAccountBtn->raise();
        myticketBtn->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "12308", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "12308", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        regBtn->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        stationToStationSearch->setText(QApplication::translate("MainWindow", "\347\253\231\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
        Trainsearch->setText(QApplication::translate("MainWindow", "\350\275\246\346\254\241\346\237\245\350\257\242", Q_NULLPTR));
        stationSearch->setText(QApplication::translate("MainWindow", "\350\275\246\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
        myticketBtn->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\350\275\246\347\245\250", Q_NULLPTR));
        modifyAccountBtn->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        logoutBtn->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
