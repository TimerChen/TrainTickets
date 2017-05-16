/********************************************************************************
** Form generated from reading UI file 'myticket.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTICKET_H
#define UI_MYTICKET_H

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

class Ui_Myticket
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableView *ticketsTableView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *numLineEdit;
    QPushButton *modifyTicketBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *Myticket)
    {
        if (Myticket->objectName().isEmpty())
            Myticket->setObjectName(QStringLiteral("Myticket"));
        Myticket->resize(1600, 900);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        Myticket->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(Myticket);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ticketsTableView = new QTableView(Myticket);
        ticketsTableView->setObjectName(QStringLiteral("ticketsTableView"));

        verticalLayout_2->addWidget(ticketsTableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Myticket);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        numLineEdit = new QLineEdit(Myticket);
        numLineEdit->setObjectName(QStringLiteral("numLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numLineEdit->sizePolicy().hasHeightForWidth());
        numLineEdit->setSizePolicy(sizePolicy);
        numLineEdit->setMinimumSize(QSize(0, 70));

        horizontalLayout->addWidget(numLineEdit);

        modifyTicketBtn = new QPushButton(Myticket);
        modifyTicketBtn->setObjectName(QStringLiteral("modifyTicketBtn"));
        sizePolicy.setHeightForWidth(modifyTicketBtn->sizePolicy().hasHeightForWidth());
        modifyTicketBtn->setSizePolicy(sizePolicy);
        modifyTicketBtn->setMinimumSize(QSize(0, 70));

        horizontalLayout->addWidget(modifyTicketBtn);


        verticalLayout->addLayout(horizontalLayout);

        exitBtn = new QPushButton(Myticket);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setMinimumSize(QSize(0, 70));

        verticalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Myticket);
        QObject::connect(exitBtn, SIGNAL(clicked()), Myticket, SLOT(close()));

        QMetaObject::connectSlotsByName(Myticket);
    } // setupUi

    void retranslateUi(QDialog *Myticket)
    {
        Myticket->setWindowTitle(QApplication::translate("Myticket", "\346\210\221\347\232\204\350\275\246\347\245\250", Q_NULLPTR));
        label->setText(QApplication::translate("Myticket", "\351\200\200\350\256\242\345\274\240\346\225\260", Q_NULLPTR));
        modifyTicketBtn->setText(QApplication::translate("Myticket", "\351\200\200\350\256\242", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Myticket", "\350\277\224\345\233\236\346\237\245\350\257\242\347\252\227\345\217\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Myticket: public Ui_Myticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTICKET_H
