/********************************************************************************
** Form generated from reading UI file 'stationsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONSEARCH_H
#define UI_STATIONSEARCH_H

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

class Ui_StationSearch
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QDateEdit *dateEdit;
    QLineEdit *stationLineEdit;
    QLabel *label_3;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *searchbotton;
    QPushButton *exitBtn;

    void setupUi(QDialog *StationSearch)
    {
        if (StationSearch->objectName().isEmpty())
            StationSearch->setObjectName(QStringLiteral("StationSearch"));
        StationSearch->resize(800, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        StationSearch->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(StationSearch);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dateEdit = new QDateEdit(StationSearch);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);
        dateEdit->setDateTime(QDateTime(QDate(2017, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2020, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMaximumDate(QDate(2020, 12, 31));
        dateEdit->setMinimumDate(QDate(2015, 1, 1));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 1);

        stationLineEdit = new QLineEdit(StationSearch);
        stationLineEdit->setObjectName(QStringLiteral("stationLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stationLineEdit->sizePolicy().hasHeightForWidth());
        stationLineEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(stationLineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(StationSearch);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label = new QLabel(StationSearch);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        searchbotton = new QPushButton(StationSearch);
        searchbotton->setObjectName(QStringLiteral("searchbotton"));
        sizePolicy.setHeightForWidth(searchbotton->sizePolicy().hasHeightForWidth());
        searchbotton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(searchbotton);

        exitBtn = new QPushButton(StationSearch);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        sizePolicy.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(StationSearch);
        QObject::connect(exitBtn, SIGNAL(clicked()), StationSearch, SLOT(close()));

        QMetaObject::connectSlotsByName(StationSearch);
    } // setupUi

    void retranslateUi(QDialog *StationSearch)
    {
        StationSearch->setWindowTitle(QApplication::translate("StationSearch", "\350\275\246\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("StationSearch", "\346\227\245\346\234\237\357\274\232 ", Q_NULLPTR));
        label->setText(QApplication::translate("StationSearch", "\347\253\231\347\202\271\357\274\232 ", Q_NULLPTR));
        searchbotton->setText(QApplication::translate("StationSearch", "\347\253\213\345\215\263\346\220\234\347\264\242", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("StationSearch", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StationSearch: public Ui_StationSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONSEARCH_H
