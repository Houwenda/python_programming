#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpainter.h>
#include <QPaintEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_destroyed();

    void on_pushButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *event)
    {

        Q_UNUSED(event);

        QPainter painter(this);

        painter.setRenderHint(QPainter::Antialiasing, true);

        painter.setPen(QColor(0,160,230));

        painter.drawLine(QPointF(0,height()), QPointF(width()/2, height()/2));

    }


};

#endif // MAINWINDOW_H
