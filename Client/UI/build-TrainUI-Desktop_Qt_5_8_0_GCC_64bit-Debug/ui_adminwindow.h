/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *welcomeLabel;
    QLabel *nameLabel;
    QSplitter *splitter;
    QPushButton *trainSearchBtn;
    QPushButton *addPlanBtn;
    QPushButton *searchAccountBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_3;
    QSplitter *splitter_2;
    QPushButton *pushButton;
    QPushButton *myinformBtn;
    QPushButton *logoutBtn;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(826, 800);
        AdminWindow->setMinimumSize(QSize(826, 800));
        AdminWindow->setMaximumSize(QSize(826, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminWindow->setWindowIcon(icon);
        layoutWidget_2 = new QWidget(AdminWindow);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(310, 60, 421, 181));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        welcomeLabel = new QLabel(layoutWidget_2);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(welcomeLabel, 0, 0, 1, 1);

        nameLabel = new QLabel(layoutWidget_2);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setTextFormat(Qt::AutoText);
        nameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        splitter = new QSplitter(AdminWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(60, 310, 671, 281));
        splitter->setOrientation(Qt::Vertical);
        trainSearchBtn = new QPushButton(splitter);
        trainSearchBtn->setObjectName(QStringLiteral("trainSearchBtn"));
        splitter->addWidget(trainSearchBtn);
        addPlanBtn = new QPushButton(splitter);
        addPlanBtn->setObjectName(QStringLiteral("addPlanBtn"));
        splitter->addWidget(addPlanBtn);
        searchAccountBtn = new QPushButton(splitter);
        searchAccountBtn->setObjectName(QStringLiteral("searchAccountBtn"));
        splitter->addWidget(searchAccountBtn);
        layoutWidget = new QWidget(AdminWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 20, 251, 271));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(241, 251));
        label->setMaximumSize(QSize(241, 251));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/12308.png")));
        label->setScaledContents(true);

        verticalLayout_3->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        splitter_2 = new QSplitter(AdminWindow);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(61, 640, 671, 61));
        splitter_2->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        splitter_2->addWidget(pushButton);
        myinformBtn = new QPushButton(splitter_2);
        myinformBtn->setObjectName(QStringLiteral("myinformBtn"));
        sizePolicy.setHeightForWidth(myinformBtn->sizePolicy().hasHeightForWidth());
        myinformBtn->setSizePolicy(sizePolicy);
        splitter_2->addWidget(myinformBtn);
        logoutBtn = new QPushButton(splitter_2);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));
        sizePolicy.setHeightForWidth(logoutBtn->sizePolicy().hasHeightForWidth());
        logoutBtn->setSizePolicy(sizePolicy);
        splitter_2->addWidget(logoutBtn);
        splitter_2->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();
        splitter->raise();

        retranslateUi(AdminWindow);
        QObject::connect(logoutBtn, SIGNAL(clicked()), AdminWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        welcomeLabel->setText(QApplication::translate("AdminWindow", "\346\254\242\350\277\216\357\274\201", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("AdminWindow", "name", Q_NULLPTR));
        trainSearchBtn->setText(QApplication::translate("AdminWindow", "\350\275\246\346\254\241\346\237\245\350\257\242\357\274\210\344\277\256\346\224\271\350\277\220\350\241\214\350\256\241\345\210\222\357\274\211", Q_NULLPTR));
        addPlanBtn->setText(QApplication::translate("AdminWindow", "\346\267\273\345\212\240\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        searchAccountBtn->setText(QApplication::translate("AdminWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QApplication::translate("AdminWindow", "12308", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AdminWindow", "\346\237\245\350\257\242\347\263\273\347\273\237\346\227\245\345\277\227", Q_NULLPTR));
        myinformBtn->setText(QApplication::translate("AdminWindow", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257", Q_NULLPTR));
        logoutBtn->setText(QApplication::translate("AdminWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
