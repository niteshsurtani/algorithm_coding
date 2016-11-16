def solution(a):
    # write your code in Python 2.7
    n = len(a)
    
    sum = 0
    for num in a:
        sum += num
    
    left = 0
    right = 0
    
    for i in range(0,n):
        if sum - a[i] - left == left:
            print i
        left += a[i]
    
    return -1

# a= [-1, 3, -4, 5, 1, -6, 2, 1] 
a = [0,4,-4,2,-2,0]
print solution(a)