const express = require('express');
const router = express.Router();
const student = require('../models/student_model');

router.get('/',function(request, response){
    student.getAll(function(err,result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    })
});

router.get('/:username',function(request, response){
    student.getOne(request.params.username, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result[0]);
        }

    })
});

router.post('/',function(request,response){
    console.log(request.body);
    student.add(request.body, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    })
});

router.put('/:username',function(request,response){
    student.update(request.body, request.params.username, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result.affectedRows);
        }
    })
});

router.delete('/:username',function(request,response){
    student.delete(request.params.username, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result);
        }
    })
});

module.exports=router;