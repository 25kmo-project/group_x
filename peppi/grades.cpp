#include "grades.h"


Grades Grades::mapJson(const QJsonObject &json)
{
    Grades grade;
    grade.course_name=json["course_name"].toString();
    grade.gredit_points=json["gredit_points"].toInt();
    grade.grade=json["grade"].toInt();
    grade.grade_date=json["grade_date"].toString();
    return grade;

}
