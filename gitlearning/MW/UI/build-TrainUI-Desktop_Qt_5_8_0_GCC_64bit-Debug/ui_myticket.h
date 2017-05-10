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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Myticket
{
public:
    QTextEdit *ticketsTextEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *preTicketBtn;
    QPushButton *nextTicketBtn;
    QPushButton *modifyTicketBtn;

    void setupUi(QDialog *Myticket)
    {
        if (Myticket->objectName().isEmpty())
            Myticket->setObjectName(QStringLiteral("Myticket"));
        Myticket->resize(727, 564);
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        Myticket->setWindowIcon(icon);
        ticketsTextEdit = new QTextEdit(Myticket);
        ticketsTextEdit->setObjectName(QStringLiteral("ticketsTextEdit"));
        ticketsTextEdit->setGeometry(QRect(90, 30, 541, 381));
        layoutWidget = new QWidget(Myticket);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 430, 601, 60));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        preTicketBtn = new QPushButton(layoutWidget);
        preTicketBtn->setObjectName(QStringLiteral("preTicketBtn"));

        horizontalLayout->addWidget(preTicketBtn);

        nextTicketBtn = new QPushButton(layoutWidget);
        nextTicketBtn->setObjectName(QStringLiteral("nextTicketBtn"));

        horizontalLayout->addWidget(nextTicketBtn);

        modifyTicketBtn = new QPushButton(layoutWidget);
        modifyTicketBtn->setObjectName(QStringLiteral("modifyTicketBtn"));

        horizontalLayout->addWidget(modifyTicketBtn);


        retranslateUi(Myticket);

        QMetaObject::connectSlotsByName(Myticket);
    } // setupUi

    void retranslateUi(QDialog *Myticket)
    {
        Myticket->setWindowTitle(QApplication::translate("Myticket", "\346\210\221\347\232\204\350\275\246\347\245\250", Q_NULLPTR));
        preTicketBtn->setText(QApplication::translate("Myticket", "\345\211\215\344\270\200\345\274\240", Q_NULLPTR));
        nextTicketBtn->setText(QApplication::translate("Myticket", "\345\220\216\344\270\200\345\274\240", Q_NULLPTR));
        modifyTicketBtn->setText(QApplication::translate("Myticket", "\351\200\200\350\256\242/\346\224\271\347\255\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Myticket: public Ui_Myticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTICKET_H
