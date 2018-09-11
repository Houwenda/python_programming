/********************************************************************************
** Form generated from reading UI file 'dialogaddfuntion.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDFUNTION_H
#define UI_DIALOGADDFUNTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogAddFuntion
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_2;

    void setupUi(QDialog *DialogAddFuntion)
    {
        if (DialogAddFuntion->objectName().isEmpty())
            DialogAddFuntion->setObjectName(QStringLiteral("DialogAddFuntion"));
        DialogAddFuntion->resize(974, 304);
        buttonBox = new QDialogButtonBox(DialogAddFuntion);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(580, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(DialogAddFuntion);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 120, 771, 51));
        radioButton = new QRadioButton(DialogAddFuntion);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(360, 20, 111, 41));
        radioButton_2 = new QRadioButton(DialogAddFuntion);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(520, 20, 111, 41));
        label = new QLabel(DialogAddFuntion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 10, 91, 31));
        label_2 = new QLabel(DialogAddFuntion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(550, 40, 91, 31));
        label_3 = new QLabel(DialogAddFuntion);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 120, 101, 51));
        comboBox = new QComboBox(DialogAddFuntion);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 240, 101, 41));
        label_4 = new QLabel(DialogAddFuntion);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 100, 81, 41));
        label_5 = new QLabel(DialogAddFuntion);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 160, 91, 31));
        lineEdit_2 = new QLineEdit(DialogAddFuntion);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 90, 771, 51));
        lineEdit_3 = new QLineEdit(DialogAddFuntion);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 150, 771, 51));
        comboBox_2 = new QComboBox(DialogAddFuntion);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(230, 240, 101, 41));

        retranslateUi(DialogAddFuntion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddFuntion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddFuntion, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddFuntion);
    } // setupUi

    void retranslateUi(QDialog *DialogAddFuntion)
    {
        DialogAddFuntion->setWindowTitle(QApplication::translate("DialogAddFuntion", "Dialog", nullptr));
        radioButton->setText(QApplication::translate("DialogAddFuntion", "Y = f(X)", nullptr));
        radioButton_2->setText(QString());
        label->setText(QApplication::translate("DialogAddFuntion", "X = f( t )", nullptr));
        label_2->setText(QApplication::translate("DialogAddFuntion", "Y = g( t )", nullptr));
        label_3->setText(QApplication::translate("DialogAddFuntion", "f( X ) =  ", nullptr));
        label_4->setText(QApplication::translate("DialogAddFuntion", "X( t ) = ", nullptr));
        label_5->setText(QApplication::translate("DialogAddFuntion", "Y( t ) = ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAddFuntion: public Ui_DialogAddFuntion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDFUNTION_H
