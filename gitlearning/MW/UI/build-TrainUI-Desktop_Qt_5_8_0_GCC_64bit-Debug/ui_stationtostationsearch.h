/********************************************************************************
** Form generated from reading UI file 'stationtostationsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONTOSTATIONSEARCH_H
#define UI_STATIONTOSTATIONSEARCH_H

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

class Ui_StationToStationSearch
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *fromLineEdit;
    QLabel *label_2;
    QLineEdit *toLineEdit;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *searchbotton;
    QPushButton *exitBtn;

    void setupUi(QDialog *StationToStationSearch)
    {
        if (StationToStationSearch->objectName().isEmpty())
            StationToStationSearch->setObjectName(QStringLiteral("StationToStationSearch"));
        StationToStationSearch->resize(570, 206);
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        StationToStationSearch->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(StationToStationSearch);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(StationToStationSearch);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        fromLineEdit = new QLineEdit(StationToStationSearch);
        fromLineEdit->setObjectName(QStringLiteral("fromLineEdit"));

        gridLayout->addWidget(fromLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(StationToStationSearch);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        toLineEdit = new QLineEdit(StationToStationSearch);
        toLineEdit->setObjectName(QStringLiteral("toLineEdit"));

        gridLayout->addWidget(toLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(StationToStationSearch);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        dateEdit = new QDateEdit(StationToStationSearch);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2017, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2020, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMaximumDate(QDate(2020, 12, 31));
        dateEdit->setMinimumDate(QDate(2015, 1, 1));

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        searchbotton = new QPushButton(StationToStationSearch);
        searchbotton->setObjectName(QStringLiteral("searchbotton"));

        verticalLayout->addWidget(searchbotton);

        exitBtn = new QPushButton(StationToStationSearch);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        verticalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(StationToStationSearch);
        QObject::connect(exitBtn, SIGNAL(clicked()), StationToStationSearch, SLOT(close()));

        QMetaObject::connectSlotsByName(StationToStationSearch);
    } // setupUi

    void retranslateUi(QDialog *StationToStationSearch)
    {
        StationToStationSearch->setWindowTitle(QApplication::translate("StationToStationSearch", "\347\253\231\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
        label->setText(QApplication::translate("StationToStationSearch", "\345\207\272\345\217\221", Q_NULLPTR));
        label_2->setText(QApplication::translate("StationToStationSearch", "\345\210\260\350\276\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("StationToStationSearch", "\346\227\245\346\234\237", Q_NULLPTR));
        searchbotton->setText(QApplication::translate("StationToStationSearch", "\347\253\213\345\215\263\346\220\234\347\264\242", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("StationToStationSearch", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StationToStationSearch: public Ui_StationToStationSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONTOSTATIONSEARCH_H
