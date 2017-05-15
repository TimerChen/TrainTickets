/********************************************************************************
** Form generated from reading UI file 'syslog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSLOG_H
#define UI_SYSLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sysLog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *viewLogTextBrowser;
    QPushButton *exitBtn;

    void setupUi(QDialog *sysLog)
    {
        if (sysLog->objectName().isEmpty())
            sysLog->setObjectName(QStringLiteral("sysLog"));
        sysLog->resize(651, 575);
        verticalLayout_2 = new QVBoxLayout(sysLog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        viewLogTextBrowser = new QTextBrowser(sysLog);
        viewLogTextBrowser->setObjectName(QStringLiteral("viewLogTextBrowser"));

        verticalLayout->addWidget(viewLogTextBrowser);

        exitBtn = new QPushButton(sysLog);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        verticalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(sysLog);
        QObject::connect(exitBtn, SIGNAL(clicked()), sysLog, SLOT(accept()));

        QMetaObject::connectSlotsByName(sysLog);
    } // setupUi

    void retranslateUi(QDialog *sysLog)
    {
        sysLog->setWindowTitle(QApplication::translate("sysLog", "Dialog", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("sysLog", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sysLog: public Ui_sysLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSLOG_H
