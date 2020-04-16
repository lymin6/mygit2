__author__ = 'Administrator'
#-*-coding:utf-8 -*-
#导包
import pymysql
#创建连接
db=pymysql.connect(host='localhost',user='root',password='6828#',port=3306)
#获得操作游标
cursor=db.cursor()

#查询版本号
cursor.execute('SELECT VERSION()')

data=cursor.fetchone()
print('DATABASE version:',data)

#创建数据库
if cursor.execute('CREATE DATABASE spiders DEFAULT CHARACTER SET utf8'):
  print('Successful')

#使用库
cursor.execute('use spiders;')

#建表
sql='CREATE TABLE IF NOT EXISTS students(id VARCHAR(255) NOT NULL,name VARCHAR(255) NOT NULL,age INT NOT NULL,PRIMARY KEY(id))'
if cursor.execute(sql):
    print('Successful')

#关闭链接
db.close()
