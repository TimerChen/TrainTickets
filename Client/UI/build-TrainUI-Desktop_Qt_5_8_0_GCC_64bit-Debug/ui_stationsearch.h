/********************************************************************************
** Form generated from reading UI file 'stationsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONSEARCH_H
#define UI_STATIONSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_StationSearch
{
public:

    void setupUi(QDialog *StationSearch)
    {
        if (StationSearch->objectName().isEmpty())
            StationSearch->setObjectName(QStringLiteral("StationSearch"));
        StationSearch->resize(1045, 909);

        retranslateUi(StationSearch);

        QMetaObject::connectSlotsByName(StationSearch);
    } // setupUi

    void retranslateUi(QDialog *StationSearch)
    {
        StationSearch->setWindowTitle(QApplication::translate("StationSearch", "\350\275\246\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StationSearch: public Ui_StationSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONSEARCH_H
