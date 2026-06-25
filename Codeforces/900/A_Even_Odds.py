n, k = map(int, input().split())
ans=0
if n%2==0:
    ans=1
if(ans):
    if(k<=n//2):
        print(2*k-1)
    else:
        print(2* (k-n//2))
else:
    if(k<= (n//2) +1):
        print(2*k -1)
    else:
        print(2* (k- (n//2) - 1))
        
    