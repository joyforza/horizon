n = int(input())
d = input().split()
flag = False
for i in range(0, n):
    if i < n - 1:
        if int(d[i]) > 0 and int(d[i + 1]) > 0:
            flag = True
        if int(d[i]) > 1:
            flag = True
    else:
        if int(d[i]) > 1:
            flag = True

if flag:
    print ("YES")
else:
    print ("NO")
    
            
    
