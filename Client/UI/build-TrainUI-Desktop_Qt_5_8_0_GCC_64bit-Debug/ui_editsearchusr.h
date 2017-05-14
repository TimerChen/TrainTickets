/********************************************************************************
** Form generated from reading UI file 'editsearchusr.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSEARCHUSR_H
#define UI_EDITSEARCHUSR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editSearchUsr
{
public:
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *myticketBtn_2;
    QPushButton *myinformBtn_2;
    QPushButton *deleteUsrBtn;
    QLabel *label;
    QSplitter *splitter;
    QPushButton *stationToStationSearchBtn_2;
    QPushButton *trainSearchBtn_2;
    QPushButton *stationSearchBtn_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *nameLabel_2;
    QLabel *welcomeLabel_2;

    void setupUi(QDialog *editSearchUsr)
    {
        if (editSearchUsr->objectName().isEmpty())
            editSearchUsr->setObjectName(QStringLiteral("editSearchUsr"));
        editSearchUsr->resize(826, 800);
        label_3 = new QLabel(editSearchUsr);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 250, 91, 41));
        label_3->setScaledContents(false);
        layoutWidget = new QWidget(editSearchUsr);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 690, 691, 60));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        myticketBtn_2 = new QPushButton(layoutWidget);
        myticketBtn_2->setObjectName(QStringLiteral("myticketBtn_2"));
        myticketBtn_2->setMinimumSize(QSize(222, 58));
        myticketBtn_2->setMaximumSize(QSize(222, 58));

        horizontalLayout_2->addWidget(myticketBtn_2);

        myinformBtn_2 = new QPushButton(layoutWidget);
        myinformBtn_2->setObjectName(QStringLiteral("myinformBtn_2"));
        myinformBtn_2->setMinimumSize(QSize(221, 58));
        myinformBtn_2->setMaximumSize(QSize(221, 58));

        horizontalLayout_2->addWidget(myinformBtn_2);

        deleteUsrBtn = new QPushButton(layoutWidget);
        deleteUsrBtn->setObjectName(QStringLiteral("deleteUsrBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteUsrBtn->sizePolicy().hasHeightForWidth());
        deleteUsrBtn->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(deleteUsrBtn);

        label = new QLabel(editSearchUsr);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 241, 251));
        label->setMinimumSize(QSize(241, 251));
        label->setMaximumSize(QSize(241, 251));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/12308.png")));
        label->setScaledContents(true);
        splitter = new QSplitter(editSearchUsr);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(60, 310, 691, 351));
        splitter->setMinimumSize(QSize(691, 351));
        splitter->setMaximumSize(QSize(691, 343));
        splitter->setOrientation(Qt::Vertical);
        stationToStationSearchBtn_2 = new QPushButton(splitter);
        stationToStationSearchBtn_2->setObjectName(QStringLiteral("stationToStationSearchBtn_2"));
        stationToStationSearchBtn_2->setMinimumSize(QSize(691, 112));
        stationToStationSearchBtn_2->setMaximumSize(QSize(691, 112));
        splitter->addWidget(stationToStationSearchBtn_2);
        trainSearchBtn_2 = new QPushButton(splitter);
        trainSearchBtn_2->setObjectName(QStringLiteral("trainSearchBtn_2"));
        trainSearchBtn_2->setMinimumSize(QSize(691, 111));
        trainSearchBtn_2->setMaximumSize(QSize(691, 111));
        splitter->addWidget(trainSearchBtn_2);
        stationSearchBtn_2 = new QPushButton(splitter);
        stationSearchBtn_2->setObjectName(QStringLiteral("stationSearchBtn_2"));
        stationSearchBtn_2->setMinimumSize(QSize(691, 112));
        stationSearchBtn_2->setMaximumSize(QSize(691, 112));
        splitter->addWidget(stationSearchBtn_2);
        widget = new QWidget(editSearchUsr);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(341, 41, 401, 221));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLabel_2 = new QLabel(widget);
        nameLabel_2->setObjectName(QStringLiteral("nameLabel_2"));
        nameLabel_2->setTextFormat(Qt::AutoText);
        nameLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(nameLabel_2, 1, 1, 1, 1);

        welcomeLabel_2 = new QLabel(widget);
        welcomeLabel_2->setObjectName(QStringLiteral("welcomeLabel_2"));

        gridLayout_2->addWidget(welcomeLabel_2, 0, 1, 1, 1);


        retranslateUi(editSearchUsr);

        QMetaObject::connectSlotsByName(editSearchUsr);
    } // setupUi

    void retranslateUi(QDialog *editSearchUsr)
    {
        editSearchUsr->setWindowTitle(QApplication::translate("editSearchUsr", "\344\277\256\346\224\271\347\224\250\346\210\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("editSearchUsr", "12308", Q_NULLPTR));
        myticketBtn_2->setText(QApplication::translate("editSearchUsr", "\347\224\250\346\210\267\350\275\246\347\245\250", Q_NULLPTR));
        myinformBtn_2->setText(QApplication::translate("editSearchUsr", "\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        deleteUsrBtn->setText(QApplication::translate("editSearchUsr", "\345\210\240\351\231\244\347\224\250\346\210\267", Q_NULLPTR));
        label->setText(QString());
        stationToStationSearchBtn_2->setText(QApplication::translate("editSearchUsr", "\347\253\231\347\253\231\346\237\245\350\257\242\357\274\210\345\217\257\344\277\256\346\224\271\347\224\250\346\210\267\350\275\246\347\245\250\357\274\211", Q_NULLPTR));
        trainSearchBtn_2->setText(QApplication::translate("editSearchUsr", "\350\275\246\346\254\241\346\237\245\350\257\242\357\274\210\344\270\215\345\217\257\344\277\256\346\224\271\347\224\250\346\210\267\350\275\246\347\245\250\357\274\211", Q_NULLPTR));
        stationSearchBtn_2->setText(QApplication::translate("editSearchUsr", "\350\275\246\347\253\231\346\237\245\350\257\242\357\274\210\344\270\215\345\217\257\344\277\256\346\224\271\347\224\250\346\210\267\350\275\246\347\245\250)", Q_NULLPTR));
        nameLabel_2->setText(QApplication::translate("editSearchUsr", "name", Q_NULLPTR));
        welcomeLabel_2->setText(QApplication::translate("editSearchUsr", "\346\254\242\350\277\216\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class editSearchUsr: public Ui_editSearchUsr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSEARCHUSR_H
