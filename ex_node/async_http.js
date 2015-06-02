var async = require('async')
var bl = require('bl')
var http = require('http')
var count = 0
var results = []

function httpGet(i){
    var v = process.argv[i+2]
    http.get(v, function(response){
        response.pipe(bl(function (err, data){
            if (err)
                return console.error(err)
            count++
            results[i]=data.toString()
            if (count === 3){
                for (var j = 0; j < 3; j ++) {
                    console.log(results[j])
                }
            }
        }))
    })
}
for (var i = 0, l = 3; i < l; i ++) {
    httpGet(i)
}
