var currency = require("./lib/convertor.js")
var Currency = require("./lib/currency.js")

console.log('50 Canadian dollars equals this amount of US dollars:');
console.log(currency.canadianToUS(50));
console.log('30 US dollars equals this amount of Canadian dollars:');
console.log(currency.USToCanadian(30));


var cur = new Currency(1.1)
console.log(Currency)
console.log('50 Canadian dollars equals this amount of US dollars:');
console.log(cur.canadianToUS(50));
console.log('30 US dollars equals this amount of Canadian dollars:');
console.log(cur.USToCanadian(30));
