dic = dict()
access = []
def pre(x):
    i = 2
    while i <= x:
        if x%i==0:
            access.append(i)
            dic[i] = 0
        while x%i==0:
            x /= i
            dic[i] += k
        i += 1
    if x > 1:
        dic[x] += 1
n,k = map(int,input().split())
pre(n)
res = 1
for i in access:
    t = 0
    tmp = 1
    for j in range(dic[i]+1):
        t += tmp
        tmp *= i
    res *= t
print(res)
