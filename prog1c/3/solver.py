# -*- coding: cp1251 -*-
n = int(input())
age = "ЛЕТ"
if n//10!=1:
    if n%10 ==1:
        age="ГОД"
    elif n%10 in range(2,5):
        age="ГОДА"     
print("ERROR" if n not in range(1, 101) else ("ВАМ %d %s" % (n, age) ))