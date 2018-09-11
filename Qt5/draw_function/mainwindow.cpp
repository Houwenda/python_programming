#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemView>
#include "function1.h";
#include "function2.h";
extern function1 expression1[5];
extern function2 expression2[5];
extern int function1_count;
extern int function2_count;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Add");
    ui->pushButton_2->setText("Draw");
    ui->pushButton_3->setText("Delete");
    //函数列表
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(0);
//    ui->tableWidget->horizontalHeader()->setClickable(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnWidth(0,400);
    ui->tableWidget->setColumnWidth(1,50);
    ui->tableWidget->horizontalHeader()->setFixedHeight(50);
    ui->tableWidget->setStyleSheet("selection-background-color:green;");
    ui->tableWidget->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

MainWindow::~MainWindow()
{
    delete ui;
}


//按下Add，创建窗口对象
void MainWindow::on_pushButton_clicked()
{
    dialog = new DialogAddFuntion(this);
    dialog->setModal(true);  //模态
    dialog->setWindowTitle("添加函数");
    dialog->show();
}
//按下draw
void MainWindow::on_pushButton_2_clicked()
{
    draw = new DialogDraw(this);
    draw->setModal(true);
    draw->setWindowTitle("绘图");
//    draw->refresh_graph();//产生图形
    draw->show();
}
//addfunction1完成后
void MainWindow::refresh_table1(void){
    int row_count = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row_count);//插入新行
    ui->tableWidget->setItem(row_count,0,new QTableWidgetItem("Y= "+ expression1[function1_count].read_expression()));
    ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(expression1[function1_count].read_line_color()));
    ui->tableWidget->setItem(row_count,2,new QTableWidgetItem(expression1[function1_count].read_line_type()));
     //     QTableWidgetItem *item = new QTableWidgetItem();
}

//addfunction2完成后
void MainWindow::refresh_table2(void){
    int row_count = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row_count);

    ui->tableWidget->setItem(row_count,0,new QTableWidgetItem("X= "+ expression2[function2_count].read_expression1() +"   Y= "+ expression2[function2_count].read_expression2()));
    ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(expression2[function2_count].read_line_color()));
    ui->tableWidget->setItem(row_count,2,new QTableWidgetItem(expression2[function2_count].read_line_type()));


}
//按下delete后删除选中行
void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    int rowIndex = ui->tableWidget->currentRow();
    if(rowIndex != -1) ui->tableWidget->removeRow(rowIndex);
}
