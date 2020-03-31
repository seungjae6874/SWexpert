import numpy as np
T = int(input('Input T: '))
for i in range(T):
    n = int(input('Input n: '))
    k = int(input('Input k: '))
    answer = 0
    mul = 0
    for j in range(n):
        for a in range(k):
            mul += (j+1)
        mul = mul%1000000007

    print(format('#%d'%(i+1)),mul)
