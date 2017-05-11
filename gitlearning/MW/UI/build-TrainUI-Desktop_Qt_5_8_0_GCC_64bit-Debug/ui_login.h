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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *usrLineEdit;
    QLabel *label_2;
    QLineEdit *pwdLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *auloginBtn;
    QPushButton *loginBtn;
    QVBoxLayout *verticalLayout;
    QPushButton *registBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(598, 193);
        Login->setMinimumSize(QSize(598, 193));
        Login->setMaximumSize(QSize(598, 193));
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(Login);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        usrLineEdit = new QLineEdit(Login);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));
        usrLineEdit->setMinimumSize(QSize(487, 25));
        usrLineEdit->setMaximumSize(QSize(487, 25));

        gridLayout->addWidget(usrLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pwdLineEdit = new QLineEdit(Login);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setMinimumSize(QSize(487, 25));
        pwdLineEdit->setMaximumSize(QSize(487, 25));

        gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        auloginBtn = new QPushButton(Login);
        auloginBtn->setObjectName(QStringLiteral("auloginBtn"));
        auloginBtn->setMinimumSize(QSize(83, 31));
        auloginBtn->setMaximumSize(QSize(83, 31));

        horizontalLayout->addWidget(auloginBtn);

        loginBtn = new QPushButton(Login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setMinimumSize(QSize(487, 31));
        loginBtn->setMaximumSize(QSize(487, 31));

        horizontalLayout->addWidget(loginBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        registBtn = new QPushButton(Login);
        registBtn->setObjectName(QStringLiteral("registBtn"));
        registBtn->setMinimumSize(QSize(576, 31));
        registBtn->setMaximumSize(QSize(576, 31));

        verticalLayout->addWidget(registBtn);

        exitBtn = new QPushButton(Login);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setMinimumSize(QSize(576, 31));
        exitBtn->setMaximumSize(QSize(576, 31));

        verticalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


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
        auloginBtn->setText(QApplication::translate("Login", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", Q_NULLPTR));
        registBtn->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Login", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
