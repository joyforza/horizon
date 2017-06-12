n, m = list(map(int, input().split()))
ret = 1000000001
for i in range(0, m):
    u, v = [int (i) for i in input().split()]
    ret = min(ret, v - u + 1)

print (ret)
for i in range(0, n):
    print (i % ret, end=' ')
