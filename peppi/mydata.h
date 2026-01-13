#ifndef MYDATA_H
#define MYDATA_H
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "environment.h"

namespace Ui {
class MyData;
}

class MyData : public QDialog
{
    Q_OBJECT

public:
    explicit MyData(QWidget *parent = nullptr);
    ~MyData();

    void setTestData(const QByteArray &newTestData);

    void setUsername(const QString &newUsername);

    void setToken(const QByteArray &newToken);

private:
    Ui::MyData *ui;
    QByteArray testData;
    QString username;
    QByteArray token;
    QNetworkReply *reply;
    QNetworkAccessManager *manager;
private slots:
    void btnSaveClicked();
    void btnSaveSlot();
};

#endif // MYDATA_H
