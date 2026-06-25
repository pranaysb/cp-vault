`a=int(input())
arr=list(map(int,input().split()))
sorty=sorted(arr)
ans=a
for i in range (1,a):
    if( sum(sorty[-i:])>sum(sorty[:a-i])):
        ans=i
        break
print(min(ans,a))`