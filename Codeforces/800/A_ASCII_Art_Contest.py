arr = list(map(int, input().split()))
final=sorted(arr)
if final[2]-final[0]>=10:
    print("check again")
else:
    print("final", final[1])