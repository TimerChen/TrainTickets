/********************************************************************************
** Form generated from reading UI file 'stationtostationsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONTOSTATIONSEARCH_H
#define UI_STATIONTOSTATIONSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_StationToStationSearch
{
public:

    void setupUi(QDialog *StationToStationSearch)
    {
        if (StationToStationSearch->objectName().isEmpty())
            StationToStationSearch->setObjectName(QStringLiteral("StationToStationSearch"));
        StationToStationSearch->resize(862, 760);

        retranslateUi(StationToStationSearch);

        QMetaObject::connectSlotsByName(StationToStationSearch);
    } // setupUi

    void retranslateUi(QDialog *StationToStationSearch)
    {
        StationToStationSearch->setWindowTitle(QApplication::translate("StationToStationSearch", "\347\253\231\347\253\231\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StationToStationSearch: public Ui_StationToStationSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONTOSTATIONSEARCH_H
