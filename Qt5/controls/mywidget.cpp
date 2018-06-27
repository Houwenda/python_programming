#include "mywidget.h"
#include <QApplication>

#include <QLabel> //文字或图片
#include <QLineEdit>
#include <QPushButton>
#include <QCompleter>

#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>//多行，富文本
#include <QTextBrowser>//只读的Qtextedit
#include <QGroupBox>//分类
#include <QSlider> //模拟方式显示数值
#include <QSpinBox>//数字
#include <QDateEdit>//日期输入
#include <QTimeEdit>//时间输入
#include <QDateTimeEdit>
#include <QTabWidget>//不算控件

#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* lay = new QVBoxLayout(this);
    QLabel* label;
    QComboBox* combo;
    QPushButton* button;
    QRadioButton* radio;

    lay->addWidget(label = new QLabel("<h1><font color = red>label</font></h1>"));
    lay->addWidget(button = new QPushButton("Button"));
    button->setStyleSheet("QPushButton {font:bold 16px;color:red}");

    lay->addWidget(radio = new QRadioButton("Radio"));
    radio->setStyleSheet("QRadioButton {font:bold 16px;color:red}");

    lay->addWidget(new QCheckBox);

    lay->addWidget(combo = new QComboBox());
    combo->addItem("select item1");
    combo->addItem("select item2");
    combo->setEditable(true);
    //combo->setCompleter(new QCompleter(QStringList()<<"aaa"<<"bbb"));
    combo->setCompleter(new QCompleter(combo->model()));

    lay->addWidget(new QTextEdit);
    lay->addWidget(new QGroupBox);
    lay->addWidget(new QSlider);
    lay->addWidget(new QSpinBox);
    lay->addWidget(new QDateTimeEdit);


}

int main(int argc, char **argv)
{
    QApplication app(argc,argv);


    MyWidget w;
    w.show();

    return app.exec();
}
