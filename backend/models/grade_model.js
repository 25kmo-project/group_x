const db = require('../database');

const grade = {
    getGradeByStudent(username, callback){
        return db.query("SELECT course_name,  gredit_points, grade FROM course INNER JOIN grade ON course.idcourse=grade.idcourse WHERE username=?",[username],callback);
    }
}

module.exports=grade;
