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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchTicket
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableView *ticketsTableView;
    QVBoxLayout *verticalLayout;
    QPushButton *buyTicketBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *SearchTicket)
    {
        if (SearchTicket->objectName().isEmpty())
            SearchTicket->setObjectName(QStringLiteral("SearchTicket"));
        SearchTicket->resize(1080, 506);
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        SearchTicket->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(SearchTicket);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        ticketsTableView = new QTableView(SearchTicket);
        ticketsTableView->setObjectName(QStringLiteral("ticketsTableView"));

        verticalLayout_2->addWidget(ticketsTableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        buyTicketBtn = new QPushButton(SearchTicket);
        buyTicketBtn->setObjectName(QStringLiteral("buyTicketBtn"));

        verticalLayout->addWidget(buyTicketBtn);

        exitBtn = new QPushButton(SearchTicket);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        verticalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


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
