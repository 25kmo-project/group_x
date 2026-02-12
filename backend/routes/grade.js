const express = require('express');
const router = express.Router();
const grade = require('../models/grade_model');

router.get('/:username', function (request, response) {
    if (request.user.username != request.params.username && request.user.role != 'admin') {
        return response.status(403).json("Sinulla ei ole oikeuksia tähän resursiin");
    }
    grade.getGradeByStudent(request.params.username, function (err, result) {
        if (err) {
            response.send(err);
        }
        else {
            response.json(result);
        }
    })
});

module.exports = router;