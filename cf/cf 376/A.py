d = input()
n = len(d)
last = 'a'
ret = 0
for i in range(0, n):
    rr = abs(ord(d[i]) - ord(last))
    ret += min(rr, 26 - rr)
    last = d[i]

print (ret)
