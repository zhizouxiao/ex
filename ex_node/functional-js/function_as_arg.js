function repeat(oper, num) {
    if (num <= 0) return
    oper()
    repeat(oper, --num)
}

module.exports = repeat
