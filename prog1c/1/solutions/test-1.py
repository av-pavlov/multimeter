year = int(input())
print("ERROR" if year not in range(1, 2101) else ("NORMAL" if year%4 or (year%400 and year%100==0) else "LEAP"))