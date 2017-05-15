/********************************************************************************
** Form generated from reading UI file 'servermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERMAINWINDOW_H
#define UI_SERVERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerMainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QTextEdit *console;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *restartPushButton;
    QPushButton *stopPushButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuSetting;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ServerMainWindow)
    {
        if (ServerMainWindow->objectName().isEmpty())
            ServerMainWindow->setObjectName(QStringLiteral("ServerMainWindow"));
        ServerMainWindow->resize(822, 493);
        actionAbout = new QAction(ServerMainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(ServerMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        console = new QTextEdit(splitter);
        console->setObjectName(QStringLiteral("console"));
        console->setReadOnly(true);
        splitter->addWidget(console);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        restartPushButton = new QPushButton(widget);
        restartPushButton->setObjectName(QStringLiteral("restartPushButton"));

        verticalLayout->addWidget(restartPushButton);

        stopPushButton = new QPushButton(widget);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));

        verticalLayout->addWidget(stopPushButton);

        splitter->addWidget(widget);
        splitter_2->addWidget(splitter);
        widget1 = new QWidget(splitter_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        splitter_2->addWidget(widget1);

        verticalLayout_2->addWidget(splitter_2);

        ServerMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ServerMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 21));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        ServerMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ServerMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ServerMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ServerMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ServerMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSetting->menuAction());
        menuSetting->addAction(actionAbout);

        retranslateUi(ServerMainWindow);

        QMetaObject::connectSlotsByName(ServerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerMainWindow)
    {
        ServerMainWindow->setWindowTitle(QApplication::translate("ServerMainWindow", "12308\346\234\215\345\212\241\347\253\257", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("ServerMainWindow", "About..", Q_NULLPTR));
        restartPushButton->setText(QApplication::translate("ServerMainWindow", "Restart", Q_NULLPTR));
        stopPushButton->setText(QApplication::translate("ServerMainWindow", "Stop", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ServerMainWindow", "SendCommond", Q_NULLPTR));
        menuSetting->setTitle(QApplication::translate("ServerMainWindow", "Setting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerMainWindow: public Ui_ServerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERMAINWINDOW_H
