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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_StationToStationSearch
{
public:
    QSplitter *splitter_3;
    QPushButton *searchbotton;
    QPushButton *exitBtn;
    QSplitter *splitter;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSplitter *splitter_2;
    QLineEdit *fromLineEdit;
    QLineEdit *toLineEdit;
    QDateEdit *dateEdit;

    void setupUi(QDialog *StationToStationSearch)
    {
        if (StationToStationSearch->objectName().isEmpty())
            StationToStationSearch->setObjectName(QStringLiteral("StationToStationSearch"));
        StationToStationSearch->resize(570, 206);
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        StationToStationSearch->setWindowIcon(icon);
        splitter_3 = new QSplitter(StationToStationSearch);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(20, 110, 541, 71));
        splitter_3->setOrientation(Qt::Vertical);
        searchbotton = new QPushButton(splitter_3);
        searchbotton->setObjectName(QStringLiteral("searchbotton"));
        splitter_3->addWidget(searchbotton);
        exitBtn = new QPushButton(splitter_3);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        splitter_3->addWidget(exitBtn);
        splitter = new QSplitter(StationToStationSearch);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 10, 61, 91));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        splitter->addWidget(label);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter->addWidget(label_2);
        label_3 = new QLabel(splitter);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter->addWidget(label_3);
        splitter_2 = new QSplitter(StationToStationSearch);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(70, 10, 491, 91));
        splitter_2->setOrientation(Qt::Vertical);
        fromLineEdit = new QLineEdit(splitter_2);
        fromLineEdit->setObjectName(QStringLiteral("fromLineEdit"));
        splitter_2->addWidget(fromLineEdit);
        toLineEdit = new QLineEdit(splitter_2);
        toLineEdit->setObjectName(QStringLiteral("toLineEdit"));
        splitter_2->addWidget(toLineEdit);
        dateEdit = new QDateEdit(splitter_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2017, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2020, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMaximumDate(QDate(2020, 12, 31));
        dateEdit->setMinimumDate(QDate(2015, 1, 1));
        splitter_2->addWidget(dateEdit);

        retranslateUi(StationToStationSearch);
        QObject::connect(exitBtn, SIGNAL(clicked()), StationToStationSearch, SLOT(close()));

        QMetaObject::connectSlotsByName(StationToStationSearch);
    } // setupUi

    void retranslateUi(QDialog *StationToStationSearch)
    {
        StationToStationSearch->setWindowTitle(QApplication::translate("StationToStationSearch", "\347\253\231\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
        searchbotton->setText(QApplication::translate("StationToStationSearch", "\347\253\213\345\215\263\346\220\234\347\264\242", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("StationToStationSearch", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
        label->setText(QApplication::translate("StationToStationSearch", "\345\207\272\345\217\221", Q_NULLPTR));
        label_2->setText(QApplication::translate("StationToStationSearch", "\345\210\260\350\276\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("StationToStationSearch", "\346\227\245\346\234\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StationToStationSearch: public Ui_StationToStationSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONTOSTATIONSEARCH_H
