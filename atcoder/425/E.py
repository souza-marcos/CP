import sys
input = sys.stdin.readline
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))


queries = []
maxv = 0

init = inlt()
t, m = init[0], init[1]

for i in range(t):
    
    n = inp()
    li = inlt()
    sum = 0
    for i in li: 
        sum += i
    maxv = max(maxv, sum)
    
    queries.append((sum, li))    

fact = [1 for _ in range(maxv + 1)]

for i in range(2, maxv + 1):
    fact[i] = i * fact[i-1]   

for sum, li in queries:
    res = fact[sum]
    for el in li:
        res //= fact[el]
    res %= m
    print(res)

