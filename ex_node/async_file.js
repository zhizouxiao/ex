var fs = require('fs');
fs.readFile(process.argv[2], 'utf-8', function(err, data){
    var newLines = data.split('\n');
    console.log(newLines.length - 1);
})

