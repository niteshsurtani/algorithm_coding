import sys
A = [1,2,-2,4,-4]
l = len(A)

d = {}
s = 0
start = -1
end = -1

d[0] = -1

maximum = -1

for i in range(0,l):
    s += A[i]
    try:
        if d[s] < sys.maxint:
            # print "Yes"
            temp_start = d[s] + 1
            temp_end = i
            
            if(temp_end - temp_start > maximum):
                start = temp_start
                end = temp_end
                maximum = temp_end - temp_start
    except:
        # print "Here = " + str(s) + " -> " + str(i)
        d[s] = i
        
return A[start:end+1]