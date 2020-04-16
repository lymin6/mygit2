__author__ = 'Administrator'
#-*-coding:utf-8 -*-
#导包
import pymysql

data={
    'id':'1001',
    'name':'Jack',
    'age':20
}
#库
db=pymysql.connect(host='localhost',user='root',password='6828#',port=3306,db='spiders')
#获得操作游标
cursor=db.cursor()
#
table='students'
keys=','.join(data.keys())
values=','.join(['%s']*len(data))
sql='INSERT INTO {table}({keys}) VALUES({values})'.format(table=table,keys=keys,values=values)

print('key:',keys)
print('values:',values)
print('sql:',sql)

#
try:
    #提交
    if cursor.execute(sql,tuple(data.values())):
        db.commit()
        print('Success')
    #回滚
except Exception as e:
    print('Faild')
    db.rollback()

db.close()