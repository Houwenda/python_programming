#include <QApplication>
#include <QWidget>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget w;

    QLineEdit edit;
    edit.show();
    edit.setParent(&w);
    edit.setEchoMode(QLineEdit::Password);
    edit.text();
    edit.setPlaceholderText("Input password");

    w.show();

    return app.exec();
}
