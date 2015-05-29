a={{}, {1}, {2}, {}}

--local l= 4
--for i=1,4 do
    --local v = a[i]
    --if #v == 0 then
        --table.remove(v, i)
    --end
--end

i = 1
while a[i] do
    local v = a[i]
    if #v == 0 then
        table.remove(a, i)
    else
        i = i + 1
    end
    print(i, v[1])
end
for i,v in pairs(a) do
    print(i)
    for k,v in pairs(v) do
       -- body
       print(k, v)
    end
end
