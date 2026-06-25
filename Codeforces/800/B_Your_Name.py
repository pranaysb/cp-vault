t=int(input())
for i in range(0,t):
    waste=input()
    inputy=input()
    w1,w2=inputy.split()
    list1=list(w1)
    list2=list(w2)
    list1.sort()
    list2.sort()
    if list1==list2:
        print("YES")
    else:
        print("NO")
        
    
    