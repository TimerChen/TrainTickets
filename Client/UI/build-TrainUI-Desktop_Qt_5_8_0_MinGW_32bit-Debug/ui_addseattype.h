/********************************************************************************
** Form generated from reading UI file 'addseattype.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSEATTYPE_H
#define UI_ADDSEATTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_addSeatType
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *addSeatType)
    {
        if (addSeatType->objectName().isEmpty())
            addSeatType->setObjectName(QStringLiteral("addSeatType"));
        addSeatType->resize(400, 300);
        lineEdit = new QLineEdit(addSeatType);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 70, 113, 20));
        lineEdit_2 = new QLineEdit(addSeatType);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 110, 113, 20));

        retranslateUi(addSeatType);

        QMetaObject::connectSlotsByName(addSeatType);
    } // setupUi

    void retranslateUi(QDialog *addSeatType)
    {
        addSeatType->setWindowTitle(QApplication::translate("addSeatType", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addSeatType: public Ui_addSeatType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSEATTYPE_H
