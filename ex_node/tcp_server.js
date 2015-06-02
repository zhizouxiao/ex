var net = require('net')
var strftime = require('strftime')

var server = net.createServer(function (socket) {
    var date = new Date()
    var data = strftime("%F %R", date)
    console.log(data)
    socket.end(data)
})
server.listen(process.argv[2])
