def  maxLength(a, k):
    n = len(a)
    
    back = 0
    front = 0
    max_len = 0
    total = 0
    
    while(front < n):
        total += a[front]
        if(total > k):
            l = front - back
            max_len = max(l, max_len)
            
            while(total > k):
                total -= a[back]
                back += 1
                
        front += 1

    l = front - back
    max_len = max(l, max_len)

    return max_len

a = [3,5,2,7,4,3,1,6]
print maxLength(a, 8)