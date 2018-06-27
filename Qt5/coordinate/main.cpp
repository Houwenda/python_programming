#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget w;
    w.setWindowTitle("坐标");

    QPushButton button;
    button.setText("button");
    button.setParent(&w);
    button.show();

    button.setGeometry(30,30,100,30);

    w.show();

    return app.exec();
}

