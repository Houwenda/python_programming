#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
/*layout自动创建父子关系，文本框、按钮可以不setParent*/
#include <QVBoxLayout>//竖直排列
#include <QHBoxLayout>//水平排列
#include <QGridLayout>//表格
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget w;
/*
    QPushButton button;
    button.setText("button");
    button.setParent(&w);
    button.show();

    QLineEdit edit;
    edit.setParent(&w);
    edit.setPlaceholderText("Input");
    edit.text();
*/
/*
    QHBoxLayout layout;//水平布局
    layout.addStretch(1);//距左边框的比重为1
    layout.addWidget(&button);//将按钮添加到布局
    layout.addSpacing(50);//中间隔开50像素
    layout.addWidget(&edit);//将文本框添加到布局
    layout.addStretch(1);//距右边框的比重为1
*/
/*
    QGridLayout layout;
    layout.addWidget(&button, 1, 1);
    layout.addWidget(&edit, 1, 2);
    layout.addWidget(new QPushButton("1,0"),2,1);
    layout.addWidget(new QPushButton("1,1"),2,2);

    layout.setColumnStretch(3, 1);
    layout.setRowStretch(3, 1);
    layout.setColumnStretch(0,1);
    layout.setRowStretch(0,1);
    layout.setColumnStretch(0,2);
    layout.setRowStretch(0,2);
    layout.setColumnStretch(3,2);
    layout.setRowStretch(3,2);
*/

    QGridLayout layout;
    QLineEdit *passwd;
    layout.setColumnStretch(3, 1);
    layout.setRowStretch(4, 1);
    layout.setColumnStretch(0,1);
    layout.setRowStretch(0,1);

    layout.addWidget(new QLabel("username:"), 1, 1);
    layout.addWidget(new QLineEdit(), 1, 2);
    layout.addWidget(new QLabel("password:"), 2, 1);
    layout.addWidget(passwd = new QLineEdit(), 2, 2);

    QHBoxLayout* hBox;
    layout.addLayout(hBox = new QHBoxLayout, 3, 2);
    hBox->addStretch(1);
    hBox->addWidget(new QPushButton("Login"));

//    layout.addWidget(new QPushButton("Login"), 3, 2);

    passwd->setEchoMode(QLineEdit::Password);

    w.setLayout(&layout);//将布局添加到窗口
    w.show();
/*
    QObject::connect(&button,SIGNAL(clicked(bool)),&w,SLOT(close()));
*/
    return app.exec();
}

