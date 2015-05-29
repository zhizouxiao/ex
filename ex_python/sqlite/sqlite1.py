import sqlite3
cx = sqlite3.connect("data.db")
cu = cx.cursor()

cu.execute("drop table if exists hero_config;")
cu.execute("create table hero_config (id integer primary key, pid interger, name varchar(10) UNIQUE)")


cx.commit()
cx.close()
