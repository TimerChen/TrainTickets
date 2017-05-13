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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ticketNumLineEdit;
    QPushButton *buyTicketBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *SearchTicket)
    {
        if (SearchTicket->objectName().isEmpty())
            SearchTicket->setObjectName(QStringLiteral("SearchTicket"));
        SearchTicket->resize(1080, 506);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        SearchTicket->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(SearchTicket);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ticketsTableView = new QTableView(SearchTicket);
        ticketsTableView->setObjectName(QStringLiteral("ticketsTableView"));

        verticalLayout_2->addWidget(ticketsTableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SearchTicket);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        ticketNumLineEdit = new QLineEdit(SearchTicket);
        ticketNumLineEdit->setObjectName(QStringLiteral("ticketNumLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ticketNumLineEdit->sizePolicy().hasHeightForWidth());
        ticketNumLineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(ticketNumLineEdit);

        buyTicketBtn = new QPushButton(SearchTicket);
        buyTicketBtn->setObjectName(QStringLiteral("buyTicketBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buyTicketBtn->sizePolicy().hasHeightForWidth());
        buyTicketBtn->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(buyTicketBtn);


        verticalLayout->addLayout(horizontalLayout);

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
        label->setText(QApplication::translate("SearchTicket", "\350\264\255\344\271\260\345\274\240\346\225\260", Q_NULLPTR));
        ticketNumLineEdit->setText(QApplication::translate("SearchTicket", "1", Q_NULLPTR));
        buyTicketBtn->setText(QApplication::translate("SearchTicket", "\350\264\255\347\245\250", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("SearchTicket", "\350\277\224\345\233\236\346\237\245\350\257\242\347\252\227\345\217\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchTicket: public Ui_SearchTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHTICKET_H
