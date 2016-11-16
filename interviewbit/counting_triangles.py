def nTriang(A):
    count = 0
    A.sort()
    print A

    n = len(A)
    for i in range(0,n-2):
        a = A[i]
        for j in range(i+1,n-1):
            b = A[j]
            c = a + b
            for k in range(j+1,n):
                if A[k] < c:
                    count += 1

    return (count % (10 ** 9 + 7))

A = [ 11, 18, 13, 1, 19, 14, 8, 15, 16, 20, 12, 6, 10, 5, 17, 2, 4 ]
print nTriang(A)