const db = require('../database');

const grade = {
    getGradeByStudent(username, callback){
        return db.query('SELECT course_name,  gredit_points, grade, DATE_FORMAT(grade_date,"%d.%m.%Y") AS grade_date FROM course INNER JOIN grade ON course.idcourse=grade.idcourse WHERE username=?',[username],callback);
    }
}

module.exports=grade;
