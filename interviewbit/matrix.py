	def searchMatrix(A, x):
		m = len(A)
		n = len(A[0])
		
		row = -1
		col = -1
		
		# binary_search_row(A, B)
		start = 0 
		end = m - 1

		while start<=end:
			mid = (start + end) / 2
			if A[mid][0] <= x and A[mid][n-1] >= x:
				row = mid
				break

			elif A[mid][0] > x:
				end = mid - 1

			elif A[mid][n-1] < x:
				start = mid + 1

		if row == -1:
			return 0

		# binary_search_column(A, B)
		start = 0 
		end = n - 1

		while start<=end:
			mid = (start + end) / 2
			if A[row][mid] == x:
				return 1

			elif A[row][mid] > x:
				end = mid - 1

			elif A[row][mid] < x:
				start = mid + 1


		if col == -1:
			return 0









A = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

B = 41

print searchMatrix(A, B)