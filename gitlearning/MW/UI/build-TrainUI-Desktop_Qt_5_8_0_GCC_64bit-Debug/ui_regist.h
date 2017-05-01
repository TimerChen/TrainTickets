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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QLineEdit *confirmpwdLineEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *loginBtn;
    QPushButton *backtologinBtn;
    QPushButton *exitButton;

    void setupUi(QDialog *Regist)
    {
        if (Regist->objectName().isEmpty())
            Regist->setObjectName(QStringLiteral("Regist"));
        Regist->resize(858, 442);
        Regist->setMinimumSize(QSize(858, 442));
        Regist->setMaximumSize(QSize(858, 442));
        layoutWidget = new QWidget(Regist);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(49, 30, 118, 158));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        layoutWidget1 = new QWidget(Regist);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(220, 30, 591, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usrLineEdit = new QLineEdit(layoutWidget1);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));

        verticalLayout_2->addWidget(usrLineEdit);

        pwdLineEdit = new QLineEdit(layoutWidget1);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));

        verticalLayout_2->addWidget(pwdLineEdit);

        confirmpwdLineEdit = new QLineEdit(layoutWidget1);
        confirmpwdLineEdit->setObjectName(QStringLiteral("confirmpwdLineEdit"));

        verticalLayout_2->addWidget(confirmpwdLineEdit);

        layoutWidget2 = new QWidget(Regist);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(46, 210, 771, 200));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        loginBtn = new QPushButton(layoutWidget2);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        verticalLayout_3->addWidget(loginBtn);

        backtologinBtn = new QPushButton(layoutWidget2);
        backtologinBtn->setObjectName(QStringLiteral("backtologinBtn"));

        verticalLayout_3->addWidget(backtologinBtn);

        exitButton = new QPushButton(layoutWidget2);
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
