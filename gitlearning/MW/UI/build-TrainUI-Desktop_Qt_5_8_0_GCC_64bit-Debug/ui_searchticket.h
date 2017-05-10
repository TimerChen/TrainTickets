/********************************************************************************
** Form generated from reading UI file 'searchticket.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHTICKET_H
#define UI_SEARCHTICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_SearchTicket
{
public:
    QTableView *ticketsTableView;
    QSplitter *splitter;
    QPushButton *buyTicketBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *SearchTicket)
    {
        if (SearchTicket->objectName().isEmpty())
            SearchTicket->setObjectName(QStringLiteral("SearchTicket"));
        SearchTicket->resize(1053, 529);
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        SearchTicket->setWindowIcon(icon);
        ticketsTableView = new QTableView(SearchTicket);
        ticketsTableView->setObjectName(QStringLiteral("ticketsTableView"));
        ticketsTableView->setGeometry(QRect(30, 10, 991, 401));
        splitter = new QSplitter(SearchTicket);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(30, 425, 991, 81));
        splitter->setOrientation(Qt::Vertical);
        buyTicketBtn = new QPushButton(splitter);
        buyTicketBtn->setObjectName(QStringLiteral("buyTicketBtn"));
        splitter->addWidget(buyTicketBtn);
        exitBtn = new QPushButton(splitter);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        splitter->addWidget(exitBtn);

        retranslateUi(SearchTicket);
        QObject::connect(exitBtn, SIGNAL(clicked()), SearchTicket, SLOT(close()));

        QMetaObject::connectSlotsByName(SearchTicket);
    } // setupUi

    void retranslateUi(QDialog *SearchTicket)
    {
        SearchTicket->setWindowTitle(QApplication::translate("SearchTicket", "\347\253\231\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
        buyTicketBtn->setText(QApplication::translate("SearchTicket", "\350\264\255\347\245\250", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("SearchTicket", "\350\277\224\345\233\236\346\237\245\350\257\242\347\252\227\345\217\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchTicket: public Ui_SearchTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHTICKET_H
