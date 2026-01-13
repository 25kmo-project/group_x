#ifndef GRADES_H
#define GRADES_H
#include <qjsonobject.h>

class Grades
{
public:
    QString course_name;
    int gredit_points;
    int grade;
    QString grade_date;
    static Grades mapJson(const QJsonObject &json);

};

#endif // GRADES_H
