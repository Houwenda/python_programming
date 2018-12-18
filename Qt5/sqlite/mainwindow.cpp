#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
    }

    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug()<<"open database succeeded"<<endl;

        QSqlQuery sql_query;
        QString create_sql = "create table english_words (id int primary key, word varchar(50))";
        sql_query.prepare(create_sql);
        if(!sql_query.exec())
        {
            qDebug() << "Error: Fail to create table." << sql_query.lastError();
        }
        else
        {
            qDebug() << "Table created!";
        }


        //QSqlQuery sql_query;
        QString select_sql = "select id,word from english_words";
        sql_query.prepare(select_sql);
        if(!sql_query.exec(select_sql)){
            qDebug()<<sql_query.lastError();
        }
        else{
            while(sql_query.next())
                {
                    int id = sql_query.value(0).toInt();
                    QString password = sql_query.value(1).toString();
                    qDebug()<<QString("id:%1    word:%2").arg(id).arg(password);
                }
        }
        database.close();

    }
/*写入表
        QString insert_sql = "insert into english_words values (?, ?)";
        // do something
        //启动事务
        database.transaction();
        sql_query.prepare(insert_sql);
        sql_query.addBindValue(0);
        sql_query.addBindValue("test");
        if(!sql_query.exec())
        {
            qDebug() << sql_query.lastError();
        }
        else
        {
            qDebug() << "inserted test";
        }
        database.commit();

    database.close();
    qDebug()<<"database closed"<<endl;
*/

/*写入表
    QString insert_sql = "insert into english_words values (?, ?)";
    QSqlQuery sql_query;
    database.transaction();
    int count = 0;
    QFile file("C:\\Users\\houwd\\Desktop\\english_words.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"open file succeeded"<<endl;
        while (!file.atEnd())
                {
                    QByteArray line = file.readLine();
                    QString str(line);
                    //qDebug() << str;
                    sql_query.prepare(insert_sql);
                    sql_query.addBindValue(count);
                    count++;
                    sql_query.addBindValue(str);
                    if(!sql_query.exec())
                    {
                        qDebug() << sql_query.lastError();
                    }
                    else
                    {
                        //qDebug() << "inserted test";
                    }
                }
        database.commit();
        database.close();
        qDebug()<<"database closed"<<endl;
                file.close();
    }
*/

/*读文件
    qDebug()<<"start reading file"<<endl;
    QFile file("C:\\Users\\houwd\\Desktop\\english_words.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"open file succeeded"<<endl;
        while (!file.atEnd())
                {
                    QByteArray line = file.readLine();
                    QString str(line);
                    qDebug() << str;
                }
    }
    file.close();
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
