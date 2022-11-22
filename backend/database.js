const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'hannu',
  password: 'netpass',
  database: 'helppobankauto'
});
module.exports = connection;