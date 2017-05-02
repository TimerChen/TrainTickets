/********************************************************************************
** Form generated from reading UI file 'myinform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINFORM_H
#define UI_MYINFORM_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Myinform
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ageLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *idnoLineEdit;
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *changepwdButton;

    void setupUi(QDialog *Myinform)
    {
        if (Myinform->objectName().isEmpty())
            Myinform->setObjectName(QStringLiteral("Myinform"));
        Myinform->resize(712, 686);
        widget = new QWidget(Myinform);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 40, 621, 164));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(widget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ageLineEdit = new QLineEdit(widget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        horizontalLayout_2->addWidget(ageLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        idnoLineEdit = new QLineEdit(widget);
        idnoLineEdit->setObjectName(QStringLiteral("idnoLineEdit"));

        horizontalLayout_3->addWidget(idnoLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        splitter = new QSplitter(Myinform);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(50, 360, 581, 58));
        splitter->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter->addWidget(pushButton);
        changepwdButton = new QPushButton(splitter);
        changepwdButton->setObjectName(QStringLiteral("changepwdButton"));
        splitter->addWidget(changepwdButton);

        retranslateUi(Myinform);

        QMetaObject::connectSlotsByName(Myinform);
    } // setupUi

    void retranslateUi(QDialog *Myinform)
    {
        Myinform->setWindowTitle(QApplication::translate("Myinform", "myinform", Q_NULLPTR));
        label->setText(QApplication::translate("Myinform", "\345\247\223\345\220\215\357\274\232         ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Myinform", "\345\271\264\351\276\204\357\274\232         ", Q_NULLPTR));
        label_3->setText(QApplication::translate("Myinform", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Myinform", "\344\277\235\345\255\230\344\277\256\346\224\271", Q_NULLPTR));
        changepwdButton->setText(QApplication::translate("Myinform", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Myinform: public Ui_Myinform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINFORM_H
