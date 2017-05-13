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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Myinform
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QLabel *IDlabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *ageLineEdit;
    QLabel *label_3;
    QLineEdit *idnoLineEdit;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *oldpwdLineEdit;
    QLabel *label_6;
    QLineEdit *confirmNewPwdLindeEdit;
    QLineEdit *newpwdLineEdit;
    QLabel *label_4;
    QPushButton *changepwdButton;
    QPushButton *exitBtn;

    void setupUi(QDialog *Myinform)
    {
        if (Myinform->objectName().isEmpty())
            Myinform->setObjectName(QStringLiteral("Myinform"));
        Myinform->resize(595, 380);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        Myinform->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(Myinform);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter = new QSplitter(Myinform);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        IDlabel = new QLabel(splitter);
        IDlabel->setObjectName(QStringLiteral("IDlabel"));
        splitter->addWidget(IDlabel);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(widget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout_2->addWidget(nameLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        ageLineEdit = new QLineEdit(widget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        gridLayout_2->addWidget(ageLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        idnoLineEdit = new QLineEdit(widget);
        idnoLineEdit->setObjectName(QStringLiteral("idnoLineEdit"));

        gridLayout_2->addWidget(idnoLineEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        oldpwdLineEdit = new QLineEdit(widget);
        oldpwdLineEdit->setObjectName(QStringLiteral("oldpwdLineEdit"));

        gridLayout->addWidget(oldpwdLineEdit, 0, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        confirmNewPwdLindeEdit = new QLineEdit(widget);
        confirmNewPwdLindeEdit->setObjectName(QStringLiteral("confirmNewPwdLindeEdit"));

        gridLayout->addWidget(confirmNewPwdLindeEdit, 2, 1, 1, 1);

        newpwdLineEdit = new QLineEdit(widget);
        newpwdLineEdit->setObjectName(QStringLiteral("newpwdLineEdit"));

        gridLayout->addWidget(newpwdLineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        changepwdButton = new QPushButton(widget);
        changepwdButton->setObjectName(QStringLiteral("changepwdButton"));

        verticalLayout_2->addWidget(changepwdButton);


        horizontalLayout->addLayout(verticalLayout_2);

        splitter->addWidget(widget);

        verticalLayout_3->addWidget(splitter);

        exitBtn = new QPushButton(Myinform);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        verticalLayout_3->addWidget(exitBtn);


        retranslateUi(Myinform);
        QObject::connect(exitBtn, SIGNAL(clicked()), Myinform, SLOT(close()));

        QMetaObject::connectSlotsByName(Myinform);
    } // setupUi

    void retranslateUi(QDialog *Myinform)
    {
        Myinform->setWindowTitle(QApplication::translate("Myinform", "myinform", Q_NULLPTR));
        IDlabel->setText(QApplication::translate("Myinform", "ID:", Q_NULLPTR));
        label->setText(QApplication::translate("Myinform", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Myinform", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Myinform", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Myinform", "\344\277\235\345\255\230\344\277\256\346\224\271", Q_NULLPTR));
        label_5->setText(QApplication::translate("Myinform", "\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("Myinform", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Myinform", "\346\227\247\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        changepwdButton->setText(QApplication::translate("Myinform", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Myinform", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Myinform: public Ui_Myinform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINFORM_H
