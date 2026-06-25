t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    s=input().strip()
    arr=list(map(int,s))
    last=s.rfind('1')
    # ans=ones+b*(ones)
    if last==-1:
        print(len(arr))
    else:
        for i in  range (a):
            if(arr[i]==1):
                for j in range (i+1,i+ min(b,a-last-1)):
                    arr[j]=1
        ones=arr.count(1)
        ans=a-ones
        print(ans)
        
    
    
