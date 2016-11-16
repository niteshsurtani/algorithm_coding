def solution(s):
	n = len(s)

	z = 0
	o = 0
	for i in range(0,n):
		if s[i] == "(":
			o += 1
		if s[i] == ")":
			z += 1

	left = 0
	right = n-1

	flag = 0
	while left < right:
		if flag == 0:
			print z, o
			if z == 0:
				return str(left + 1)

			if s[left] == "(":
				o -= 1
				flag = 1
			else:
				z -= 1
				

			left += 1

		else:
			if s[left] == ")":
				z -= 1
				flag = 0
			else:
				o -= 1

			right -= 1
			flag = 0

	return str(left)

s = ")"
print solution(s)	