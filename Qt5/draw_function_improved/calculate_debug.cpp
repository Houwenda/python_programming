#include "function1.h"
#include "function2.h"
#include <QDebug>

void debug(void){
    //实体化
    function2 test;
    //设定
    test.get_expression(QString("sin(t)"),QString("2sin(t)"),QString("red"),QString("type1"));
    //计算
    qDebug()<<test.calculate_function(1,-0.5);
    qDebug()<<test.calculate_function(2,-0.5);
}
