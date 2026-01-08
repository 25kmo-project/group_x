#ifndef MYDATA_H
#define MYDATA_H

#include <QDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

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

private:
    Ui::MyData *ui;
    QByteArray testData;
};

#endif // MYDATA_H
