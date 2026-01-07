const express = require('express');
const router = express.Router();
const student = require('../models/student_model');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');

router.post('/', function(request, response){
    if(request.body.username && request.body.password){
        const username=request.body.username;
        const password=request.body.password;
        student.check_password(username, function(err, result){
            if(err){
                response.send(err);
            }
            else {
                if(result.length > 0){
                    bcrypt.compare(password, result[0].password, function(err, compareResult){
                        const token=generateAccessToken(username);
                        response.setHeader('Content-Type', 'application/json'); 
                        response.json({
                            success: true,
                            message: "Login OK",
                            username: username,
                            token: token
                        });
                    })
                }
                else {
                    console.log("Tunnusta ei ole");
                    response.json({"message":"tunnus ja salasana eivät täsmää"});                 
                }
            }
        })
    }
    else {
        console.log("Tunnus tai salasana puuttuu");
        response.json({"message":"tunnus ja salasana eivät täsmää"});
    }
});

function generateAccessToken(username) {
  return jwt.sign({ username }, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;