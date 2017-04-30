/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Regist
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QLineEdit *confirmpwdLineEdit;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *loginBtn;
    QPushButton *backtologinBtn;
    QPushButton *exitButton;

    void setupUi(QDialog *Regist)
    {
        if (Regist->objectName().isEmpty())
            Regist->setObjectName(QStringLiteral("Regist"));
        Regist->resize(858, 492);
        widget = new QWidget(Regist);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(49, 30, 118, 158));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        widget1 = new QWidget(Regist);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(220, 30, 591, 161));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usrLineEdit = new QLineEdit(widget1);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));

        verticalLayout_2->addWidget(usrLineEdit);

        pwdLineEdit = new QLineEdit(widget1);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));

        verticalLayout_2->addWidget(pwdLineEdit);

        confirmpwdLineEdit = new QLineEdit(widget1);
        confirmpwdLineEdit->setObjectName(QStringLiteral("confirmpwdLineEdit"));

        verticalLayout_2->addWidget(confirmpwdLineEdit);

        widget2 = new QWidget(Regist);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(46, 210, 771, 200));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        loginBtn = new QPushButton(widget2);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        verticalLayout_3->addWidget(loginBtn);

        backtologinBtn = new QPushButton(widget2);
        backtologinBtn->setObjectName(QStringLiteral("backtologinBtn"));

        verticalLayout_3->addWidget(backtologinBtn);

        exitButton = new QPushButton(widget2);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        verticalLayout_3->addWidget(exitButton);


        retranslateUi(Regist);
        QObject::connect(exitButton, SIGNAL(clicked()), Regist, SLOT(close()));

        QMetaObject::connectSlotsByName(Regist);
    } // setupUi

    void retranslateUi(QDialog *Regist)
    {
        Regist->setWindowTitle(QApplication::translate("Regist", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("Regist", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Regist", "\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("Regist", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("Regist", "\346\263\250\345\206\214", Q_NULLPTR));
        backtologinBtn->setText(QApplication::translate("Regist", "\350\277\224\345\233\236\347\231\273\351\231\206\347\225\214\351\235\242", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Regist", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Regist: public Ui_Regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
