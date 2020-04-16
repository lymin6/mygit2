__author__ = 'Administrator'

#-*-coding:utf-8 -*-
#导包
import pymysql
#库
db=pymysql.connect(host='localhost',user='root',password='6828#',port=3306,db='spiders')
#获得操作游标
cursor=db.cursor()
#
table='students'
condition='age>=20'#删除条件


sql='DELETE FROM{table} WHERE {condition}'.format(table=table,condition=condition)
# noinspection PyBroadException
try:
        cursor.execute(sql)
        db.commit()
        print('Successful')
except Exception as e:
    print('Faild')
    db.rollback()

db.close()