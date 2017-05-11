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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Myinform
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ageLineEdit;
    QLabel *label_3;
    QLineEdit *idnoLineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *changepwdButton;

    void setupUi(QDialog *Myinform)
    {
        if (Myinform->objectName().isEmpty())
            Myinform->setObjectName(QStringLiteral("Myinform"));
        Myinform->resize(975, 380);
        QIcon icon;
        icon.addFile(QStringLiteral("12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        Myinform->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(Myinform);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Myinform);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(Myinform);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Myinform);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ageLineEdit = new QLineEdit(Myinform);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        horizontalLayout_2->addWidget(ageLineEdit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        label_3 = new QLabel(Myinform);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        idnoLineEdit = new QLineEdit(Myinform);
        idnoLineEdit->setObjectName(QStringLiteral("idnoLineEdit"));

        gridLayout->addWidget(idnoLineEdit, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(Myinform);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        changepwdButton = new QPushButton(Myinform);
        changepwdButton->setObjectName(QStringLiteral("changepwdButton"));

        verticalLayout->addWidget(changepwdButton);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


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
