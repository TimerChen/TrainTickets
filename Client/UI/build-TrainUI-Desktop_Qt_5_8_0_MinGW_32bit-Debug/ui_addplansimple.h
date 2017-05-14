/********************************************************************************
** Form generated from reading UI file 'addplansimple.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLANSIMPLE_H
#define UI_ADDPLANSIMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addplansimple
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_2;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *addPlanBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *addplansimple)
    {
        if (addplansimple->objectName().isEmpty())
            addplansimple->setObjectName(QStringLiteral("addplansimple"));
        addplansimple->resize(522, 534);
        verticalLayout_2 = new QVBoxLayout(addplansimple);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser_2 = new QTextBrowser(addplansimple);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        verticalLayout->addWidget(textBrowser_2);

        label = new QLabel(addplansimple);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(addplansimple);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        addPlanBtn = new QPushButton(addplansimple);
        addPlanBtn->setObjectName(QStringLiteral("addPlanBtn"));

        verticalLayout->addWidget(addPlanBtn);


        verticalLayout_2->addLayout(verticalLayout);

        exitBtn = new QPushButton(addplansimple);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        verticalLayout_2->addWidget(exitBtn);


        retranslateUi(addplansimple);
        QObject::connect(exitBtn, SIGNAL(clicked()), addplansimple, SLOT(close()));

        QMetaObject::connectSlotsByName(addplansimple);
    } // setupUi

    void retranslateUi(QDialog *addplansimple)
    {
        addplansimple->setWindowTitle(QApplication::translate("addplansimple", "\346\267\273\345\212\240\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("addplansimple", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\257\267\346\214\211\347\205\247\344\270\200\344\270\213\346\240\274\345\274\217\350\276\223\345\205\245\351\234\200\350\246\201\346\267\273\345\212\240\347\232\204\350\275\246\346\254\241\350\256\241\345\210\222\357\274\210\350\257\267\344\273\224\347\273\206\346\243\200\346\237\245\346\240\274\345\274\217\346\230\257\345\220\246\346\255\243\347\241\256\357\274\214\344\270\215\346\255\243\347\241\256\346\240\274\345\274\217\347\232\204\350\256\241\345\210\222\345\217\257\350\203\275\344\274\232\345\257\274\350\207\264\347\263\273\347\273\237\345\207\272\347\216"
                        "\260\351\227\256\351\242\230\357\274\211</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\275\246\346\254\241\345\217\267</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\253\231\345\220\215,\346\227\245\346\234\237,\345\210\260\350\276\276\346\227\266\351\227\264,\345\201\234\350\275\246\346\227\266\351\227\264,\351\207\214\347\250\213,\345\272\247\344\275\215\347\261\273\345\236\2131,\345\272\247\344\275\215\347\261\273\345\236\2132\342\200\246\342\200\246</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\240\267\344\276\213\345\246\202\344\270\213\350\257\267\344\273\224\347\273\206\346\237\245\351\230\205\357\274\232</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">D5911/D5914</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\253\231\345\220\215,\346\227\245\346\234\237,\345\210\260\350\276\276\346\227\266\351\227\264,\345\201\234\350\275\246\346\227\266\351\227\264,\351\207\214\347\250\213,\344\272\214\347\255\211\345\272\247,\344\270\200\347\255\211\345\272\247,\346\227\240\345\272\247</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\210\251\345"
                        "\267\235,2017-03-28,\350\265\267\347\202\271\347\253\231,14:38,0km,-,-,-</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\201\251\346\226\275,2017-03-28,15:10,15:17,61km,\357\277\24518,\357\277\24521.5,\357\277\24518</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\273\272\345\247\213,2017-03-28,15:39,15:41,96km,\357\277\24528,\357\277\24533.5,\357\277\24528</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\256\234\346\230\214\344\270\234,2017-03-28,17:08,17:13,275km,\357\277\24581,\357\277\24597,\357\277\24581</p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("addplansimple", "\350\257\267\345\234\250\344\270\213\346\241\206\344\270\255\350\276\223\345\205\245\346\226\260\347\232\204\350\277\220\350\241\214\350\256\241\345\210\222\357\274\232", Q_NULLPTR));
        addPlanBtn->setText(QApplication::translate("addplansimple", "\346\267\273\345\212\240\350\277\220\350\241\214\350\256\241\345\210\222\357\274\210\350\257\267\344\270\245\346\240\274\344\277\235\350\257\201\346\240\274\345\274\217\346\255\243\347\241\256\357\274\211", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("addplansimple", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addplansimple: public Ui_addplansimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLANSIMPLE_H
