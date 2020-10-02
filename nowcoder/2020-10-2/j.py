f = [0]*505
f[1] = f[2] = 1
for i in range(3,500):
    f[i] = f[i-1] + f[i-2]
while True:
    n = int(input())
    if n==-1: break
    print("Hour: " + str(n) + ": " + str(f[n]) + " cow(s) affected")
