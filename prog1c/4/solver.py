a,b,c,A,B,C = map(float,input().split())

def det(a,b,c,d): return a*d-b*c
            
if (a*a+b*b)*(A*A+B*B)==0:
    print("ERROR")
elif a*B==b*A:
    print("SAME" if a*C==c*A and b*C == c*B else "PARALLEL")
else:
    zn = det (a, b, A, B)
    x = - det (c, b, C, B) / zn
    y = - det (a, c, A, C) / zn
    print(x, y)     