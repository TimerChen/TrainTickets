/********************************************************************************
** Form generated from reading UI file 'trainsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINSEARCH_H
#define UI_TRAINSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_TrainSearch
{
public:

    void setupUi(QDialog *TrainSearch)
    {
        if (TrainSearch->objectName().isEmpty())
            TrainSearch->setObjectName(QStringLiteral("TrainSearch"));
        TrainSearch->resize(792, 748);

        retranslateUi(TrainSearch);

        QMetaObject::connectSlotsByName(TrainSearch);
    } // setupUi

    void retranslateUi(QDialog *TrainSearch)
    {
        TrainSearch->setWindowTitle(QApplication::translate("TrainSearch", "\350\275\246\346\254\241\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrainSearch: public Ui_TrainSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINSEARCH_H
