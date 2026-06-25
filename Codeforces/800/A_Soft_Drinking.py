n, k, l, c, d, p, nl, np = map(int, input().split())
totalml=k*l
drinks=totalml//nl
limes=c*d
salt=p//np
print(min(drinks,limes,salt)//n)
# print(totalml,limes,drinks,salt)