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
    QPushButton *registBtn;
    QPushButton *exitButton;

    void setupUi(QDialog *Regist)
    {
        if (Regist->objectName().isEmpty())
            Regist->setObjectName(QStringLiteral("Regist"));
        Regist->resize(789, 338);
        Regist->setMinimumSize(QSize(789, 338));
        Regist->setMaximumSize(QSize(789, 338));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usrLineEdit->sizePolicy().hasHeightForWidth());
        usrLineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(usrLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(Regist);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pwdLineEdit = new QLineEdit(Regist);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        sizePolicy.setHeightForWidth(pwdLineEdit->sizePolicy().hasHeightForWidth());
        pwdLineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(Regist);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        confirmpwdLineEdit = new QLineEdit(Regist);
        confirmpwdLineEdit->setObjectName(QStringLiteral("confirmpwdLineEdit"));
        sizePolicy.setHeightForWidth(confirmpwdLineEdit->sizePolicy().hasHeightForWidth());
        confirmpwdLineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(confirmpwdLineEdit, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        registBtn = new QPushButton(Regist);
        registBtn->setObjectName(QStringLiteral("registBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(registBtn->sizePolicy().hasHeightForWidth());
        registBtn->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(registBtn);

        exitButton = new QPushButton(Regist);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);

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
        label->setText(QApplication::translate("Regist", "\347\224\250\346\210\267ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("Regist", "\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("Regist", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        registBtn->setText(QApplication::translate("Regist", "\346\263\250\345\206\214", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Regist", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Regist: public Ui_Regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
