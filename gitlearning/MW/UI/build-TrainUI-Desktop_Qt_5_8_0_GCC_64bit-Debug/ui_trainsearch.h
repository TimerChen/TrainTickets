/********************************************************************************
** Form generated from reading UI file 'trainsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINSEARCH_H
#define UI_TRAINSEARCH_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrainSearch
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *trainIDLineEdit;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *searchbotton;
    QPushButton *exitBtn;

    void setupUi(QDialog *TrainSearch)
    {
        if (TrainSearch->objectName().isEmpty())
            TrainSearch->setObjectName(QStringLiteral("TrainSearch"));
        TrainSearch->resize(527, 212);
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        TrainSearch->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(TrainSearch);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(TrainSearch);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        trainIDLineEdit = new QLineEdit(TrainSearch);
        trainIDLineEdit->setObjectName(QStringLiteral("trainIDLineEdit"));

        gridLayout->addWidget(trainIDLineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(TrainSearch);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        dateEdit = new QDateEdit(TrainSearch);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2017, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2020, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMaximumDate(QDate(2020, 12, 31));
        dateEdit->setMinimumDate(QDate(2015, 1, 1));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        searchbotton = new QPushButton(TrainSearch);
        searchbotton->setObjectName(QStringLiteral("searchbotton"));

        verticalLayout->addWidget(searchbotton);

        exitBtn = new QPushButton(TrainSearch);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        verticalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(TrainSearch);
        QObject::connect(exitBtn, SIGNAL(clicked()), TrainSearch, SLOT(close()));

        QMetaObject::connectSlotsByName(TrainSearch);
    } // setupUi

    void retranslateUi(QDialog *TrainSearch)
    {
        TrainSearch->setWindowTitle(QApplication::translate("TrainSearch", "\350\275\246\346\254\241\346\237\245\350\257\242", Q_NULLPTR));
        label->setText(QApplication::translate("TrainSearch", "\350\275\246\346\254\241", Q_NULLPTR));
        label_3->setText(QApplication::translate("TrainSearch", "\346\227\245\346\234\237", Q_NULLPTR));
        searchbotton->setText(QApplication::translate("TrainSearch", "\347\253\213\345\215\263\346\220\234\347\264\242", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("TrainSearch", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrainSearch: public Ui_TrainSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINSEARCH_H
