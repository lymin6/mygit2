__author__ = 'Administrator'
#-*-coding:utf-8 -*-
#导包
import pymysql

data={
    'id':'1001',
    'name':'Jack',
    'age':22    #20->22
}
#库
db=pymysql.connect(host='localhost',user='root',password='6828#',port=3306,db='spiders')
#获得操作游标
cursor=db.cursor()
#
table='students'
keys=','.join(data.keys())
values=','.join(['%s']*len(data))
sql='INSERT INTO {table}({keys}) VALUES({values}) ON DUPLICATE KEY UPDATE'.format(table=table,keys=keys,values=values)
update=','.join(["{keys}=%s".format(keys=keys) for keys in data.keys()])
sql+=update  #拼接

print('key:',keys)
print('values:',values)
print('update:',update)
print('sql:',sql)

#noinspection PyBroadException
try:
    if cursor.execute(sql,tuple(data.values())*2):
        db.commit()
        print('Successful')#提交
except Exception as e:
    print('Faild')
    db.rollback()#回滚

db.close()
