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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerMainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralWidget;
    QPushButton *restartPushButton;
    QTextEdit *textEdit;
    QPushButton *stopPushButton;
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
        ServerMainWindow->resize(400, 300);
        actionAbout = new QAction(ServerMainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(ServerMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        restartPushButton = new QPushButton(centralWidget);
        restartPushButton->setObjectName(QStringLiteral("restartPushButton"));
        restartPushButton->setGeometry(QRect(280, 50, 85, 28));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 40, 221, 101));
        textEdit->setReadOnly(true);
        stopPushButton = new QPushButton(centralWidget);
        stopPushButton->setObjectName(QStringLiteral("stopPushButton"));
        stopPushButton->setGeometry(QRect(280, 90, 85, 28));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 180, 221, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 180, 121, 31));
        ServerMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ServerMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 28));
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
