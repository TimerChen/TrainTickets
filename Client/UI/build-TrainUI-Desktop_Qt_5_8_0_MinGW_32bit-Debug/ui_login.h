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
    QPushButton *exitBtn;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(783, 354);
        Login->setMinimumSize(QSize(783, 354));
        Login->setMaximumSize(QSize(783, 354));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usrLineEdit->sizePolicy().hasHeightForWidth());
        usrLineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(usrLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pwdLineEdit = new QLineEdit(Login);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        sizePolicy.setHeightForWidth(pwdLineEdit->sizePolicy().hasHeightForWidth());
        pwdLineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        auloginBtn = new QPushButton(Login);
        auloginBtn->setObjectName(QStringLiteral("auloginBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(auloginBtn->sizePolicy().hasHeightForWidth());
        auloginBtn->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(auloginBtn);

        loginBtn = new QPushButton(Login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        sizePolicy1.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(loginBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        exitBtn = new QPushButton(Login);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        sizePolicy1.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy1);

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
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201", Q_NULLPTR));
        auloginBtn->setText(QApplication::translate("Login", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Login", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
