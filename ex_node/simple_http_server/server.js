var http = require("http")
var fs = require("fs")

http.createServer(function (req, res) {
    if (req.url == '/') {
        fs.readFile('./titles.json', function (err, data) {
            if (err) {
                console.error('read file error! '+err)
                req.end("Server Error!")
            }
            else {
                var titles = JSON.parse(data)
                fs.readFile('./template.html', function (err, data) {
                    if (err) {
                        console.error('read file error! '+err)
                        req.end("Server Error!")
                    }
                    else {
                        var tmp = data.toString()
                        var html = tmp.replace('%', titles.join('</li><li>'))
                        res.writeHead(200, {'Content-Type': 'text/html'})
                        res.end(html)
                    }
                })
            }
        })
        
    }
}).listen(8000, '127.0.0.1')
