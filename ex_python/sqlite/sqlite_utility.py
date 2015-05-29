import sqlite3

def create_conn(db_name):
    return sqlite3.connect(db_name)

def create_table(cur, sql):
    cur.execute("drop table if exists;")
    cur.execute(sql)

def insert_data()
