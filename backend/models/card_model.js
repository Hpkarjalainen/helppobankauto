const db = require('../database');
const bcrypt = require('bcryptjs');  //kryptaus

const saltRounds = 10;                //kryptaus

const card = {
  getById: function (id, callback) {
    return db.query('select * from card where card_id=?', [id], callback);
  },
  getAll: function (callback) {
    return db.query('select * from card', callback);
  },
  add: function (add_data, callback) {
    bcrypt.hash(add_data.pin, saltRounds, function (err, hashedPassword) {        //tähän kryptifunktio
      return db.query(
        'insert into card (user_id,cardnumber,pin,credit) values(?,?,?,?)', //ok, card_id on AI. Credit lisätty
        [add_data.user_id, add_data.cardnumber, hashedPassword, add_data.credit],  //kryptaus: ennen kuin salasana viedään tietokantaan ,se kryptataan
        callback);
    });
  },
  delete: function (id, callback) {
    return db.query('delete from card where card_id=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    bcrypt.hash(update_data.pin, saltRounds, function (err, hashedPassword) {
      return db.query(
        'update card set user_id=?,cardnumber=?, pin=?, credit=? where card_id=?',
        [update_data.user_id, update_data.cardnumber, hashedPassword, update_data.credit, id],
        callback);
    });
  },
  checkPassword: function(card_id,callback){  //MISSÄ KÄYTETÄÄN?, card_id muokattu
    return db.query('SELECT pin FROM card WHERE card_id=?',[card_id],callback);  //muokattu pin
},
};
module.exports = card;