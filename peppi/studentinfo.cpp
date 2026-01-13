#include "studentinfo.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
    manager=new QNetworkAccessManager(this);
    connect(ui->btnMyData, &QPushButton::clicked, this, &StudentInfo::btnMyDataClicked);
    connect(ui->btnMyGrades, &QPushButton::clicked, this, &StudentInfo::btnMyGradesClicked);
}

StudentInfo::~StudentInfo()
{
    delete ui;
}

void StudentInfo::setUsername(const QString &newUsername)
{
    username = newUsername;
    ui->labelUsername->setText(username);
}

void StudentInfo::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<token;
}

void StudentInfo::btnMyDataClicked()
{
    QString url=Environment::base_url()+"student/"+username;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    reply=manager->get(request);
    connect(reply, &QNetworkReply::finished, this, &StudentInfo::MyDataSlot);
}

void StudentInfo::MyDataSlot()
{
    QByteArray response=reply->readAll();
    //qDebug()<<response;
    MyData *objMydata=new MyData(this);
    objMydata->setTestData(response);
    objMydata->setUsername(username);
    objMydata->setToken(token);
    objMydata->show();
    reply->deleteLater();
}

void StudentInfo::btnMyGradesClicked()
{
    QString url=Environment::base_url()+"grade/"+username;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    reply=manager->get(request);
    connect(reply, &QNetworkReply::finished, this, &StudentInfo::MyGradesSlot);
}

void StudentInfo::MyGradesSlot()
{
    QByteArray response=reply->readAll();
    // qDebug()<<"MyGradeSlot";
    // qDebug()<<response;
    MyGrades *objMyGrades=new MyGrades(this);
    objMyGrades->setMyGrades(response);
    objMyGrades->show();

    reply->deleteLater();
}
