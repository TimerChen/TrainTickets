/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_3;
    QSplitter *splitter;
    QPushButton *stationToStationSearchBtn;
    QPushButton *trainSearchBtn;
    QPushButton *stationSearchBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *myticketBtn;
    QPushButton *myinformBtn;
    QPushButton *logoutBtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *welcomeLabel;
    QVBoxLayout *verticalLayout_2;
    QPushButton *loginBtn;
    QPushButton *regBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(826, 800);
        MainWindow->setMinimumSize(QSize(826, 800));
        MainWindow->setMaximumSize(QSize(826, 800));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/12308.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 241, 251));
        label->setMinimumSize(QSize(241, 251));
        label->setMaximumSize(QSize(241, 251));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/12308.png")));
        label->setScaledContents(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 240, 91, 41));
        label_3->setScaledContents(false);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(60, 300, 691, 351));
        splitter->setMinimumSize(QSize(691, 351));
        splitter->setMaximumSize(QSize(691, 343));
        splitter->setOrientation(Qt::Vertical);
        stationToStationSearchBtn = new QPushButton(splitter);
        stationToStationSearchBtn->setObjectName(QStringLiteral("stationToStationSearchBtn"));
        stationToStationSearchBtn->setMinimumSize(QSize(691, 112));
        stationToStationSearchBtn->setMaximumSize(QSize(691, 112));
        splitter->addWidget(stationToStationSearchBtn);
        trainSearchBtn = new QPushButton(splitter);
        trainSearchBtn->setObjectName(QStringLiteral("trainSearchBtn"));
        trainSearchBtn->setMinimumSize(QSize(691, 111));
        trainSearchBtn->setMaximumSize(QSize(691, 111));
        splitter->addWidget(trainSearchBtn);
        stationSearchBtn = new QPushButton(splitter);
        stationSearchBtn->setObjectName(QStringLiteral("stationSearchBtn"));
        stationSearchBtn->setMinimumSize(QSize(691, 112));
        stationSearchBtn->setMaximumSize(QSize(691, 112));
        splitter->addWidget(stationSearchBtn);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 680, 691, 60));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        myticketBtn = new QPushButton(layoutWidget);
        myticketBtn->setObjectName(QStringLiteral("myticketBtn"));
        myticketBtn->setMinimumSize(QSize(222, 58));
        myticketBtn->setMaximumSize(QSize(222, 58));

        horizontalLayout->addWidget(myticketBtn);

        myinformBtn = new QPushButton(layoutWidget);
        myinformBtn->setObjectName(QStringLiteral("myinformBtn"));
        myinformBtn->setMinimumSize(QSize(221, 58));
        myinformBtn->setMaximumSize(QSize(221, 58));

        horizontalLayout->addWidget(myinformBtn);

        logoutBtn = new QPushButton(layoutWidget);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));
        logoutBtn->setMinimumSize(QSize(222, 58));
        logoutBtn->setMaximumSize(QSize(222, 58));

        horizontalLayout->addWidget(logoutBtn);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(340, 30, 411, 211));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(layoutWidget1);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setTextFormat(Qt::AutoText);
        nameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 0, 1, 1, 1);

        welcomeLabel = new QLabel(layoutWidget1);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(welcomeLabel, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        loginBtn = new QPushButton(layoutWidget1);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy);
        loginBtn->setMinimumSize(QSize(409, 58));

        verticalLayout_2->addWidget(loginBtn);

        regBtn = new QPushButton(layoutWidget1);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setMinimumSize(QSize(409, 58));

        verticalLayout_2->addWidget(regBtn);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        splitter->raise();
        layoutWidget->raise();
        label->raise();
        label_3->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "12308", Q_NULLPTR));
        stationToStationSearchBtn->setText(QApplication::translate("MainWindow", "\347\253\231\347\253\231\346\237\245\350\257\242\357\274\210\345\217\257\350\264\255\347\245\250\357\274\211", Q_NULLPTR));
        trainSearchBtn->setText(QApplication::translate("MainWindow", "\350\275\246\346\254\241\346\237\245\350\257\242\357\274\210\344\270\215\345\217\257\350\264\255\347\245\250\357\274\211", Q_NULLPTR));
        stationSearchBtn->setText(QApplication::translate("MainWindow", "\350\275\246\347\253\231\346\237\245\350\257\242\357\274\210\344\270\215\345\217\257\350\264\255\347\245\250)", Q_NULLPTR));
        myticketBtn->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\350\275\246\347\245\250", Q_NULLPTR));
        myinformBtn->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        logoutBtn->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("MainWindow", "name", Q_NULLPTR));
        welcomeLabel->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\357\274\201", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        regBtn->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
