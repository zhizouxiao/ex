var fs = require('fs')
buff = fs.readFileSync(process.argv[2])
newLines = buff.toString().split('\n').length - 1
console.log(newLines)
