t=int(input())
while t>0:
    t-=1
    a=int(input())
    arr=list(map(int,input().split()))
    fin=sorted(arr)
    print(fin[a-1])
