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

    ui->lineEdit->setFont(QFont("微软雅黑",14));
    ui->pushButton->setFont(QFont("微软雅黑",14,QFont::Bold));
    ui->pushButton->setStyleSheet("color:green");

    //ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setTextBackgroundColor(QColor(Qt::black));
    ui->textEdit->setFont(QFont("微软雅黑",10));
    ui->textEdit_2->setFont(QFont("微软雅黑",10));
    //ui->textEdit->append(QString("text"));
    //ui->textEdit->append(QString("test"));
    ui->textEdit->document()->setMaximumBlockCount(10);//最多显示10行
    ui->textEdit_2->document()->setMaximumBlockCount(200);
    //设定定时器，每秒触发一次事件，调整TextEdit光标位置
    QTimer *CurrentTime = new QTimer(this);
    CurrentTime->start(1000);
    connect(CurrentTime,&QTimer::timeout,[=](){
            //保持编辑器光标在最后一行
            QTextCursor cursor=ui->textEdit->textCursor();
            cursor.movePosition(QTextCursor::End);
            ui->textEdit->setTextCursor(cursor);
            //ui->textEdit->append(QString("......"));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//写入文件
bool MainWindow::writeQuipquip(QString str){
    ui->textEdit_2->append(str);
    QFile file("quipquip.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        qDebug()<<"Open failed"<< endl;
        return false;
    }
    QTextStream out(&file);
    str = str + "\r\n";
    out<<str;

    file.close();
    //qDebug()<<"file writing succeeded"<<endl;

    return true;
}
//槽函数 接收服务器消息
void MainWindow::replyFinished(QNetworkReply *reply)
{
    qDebug()<<"data received"<<endl;
    // 获取响应信息
    QByteArray bytes = reply->readAll();
    //qDebug()<<bytes<<endl;
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(bytes, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << QStringLiteral("解析Json失败");
        return;
    }
    QString source = QString(bytes);
    //qDebug()<<source<<endl;
    for(int i=0;i<source.length();i++){
        if(source[i]=='p'&&source[i+1]=='l'&&source[i+2]=='a'&&source[i+3]=='i'&&source[i+4]=='n'&&source[i+5]=='t'&&source[i+6]=='e'&&source[i+7]=='x'&&source[i+8]=='t'){
            i += 12;
            int j = i;
            while(source[j]!='"'){
                j++;
            }
            QString plaintext = source.mid(i,j-i);
            //qDebug()<<plaintext<<endl;
            if(writeQuipquip(plaintext)){
                //qDebug()<<"file writing succeeded"<<endl;
            }
            else{
                qDebug()<<"file writing failed"<<endl;
            }
            i = j;
            continue;
        }
    }
    qDebug()<<"plaintext writing succeeded"<<endl;
    ui->textEdit->append(QString("quipquip analysing finished. . . . . ."));
/*
    // 解析Json
    if (doucment.isObject()) {
        QJsonObject obj = doucment.object();
        QJsonValue value;
        if (obj.contains("data")) {
            value = obj.take("data");
            if (value.isString()||true) {
                QString data = value.toString();
                qDebug() << data;
            }
        }
    }
*/

}

//发送请求quipquip
bool MainWindow::requestQuipquip(void){

    qDebug()<<"clicked"<<endl;
    QString baseUrl = "https://6n9n93nlr5.execute-api.us-east-1.amazonaws.com/prod/dict";
    QUrl url(baseUrl);

    QString ciphertext = ui->lineEdit->text();

    ui->textEdit->append(QString("quipquip analysing starts. . . . . ."));

    QJsonObject json;
    json.insert("time",1);
    json.insert("shardidx",0);
    json.insert("shards",1);
    json.insert("clues","");
    json.insert("ciphertext",ciphertext);

    QJsonDocument document;
    document.setObject(json);
    QByteArray dataArray = document.toJson(QJsonDocument::Compact);

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setRawHeader("Origin","https://quipquip.com");
    request.setRawHeader("Referer","https://quipquip.com");
    request.setUrl(url);

    //QNetworkAccessManager manager();
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply *)));

    manager->post(request,dataArray);
    qDebug()<<"data posted"<<endl;

    return true;
}

//特征识别
void MainWindow::staticsAnalysis(void){

}

//按下按钮
void MainWindow::on_pushButton_clicked()
{
    if(requestQuipquip())   qDebug()<<"quipquip analysis"<<endl;

}
