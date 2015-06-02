var total = 0;

for (var i = 2, l = process.argv.length; i < l; i ++) {
    var v = process.argv[i];
    total += Number(v);
}
console.log(total);
