#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    QWidget w;
    QLineEdit passwd;
    QPushButton enter;

    passwd.setPlaceholderText("请输入密码...");
    passwd.setGeometry(100,100,100,40);
    enter.setGeometry(100,200,100,40);

    passwd.setParent(&w);
    passwd.setMaxLength(10);
    enter.setFixedWidth(100);
    enter.setParent(&w);
    enter.setText("确定");

    enter.show();
    passwd.show();

    QString password = passwd.text();

    w.setFixedWidth(300);
    w.setFixedHeight(350);
    w.setWindowTitle("解密器");
    w.show();

    QObject::connect(&enter,SIGNAL(clicked(bool)),&w,SLOT(close()));
    //qDebug << passwd.text();

    return app.exec();

}
