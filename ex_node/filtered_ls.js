var fs = require('fs');
var path = require('path');
fs.readdir(process.argv[2], function (err, list){
    for (var i = 0, l = list.length; i < l; i ++) {
        var v = list[i];
        extname = path.extname(v);
        if (extname == "." + process.argv[3]){
            console.log(v)
        }
    }
})
