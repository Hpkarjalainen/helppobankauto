const db = require('../database');
const bcrypt = require('bcryptjs');  //kryptaus

const saltRounds = 10;                //kryptaus

const card = {
  getById: function (id, callback) {
    return db.query('select * from card where card_id=?', [id], callback);  //HAETAAN CARD_ID AVULLA
  },
  getAll: function (callback) {
    return db.query('select * from card', callback);
  },
  add: function (add_data, callback) {
    bcrypt.hash(add_data.pin, saltRounds, function (err, hashedPassword) {        //tähän kryptifunktio
      return db.query(
        'insert into card (account_id,card_number,pin) values(?,?,?)', //card_id on AI.
        [add_data.account_id, add_data.card_number, hashedPassword],  //kryptaus: ennen kuin salasana viedään tietokantaan ,se kryptataan
        callback);
    });
  },
  delete: function (id, callback) {
    return db.query('delete from card where card_id=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    bcrypt.hash(update_data.pin, saltRounds, function (err, hashedPassword) {
      return db.query(
        'update card set account_id=?,card_number=?, pin=? where card_id=?',
        [update_data.account_id, update_data.card_number, hashedPassword, id],
        callback);
    });
  },
  checkPassword: function(card_id,callback){  //MISSÄ KÄYTETÄÄN?, card_id muokattu
    return db.query('SELECT pin FROM card WHERE card_id=?',[card_id],callback);  //muokattu pin
},
};
module.exports = card;