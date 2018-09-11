#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    qDebug()<<"data received"<<endl;
    // 获取响应信息
    QByteArray bytes = reply->readAll();
    qDebug()<<bytes<<endl;
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(bytes, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << QStringLiteral("解析Json失败");
        return;
    }

    // 解析Json
    if (doucment.isObject()) {
        QJsonObject obj = doucment.object();
        QJsonValue value;
        if (obj.contains("data")) {
            value = obj.take("data");
            if (value.isString()) {
                QString data = value.toString();
                qDebug() << data;
            }
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"clicked"<<endl;
    QString baseUrl = "https://6n9n93nlr5.execute-api.us-east-1.amazonaws.com/prod/dict";
    QUrl url(baseUrl);

    QJsonObject json;
    json.insert("time",1);
    json.insert("shardidx",0);
    json.insert("shards",1);
    json.insert("cluse","");
    json.insert("ciphertext","asdfghjk");

    QJsonDocument document;
    document.setObject(json);
    QByteArray dataArray = document.toJson(QJsonDocument::Compact);

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setRawHeader("Origin","https://quipquip.com");
    request.setRawHeader("Referer","https://quipquip.com");
    request.setUrl(url);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply *)));

    manager->post(request,dataArray);
    qDebug()<<"data posted"<<endl;
}


