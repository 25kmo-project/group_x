#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &MainWindow::btnLoginSlot);
    manager=new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnLoginSlot()
{
    QString url=Environment::base_url()+"login";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject jObject;
    jObject.insert("username", ui->textUsername->text());
    jObject.insert("password",ui->textPassword->text());
    QJsonDocument jsonDoc(jObject);
    reply=manager->post(request, jsonDoc.toJson());
    connect(reply, &QNetworkReply::finished, this,&MainWindow::loginAction);

}

void MainWindow::loginAction()
{
    QByteArray responseData=reply->readAll();
    qDebug()<<responseData;
}
