const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select * from account where account_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (user_id,account_balance,account_number) values(?,?,?)',
      [account.user_id, account.account_balance, account.account_number],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where account_id=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set user_id=?,account_balance=?, account_number=? where account_id=?',
      [account.user_id, account.account_balance, account.account_number, id],
      callback
    );
  }
};
module.exports = account;