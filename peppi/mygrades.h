#ifndef MYGRADES_H
#define MYGRADES_H

#include <QDialog>
#include "grades.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class MyGrades;
}

class MyGrades : public QDialog
{
    Q_OBJECT

public:
    explicit MyGrades(QWidget *parent = nullptr);
    ~MyGrades();

    void setMyGrades(const QByteArray &newMyGrades);

private:
    Ui::MyGrades *ui;
    QByteArray myGrades;
};

#endif // MYGRADES_H
