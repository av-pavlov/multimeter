# -*- coding: cp1251 -*-
n = int(input())
age = "���"
if n//10!=1:
    if n%10 ==1:
        age="���"
    elif n%10 in range(2,5):
        age="����"     
print("ERROR" if n not in range(1, 101) else ("��� %d %s" % (n, age) ))