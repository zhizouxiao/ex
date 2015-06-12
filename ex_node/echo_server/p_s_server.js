var events = require("events")
var net = require("net")
var channel = new events.EventEmitter();
channel.clients = {};
channel.subscriptions = {};

channel.on('join', function(id, client) {
    console.log("1join======")
    this.clients[id] = client;
    this.subscriptions[id] = function(senderId) {
        if (id != senderId) {
            console.log("123========" + id)
            this.clients[id].write(id+" joined!");
        }
    }
    this.on('broadcast', this.subscriptions[id])
})  
var server = net.createServer(function (client) {
    var id = client.remoteAddress + ':' + client.remotePort
    channel.emit('join', id, client);
    client.on('data', function(data) {
    data = data.toString();
    console.log("data======" + data)
  });
    channel.emit('broadcast', id);
});
server.listen(8888);
