var fs = require('fs');
var path = require('path');

module.exports = function(dir_name, ext, callback){
    fs.readdir(dir_name, function (err, list){
        if (err)
            return callback(err)
        list = list.filter(function (file){
            return path.extname(file) === '.' + ext
        })
        callback(null, list)
    })
}

