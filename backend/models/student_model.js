const db = require('../database');
const bcrypt = require('bcryptjs');

const student={
    getAll:function(callback){
        return db.query("SELECT * FROM student", callback);
    },
    getOne:function(username, callback){
        return db.query("SELECT * FROM student WHERE username=?",[username],callback);
    },
    add:function(student,callback){
        bcrypt.hash(student.password,10,function(err, hashedPassword){
            return db.query("INSERT INTO student VALUES(?,?,?,?,?,?)",[student.username, student.fname, student.lname, student.streetaddress, student.email, hashedPassword],callback)
        });
    },
    update:function(student,username,callback){
        bcrypt.hash(student.password,10,function(err, hashedPassword){
            return db.query("UPDATE student SET fname=?,lname=?,streetaddress=?,email=?,password=? WHERE username=?",[student.fname, student.lname, student.streetaddress, student.email, hashedPassword, username],callback)
        });
    },
    delete:function(username, callback){
        return db.query("DELETE FROM student WHERE username=?",[username],callback);
    }
}

module.exports=student;