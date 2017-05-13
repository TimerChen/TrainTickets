/********************************************************************************
** Form generated from reading UI file 'modifyplanofatrain.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPLANOFATRAIN_H
#define UI_MODIFYPLANOFATRAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_modifyPlanOfATrain
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QLabel *accountLabel;
    QLabel *trainLabel;
    QSplitter *splitter;
    QPushButton *startsellBtn;
    QPushButton *stopSellBtn;
    QPushButton *deleteTrainBtn;

    void setupUi(QDialog *modifyPlanOfATrain)
    {
        if (modifyPlanOfATrain->objectName().isEmpty())
            modifyPlanOfATrain->setObjectName(QStringLiteral("modifyPlanOfATrain"));
        modifyPlanOfATrain->resize(610, 587);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifyPlanOfATrain->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(modifyPlanOfATrain);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        splitter_2 = new QSplitter(modifyPlanOfATrain);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        accountLabel = new QLabel(splitter_2);
        accountLabel->setObjectName(QStringLiteral("accountLabel"));
        splitter_2->addWidget(accountLabel);
        trainLabel = new QLabel(splitter_2);
        trainLabel->setObjectName(QStringLiteral("trainLabel"));
        splitter_2->addWidget(trainLabel);

        verticalLayout->addWidget(splitter_2);

        splitter = new QSplitter(modifyPlanOfATrain);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        startsellBtn = new QPushButton(splitter);
        startsellBtn->setObjectName(QStringLiteral("startsellBtn"));
        splitter->addWidget(startsellBtn);
        stopSellBtn = new QPushButton(splitter);
        stopSellBtn->setObjectName(QStringLiteral("stopSellBtn"));
        splitter->addWidget(stopSellBtn);
        deleteTrainBtn = new QPushButton(splitter);
        deleteTrainBtn->setObjectName(QStringLiteral("deleteTrainBtn"));
        splitter->addWidget(deleteTrainBtn);

        verticalLayout->addWidget(splitter);


        retranslateUi(modifyPlanOfATrain);

        QMetaObject::connectSlotsByName(modifyPlanOfATrain);
    } // setupUi

    void retranslateUi(QDialog *modifyPlanOfATrain)
    {
        modifyPlanOfATrain->setWindowTitle(QApplication::translate("modifyPlanOfATrain", "\344\277\256\346\224\271\350\275\246\346\254\241\350\256\241\345\210\222", Q_NULLPTR));
        accountLabel->setText(QApplication::translate("modifyPlanOfATrain", "TextLabel", Q_NULLPTR));
        trainLabel->setText(QApplication::translate("modifyPlanOfATrain", "TextLabel", Q_NULLPTR));
        startsellBtn->setText(QApplication::translate("modifyPlanOfATrain", "\345\274\200\345\247\213\345\217\221\345\224\256", Q_NULLPTR));
        stopSellBtn->setText(QApplication::translate("modifyPlanOfATrain", "\345\201\234\346\255\242\345\224\256\347\245\250", Q_NULLPTR));
        deleteTrainBtn->setText(QApplication::translate("modifyPlanOfATrain", "\345\210\240\351\231\244\350\275\246\346\254\241", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modifyPlanOfATrain: public Ui_modifyPlanOfATrain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPLANOFATRAIN_H
