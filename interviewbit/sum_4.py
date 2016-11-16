A = [1,0,-1,0,-2,2]
B = 0
A.sort()
print A

sums = {}
result = []

l = len(A)
for i in range(0, l-1):
    for j in range(i+1, l):
        s = A[i] + A[j]
        search = B - s
        
        try:
            if sums[search]:
                ls = sums[search]
                a1 = ls[0]
                a2 = ls[1]
                
                if a1 != i and a1 != j and a2 != i and a2 != j:
                    ls = [a1, a2, i, j]
                    ls.sort()
                    res = [A[ls[0]], A[ls[1]], A[ls[2]], A[ls[3]]]
                    if res not in result:
                        result.append(res)
                
        except:
            sums[s] = [i, j]

print result