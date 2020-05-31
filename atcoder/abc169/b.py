n = int(input())
a = list(map(int,input().split()))
ans = 1
mark = False
if 0 in a:
    print(0)
    mark = True
if mark==False:
    for i in range(n):
        ans *= a[i]
        if ans > 1000000000000000000:
            mark = True
            print(-1)
            break
if not mark: print(ans)
