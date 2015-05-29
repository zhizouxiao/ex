t = {}
t1 = {}
t1["abc"] = {1}
t1.__index = function (table, key)
    return t1[key]
end
setmetatable(t, t1)
setmetatable(t, {"other"})

for i,v in pairs(t) do
   -- body
   print(v)
end
for i,v in pairs(getmetatable(t)) do
   -- body
   print(i, v)
end

function assert_test(...)
    -- body
    return {"assert_test"}
end

print("---------")
print(assert(assert_test()))
