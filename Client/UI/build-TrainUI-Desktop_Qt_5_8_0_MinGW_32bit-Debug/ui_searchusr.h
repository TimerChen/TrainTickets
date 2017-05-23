/********************************************************************************
** Form generated from reading UI file 'searchusr.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHUSR_H
#define UI_SEARCHUSR_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_searchUsr
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *searchUsrIDLineEdit;
    QPushButton *searchBtn;

    void setupUi(QDialog *searchUsr)
    {
        if (searchUsr->objectName().isEmpty())
            searchUsr->setObjectName(QStringLiteral("searchUsr"));
        searchUsr->resize(457, 88);
        verticalLayout_2 = new QVBoxLayout(searchUsr);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(searchUsr);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        searchUsrIDLineEdit = new QLineEdit(searchUsr);
        searchUsrIDLineEdit->setObjectName(QStringLiteral("searchUsrIDLineEdit"));

        horizontalLayout->addWidget(searchUsrIDLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        searchBtn = new QPushButton(searchUsr);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));

        verticalLayout->addWidget(searchBtn);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(searchUsr);

        QMetaObject::connectSlotsByName(searchUsr);
    } // setupUi

    void retranslateUi(QDialog *searchUsr)
    {
        searchUsr->setWindowTitle(QApplication::translate("searchUsr", "\346\237\245\346\211\276\347\224\250\346\210\267", Q_NULLPTR));
        label->setText(QApplication::translate("searchUsr", "\347\224\250\346\210\267ID\357\274\232", Q_NULLPTR));
        searchBtn->setText(QApplication::translate("searchUsr", "\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class searchUsr: public Ui_searchUsr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHUSR_H
