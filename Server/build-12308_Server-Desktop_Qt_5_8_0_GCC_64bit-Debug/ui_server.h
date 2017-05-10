/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *IPlabel;
    QLabel *portlabel;
    QLabel *statuslabel;

    void setupUi(QDialog *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(400, 300);
        IPlabel = new QLabel(Server);
        IPlabel->setObjectName(QStringLiteral("IPlabel"));
        IPlabel->setGeometry(QRect(150, 80, 141, 20));
        portlabel = new QLabel(Server);
        portlabel->setObjectName(QStringLiteral("portlabel"));
        portlabel->setGeometry(QRect(150, 130, 141, 20));
        statuslabel = new QLabel(Server);
        statuslabel->setObjectName(QStringLiteral("statuslabel"));
        statuslabel->setGeometry(QRect(80, 210, 261, 20));

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QDialog *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", Q_NULLPTR));
        IPlabel->setText(QApplication::translate("Server", "TextLabel", Q_NULLPTR));
        portlabel->setText(QApplication::translate("Server", "TextLabel", Q_NULLPTR));
        statuslabel->setText(QApplication::translate("Server", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
