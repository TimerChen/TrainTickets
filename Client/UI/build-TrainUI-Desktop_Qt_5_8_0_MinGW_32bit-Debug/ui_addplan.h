/********************************************************************************
** Form generated from reading UI file 'addplan.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAN_H
#define UI_ADDPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addPlan
{
public:
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *trainIDLineEdit;
    QLineEdit *fromStationLineEdit;
    QLineEdit *endStationLineEdit;
    QLineEdit *remainTicketsLineEdit;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QTableView *seatTypeTableView;
    QPushButton *addSearTypeBtn;
    QPushButton *deleteSeatTypeBtn;
    QTableView *stationsTableView;
    QPushButton *addStationBtn;
    QPushButton *deleteStationBtn;
    QPushButton *setEndStationPriceBtn;
    QPushButton *completeBtn;

    void setupUi(QDialog *addPlan)
    {
        if (addPlan->objectName().isEmpty())
            addPlan->setObjectName(QStringLiteral("addPlan"));
        addPlan->resize(451, 491);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        addPlan->setWindowIcon(icon);
        verticalLayout_5 = new QVBoxLayout(addPlan);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(addPlan);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(addPlan);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(addPlan);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_5 = new QLabel(addPlan);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        trainIDLineEdit = new QLineEdit(addPlan);
        trainIDLineEdit->setObjectName(QStringLiteral("trainIDLineEdit"));

        verticalLayout_3->addWidget(trainIDLineEdit);

        fromStationLineEdit = new QLineEdit(addPlan);
        fromStationLineEdit->setObjectName(QStringLiteral("fromStationLineEdit"));

        verticalLayout_3->addWidget(fromStationLineEdit);

        endStationLineEdit = new QLineEdit(addPlan);
        endStationLineEdit->setObjectName(QStringLiteral("endStationLineEdit"));

        verticalLayout_3->addWidget(endStationLineEdit);

        remainTicketsLineEdit = new QLineEdit(addPlan);
        remainTicketsLineEdit->setObjectName(QStringLiteral("remainTicketsLineEdit"));

        verticalLayout_3->addWidget(remainTicketsLineEdit);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        seatTypeTableView = new QTableView(addPlan);
        seatTypeTableView->setObjectName(QStringLiteral("seatTypeTableView"));

        verticalLayout->addWidget(seatTypeTableView);

        addSearTypeBtn = new QPushButton(addPlan);
        addSearTypeBtn->setObjectName(QStringLiteral("addSearTypeBtn"));

        verticalLayout->addWidget(addSearTypeBtn);

        deleteSeatTypeBtn = new QPushButton(addPlan);
        deleteSeatTypeBtn->setObjectName(QStringLiteral("deleteSeatTypeBtn"));

        verticalLayout->addWidget(deleteSeatTypeBtn);

        stationsTableView = new QTableView(addPlan);
        stationsTableView->setObjectName(QStringLiteral("stationsTableView"));

        verticalLayout->addWidget(stationsTableView);

        addStationBtn = new QPushButton(addPlan);
        addStationBtn->setObjectName(QStringLiteral("addStationBtn"));

        verticalLayout->addWidget(addStationBtn);

        deleteStationBtn = new QPushButton(addPlan);
        deleteStationBtn->setObjectName(QStringLiteral("deleteStationBtn"));

        verticalLayout->addWidget(deleteStationBtn);

        setEndStationPriceBtn = new QPushButton(addPlan);
        setEndStationPriceBtn->setObjectName(QStringLiteral("setEndStationPriceBtn"));

        verticalLayout->addWidget(setEndStationPriceBtn);


        verticalLayout_4->addLayout(verticalLayout);

        completeBtn = new QPushButton(addPlan);
        completeBtn->setObjectName(QStringLiteral("completeBtn"));

        verticalLayout_4->addWidget(completeBtn);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(addPlan);

        QMetaObject::connectSlotsByName(addPlan);
    } // setupUi

    void retranslateUi(QDialog *addPlan)
    {
        addPlan->setWindowTitle(QApplication::translate("addPlan", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("addPlan", "\350\275\246\346\254\241:", Q_NULLPTR));
        label_2->setText(QApplication::translate("addPlan", "\350\265\267\347\202\271\347\253\231\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("addPlan", "\347\273\210\347\202\271\347\253\231\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("addPlan", "\344\275\231\347\245\250\345\274\240\346\225\260\357\274\232", Q_NULLPTR));
        addSearTypeBtn->setText(QApplication::translate("addPlan", "\346\267\273\345\212\240\345\272\247\344\275\215\347\261\273\345\236\213", Q_NULLPTR));
        deleteSeatTypeBtn->setText(QApplication::translate("addPlan", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", Q_NULLPTR));
        addStationBtn->setText(QApplication::translate("addPlan", "\346\267\273\345\212\240\347\273\217\345\201\234\347\253\231", Q_NULLPTR));
        deleteStationBtn->setText(QApplication::translate("addPlan", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", Q_NULLPTR));
        setEndStationPriceBtn->setText(QApplication::translate("addPlan", "\350\256\276\347\275\256\347\273\210\347\202\271\347\253\231\347\245\250\344\273\267", Q_NULLPTR));
        completeBtn->setText(QApplication::translate("addPlan", "\346\267\273\345\212\240\350\256\241\345\210\222", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addPlan: public Ui_addPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAN_H
