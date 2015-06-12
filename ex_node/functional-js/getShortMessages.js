function getShortMesssages(messages) {
    var filtered = messages.filter(function (msg) {
        return msg.message.length < 50
    })
    return filtered.map(function (msg) {
        return msg.message
    })
}
module.exports = getShortMesssages
