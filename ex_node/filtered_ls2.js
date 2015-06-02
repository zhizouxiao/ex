var mfiltered = require('./mfiltered.js')

mfiltered(process.argv[2], process.argv[3], function(err, list){
    if (err)
        console.log("error!")
    list.forEach(function (t){
        console.log(t);
    })
})

