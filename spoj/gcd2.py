import math

t=int(input())

while t>0:
    a,b=map(int,input().split())
    if a==0 or b==0:
        print(a|b)
    else:
        print(math.gcd(a,b))
    t=t-1