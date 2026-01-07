var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var studentRouter = require('./routes/student');
var loginRouter = require('./routes/login');
const jwt = require('jsonwebtoken');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/login', loginRouter);

//suojatut reitit
app.use(authenticateToken);
app.use('/student', studentRouter);


function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization'];
    // Extract token by removing "Bearer " prefix from "Bearer "
    const token = authHeader && authHeader.split(' ')[1];

    if (token == null) return res.sendStatus(401);
    jwt.verify(token, process.env.MY_TOKEN, function(err, user) {
      if (err) {
        return res.sendStatus(403);
      }
      req.user = user;
      next();
    })
  }


module.exports = app;
