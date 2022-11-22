const express = require('express');  //tämä kopioitu suoraan sivulta 22.11
const router = express.Router();
const bcrypt = require('bcryptjs');
const card = require('../models/card_model');  //card_model.js required
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');


router.post('/', 
  function(request, response) {
    if(request.body.card_id && request.body.pin){   //muutettu .card_id ja .pin 
      const card_id = request.body.card_id;
      const pin = request.body.pin;
        card.checkPassword(card_id, function(dbError, dbResult) {    //löytyykö card-muuttujan yhteys?
          if(dbError){
            response.json(dbError.errno);   //lisätty .errno
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) { //pin joka lähetetään, verrataan siihen joka
                if(compareResult) {                                             //löytyy tietokannasta, jos antaa arvon tosi niin:
                  console.log("success");
                  const token = generateAccessToken({ username: card_id });
                  response.send(token);   //luennolla true
                }
                else {
                    console.log("wrong password");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("username or password missing");
      response.send(false);
    }
  }
);

function generateAccessToken(username) {  //pitääkö username muuttaa?
  dotenv.config();
  return jwt.sign(username, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;