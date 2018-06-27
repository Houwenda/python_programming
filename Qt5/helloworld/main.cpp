#include <QApplication>
#include <QWidget>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget w;

    QPushButton button;
    button.setText("close");
    button.setParent(&w);
    button.show();

    QObject::connect(&button,  SIGNAL(clicked(bool)),&w, SLOT(close()));

    w.setWindowTitle("hello world!");
    w.show();

    return app.exec();
}
