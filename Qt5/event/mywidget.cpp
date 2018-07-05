#include "mywidget.h"
#include <QApplication>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QPoint>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    this->setMouseTracking(true);//不按下鼠标mouseMove也追踪鼠标位置
}

/* 消息处理流程：QApplication先得到消息->具体应处理的窗口::event()->event()根据消息类型来调用具体虚函数 */
/* 1) 可以重载具体的虚函数，来实现对消息的响应
   2) 可以重载event函数，用来处理或截取消息 */

bool MyWidget::event(QEvent *ev)//管理所有消息
{
//截断鼠标消息
//    if(ev->type() == QEvent::MouseButtonPress){
//       return true;
//    }

    return QWidget::event(ev);
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    QPoint pt = ev->pos();//调用QEvent，获取点击位置
    qDebug() << pt;//输出点击位置

    if(ev->button() == Qt::LeftButton){
    //鼠标左键
    }

    if(ev->modifiers() == Qt::ShiftModifier){//鼠标点击加shift
        qDebug() << "shift press";
    }

    if(ev->modifiers() == Qt::ControlModifier){
        //handle1 with ctrl
        return;
    }
    //handle2 without ctrl
}

void MyWidget::mouseReleaseEvent(QMouseEvent *)
{

}
void MyWidget::mouseMoveEvent(QMouseEvent *)
{
    //通常鼠标按下才追踪
    qDebug() << "mouse move";
}
void MyWidget::keyPressEvent(QKeyEvent *ev)
{
    ev->modifiers();
    int key = ev->key();//ascii码
    qDebug() << key;
}
void MyWidget::keyReleaseEvent(QKeyEvent *)
{

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget w;

    w.show();

    return app.exec();
}
