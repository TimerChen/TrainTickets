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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QPushButton *changenameBtn;
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
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout_2->addWidget(nameLineEdit, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        changenameBtn = new QPushButton(layoutWidget);
        changenameBtn->setObjectName(QStringLiteral("changenameBtn"));

        verticalLayout->addWidget(changenameBtn);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        oldpwdLineEdit = new QLineEdit(layoutWidget);
        oldpwdLineEdit->setObjectName(QStringLiteral("oldpwdLineEdit"));

        gridLayout->addWidget(oldpwdLineEdit, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        confirmNewPwdLindeEdit = new QLineEdit(layoutWidget);
        confirmNewPwdLindeEdit->setObjectName(QStringLiteral("confirmNewPwdLindeEdit"));

        gridLayout->addWidget(confirmNewPwdLindeEdit, 2, 1, 1, 1);

        newpwdLineEdit = new QLineEdit(layoutWidget);
        newpwdLineEdit->setObjectName(QStringLiteral("newpwdLineEdit"));

        gridLayout->addWidget(newpwdLineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        changepwdButton = new QPushButton(layoutWidget);
        changepwdButton->setObjectName(QStringLiteral("changepwdButton"));

        verticalLayout_2->addWidget(changepwdButton);


        horizontalLayout->addLayout(verticalLayout_2);

        splitter->addWidget(layoutWidget);

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
        changenameBtn->setText(QApplication::translate("Myinform", "\344\277\235\345\255\230\344\277\256\346\224\271", Q_NULLPTR));
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
