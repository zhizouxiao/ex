function some_function()
    local m = 1
    for i =1,100000 do
        m = m + i
    end
end
function another_function()
    local m = 1
    for i =1,1000000 do
        m = m + i
    end
end
ProFi = require 'ProFi'
ProFi:start()
some_function()
another_function()
--coroutine.resume( some_coroutine )
ProFi:stop()
ProFi:writeReport( 'MyProfilingReport.txt' )
