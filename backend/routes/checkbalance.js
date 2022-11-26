const express = require('express');  //ei testattu
const router = express.Router();
const account = require('../models/account_model');

router.get('/:id?',function (request, response) {
    const id=request.params.id;
        account.checkbalance(id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]); 
            }
        })
    });

module.exports=router;