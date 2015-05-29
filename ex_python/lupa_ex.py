# coding:utf8
from lupa import LuaRuntime

lua = LuaRuntime()
lua.require("t")

func = lua.eval('''function() return return_data() end''')
res = func()

for t, v in res.items():
    print t, v

