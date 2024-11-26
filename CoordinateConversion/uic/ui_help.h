/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helpClass
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *helpClass)
    {
        if (helpClass->objectName().isEmpty())
            helpClass->setObjectName("helpClass");
        helpClass->resize(400, 300);
        verticalLayout = new QVBoxLayout(helpClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(helpClass);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);


        retranslateUi(helpClass);

        QMetaObject::connectSlotsByName(helpClass);
    } // setupUi

    void retranslateUi(QWidget *helpClass)
    {
        helpClass->setWindowTitle(QCoreApplication::translate("helpClass", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpClass: public Ui_helpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
