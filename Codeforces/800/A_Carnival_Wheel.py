t=int(input())
while t:
    a,b,c=map(int, input().split())
    ans=0
    for i in range (0,a):
        ans=max (ans, (b+c)%a)
        b=b+b
    t=t-1
    print(ans)