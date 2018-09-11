/********************************************************************************
** Form generated from reading UI file 'dialogdraw.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDRAW_H
#define UI_DIALOGDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_DialogDraw
{
public:
    QCustomPlot *widget;
    QCheckBox *checkBox;

    void setupUi(QDialog *DialogDraw)
    {
        if (DialogDraw->objectName().isEmpty())
            DialogDraw->setObjectName(QStringLiteral("DialogDraw"));
        DialogDraw->resize(1260, 1005);
        widget = new QCustomPlot(DialogDraw);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 1091, 961));
        checkBox = new QCheckBox(DialogDraw);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(1150, 460, 101, 81));

        retranslateUi(DialogDraw);

        QMetaObject::connectSlotsByName(DialogDraw);
    } // setupUi

    void retranslateUi(QDialog *DialogDraw)
    {
        DialogDraw->setWindowTitle(QApplication::translate("DialogDraw", "Dialog", nullptr));
        checkBox->setText(QApplication::translate("DialogDraw", "\347\275\221\346\240\274\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDraw: public Ui_DialogDraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDRAW_H
