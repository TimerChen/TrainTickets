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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Regist
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *usrLineEdit;
    QLabel *label_2;
    QLineEdit *pwdLineEdit;
    QLabel *label_3;
    QLineEdit *confirmpwdLineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *loginBtn;
    QPushButton *backtologinBtn;
    QPushButton *exitButton;

    void setupUi(QDialog *Regist)
    {
        if (Regist->objectName().isEmpty())
            Regist->setObjectName(QStringLiteral("Regist"));
        Regist->resize(603, 249);
        Regist->setMinimumSize(QSize(603, 249));
        Regist->setMaximumSize(QSize(603, 249));
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        Regist->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(Regist);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Regist);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        usrLineEdit = new QLineEdit(Regist);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));

        gridLayout->addWidget(usrLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(Regist);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pwdLineEdit = new QLineEdit(Regist);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));

        gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(Regist);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        confirmpwdLineEdit = new QLineEdit(Regist);
        confirmpwdLineEdit->setObjectName(QStringLiteral("confirmpwdLineEdit"));

        gridLayout->addWidget(confirmpwdLineEdit, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        loginBtn = new QPushButton(Regist);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        verticalLayout->addWidget(loginBtn);

        backtologinBtn = new QPushButton(Regist);
        backtologinBtn->setObjectName(QStringLiteral("backtologinBtn"));

        verticalLayout->addWidget(backtologinBtn);

        exitButton = new QPushButton(Regist);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        verticalLayout->addWidget(exitButton);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


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
