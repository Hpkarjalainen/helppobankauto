var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');  //tämä muuttuja webtokeniin liittyen (const-muuttujaa ei pysty muuttamaan)

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var cardRouter = require('./routes/card');    //lisätty
var loginRouter = require('./routes/login');  //lisätty
var accountRouter = require('./routes/account');
var checkBalanceRouter = require('./routes/checkbalance');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

//suojaamaton endpoint
app.use('/login', loginRouter); 


//kaikki endpointit tämän alla ovat suojattuja
//app.use(authenticateToken);  
app.use('/card', cardRouter);  //lisättiin
app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/account', accountRouter);
app.use('/checkbalance', checkBalanceRouter);



function authenticateToken(req, res, next) {   //funktio lisätty, kohta 5 matskuista
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }

module.exports = app;
