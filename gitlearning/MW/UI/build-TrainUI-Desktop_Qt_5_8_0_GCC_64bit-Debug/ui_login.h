/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *exitBtn;
    QPushButton *auloginBtn;
    QPushButton *loginBtn;
    QLineEdit *pwdLineEdit;
    QLineEdit *usrLineEdit;
    QPushButton *registBtn;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(794, 399);
        Login->setMinimumSize(QSize(794, 399));
        Login->setMaximumSize(QSize(794, 399));
        formLayout = new QFormLayout(Login);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        exitBtn = new QPushButton(Login);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        formLayout->setWidget(7, QFormLayout::SpanningRole, exitBtn);

        auloginBtn = new QPushButton(Login);
        auloginBtn->setObjectName(QStringLiteral("auloginBtn"));

        formLayout->setWidget(5, QFormLayout::LabelRole, auloginBtn);

        loginBtn = new QPushButton(Login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        formLayout->setWidget(5, QFormLayout::FieldRole, loginBtn);

        pwdLineEdit = new QLineEdit(Login);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pwdLineEdit);

        usrLineEdit = new QLineEdit(Login);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, usrLineEdit);

        registBtn = new QPushButton(Login);
        registBtn->setObjectName(QStringLiteral("registBtn"));

        formLayout->setWidget(6, QFormLayout::SpanningRole, registBtn);


        retranslateUi(Login);
        QObject::connect(exitBtn, SIGNAL(clicked()), Login, SLOT(close()));
        QObject::connect(usrLineEdit, SIGNAL(returnPressed()), loginBtn, SLOT(click()));
        QObject::connect(pwdLineEdit, SIGNAL(returnPressed()), loginBtn, SLOT(click()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225\347\201\253\350\275\246\350\256\242\347\245\250\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Login", "\351\200\200\345\207\272", Q_NULLPTR));
        auloginBtn->setText(QApplication::translate("Login", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", Q_NULLPTR));
        registBtn->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
