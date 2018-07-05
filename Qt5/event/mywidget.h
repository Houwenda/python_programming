#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

    bool event(QEvent *);//处理widget的event

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
//    void mouseDoubleClickEvent(QMouseEvent *);//不要用



    void keyPressEvent(QKeyEvent *);//键盘按下
    void keyReleaseEvent(QKeyEvent *);//键盘松开

signals:

public slots:
};

#endif // MYWIDGET_H
