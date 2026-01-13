#include "mygrades.h"
#include "ui_mygrades.h"

#include <QStandardItemModel>

MyGrades::MyGrades(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyGrades)
{
    ui->setupUi(this);
}

MyGrades::~MyGrades()
{
    delete ui;
}

void MyGrades::setMyGrades(const QByteArray &newMyGrades)
{
    myGrades = newMyGrades;
    qDebug()<<"MyGrades Form";
//    qDebug()<<myGrades;
    QJsonDocument json_doc = QJsonDocument::fromJson(myGrades);
    QJsonArray json_array=json_doc.array();

    QVector<Grades> listGrades;
    for (const QJsonValue &value : json_array) {
        if (value.isObject()) {
            Grades grade = Grades::mapJson(value.toObject());
            listGrades.append(grade);
        }
    }
    //qDebug()<<listGrades[0].course_name;
    auto *tableModel = new QStandardItemModel(listGrades.size(), 4, this);
    tableModel->setHorizontalHeaderLabels({ tr("kurssi"), tr("op-pisteet"), tr("arvosana"),tr("pvm") });
    for (int row = 0; row < listGrades.size(); ++row) {
        const Grades &grade = listGrades[row];
        tableModel->setItem(row, 0, new QStandardItem(grade.course_name));
        tableModel->setItem(row, 1, new QStandardItem(QString::number(grade.gredit_points)));
        tableModel->setItem(row, 2, new QStandardItem(QString::number(grade.grade)));
        tableModel->setItem(row, 3, new QStandardItem(grade.grade_date));
    }
    ui->tableGrades->setModel(tableModel);
    ui->tableGrades->verticalHeader()->setVisible(false);
    ui->tableGrades->resizeColumnsToContents();
}
