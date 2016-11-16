# def add(a,b):
# 	a = a[::-1]
# 	b = b[::-1]

# 	if len(a) < len(b):
# 		a, b = b, a

# 	m = len(a)
# 	n = len(b)

# 	l = min(m,n)
# 	p = max(m,n)
# 	i = 0

# 	s = 0
# 	c = 0
# 	ad = ""
# 	while i<l:
# 		s = int(a[i]) + int(b[i]) + c
# 		c = s/10
# 		v = s%10
# 		ad += str(v)
# 		i += 1

# 	while i<p:
# 		s = int(a[i]) + c
# 		c = s/10
# 		v = s%10
# 		ad += str(v)
# 		i += 1
	
# 	if c>0:
# 		ad += str(c)

# 	return ad[::-1]

# def  krakenCount(m, n):
# 	if m < n:
# 		m, n = n, m
# 	a = []
	
# 	for i in range(n):
# 		a.append("1")

	
# 	for i in range(1,m):
# 		b = []
# 		b.append("1")
# 		for j in range(1,n):
# 			b.append(add(add(a[j],a[j-1]),b[j-1]))

# 		a = b

# 	return b[n-1]

# # print add("123","4567")
# print krakenCount(3,3)







# def add(a,b):
# 	a = a[::-1]
# 	b = b[::-1]

# 	if len(a) < len(b):
# 		a, b = b, a

# 	m = len(a)
# 	n = len(b)

# 	l = min(m,n)
# 	p = max(m,n)
# 	i = 0

# 	s = 0
# 	c = 0
# 	ad = ""
# 	while i<l:
# 		s = int(a[i]) + int(b[i]) + c
# 		c = s/10
# 		v = s%10
# 		ad += str(v)
# 		i += 1

# 	while i<p:
# 		s = int(a[i]) + c
# 		c = s/10
# 		v = s%10
# 		ad += str(v)
# 		i += 1
	
# 	if c>0:
# 		ad += str(c)

# 	return ad[::-1]




def  krakenCount(m, n):
    if m < n:
        m, n = n, m
    a = []
    
    if m == 0:
        return 0
    if m == 1:
        return 1
    
    for i in range(n):
        a.append(1)

    c = []
    c.append(a)
    for i in range(1,m):
        b = []
        b.append(1)
        for j in range(1,n):
            b.append(a[j] + a[j-1] + b[j-1])

        a = b
        c.append(a)

    for i in range(m):
    	for j in range(n):
    		print str(c[i][j]) + " ",
    	print 
    return b[n-1]
    
print krakenCount(5,5)