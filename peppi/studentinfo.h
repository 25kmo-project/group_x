#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "environment.h"
#include "mydata.h"
#include "mygrades.h"

namespace Ui {
class StudentInfo;
}

class StudentInfo : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = nullptr);
    ~StudentInfo();

    void setUsername(const QString &newUsername);

    void setToken(const QByteArray &newToken);

private:
    Ui::StudentInfo *ui;
    QString username;
    QByteArray token;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;

private slots:
    void btnMyDataClicked();
    void MyDataSlot();
    void btnMyGradesClicked();
    void MyGradesSlot();
};

#endif // STUDENTINFO_H
