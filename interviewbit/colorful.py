class Solution:
    # @param A : integer
    # @return an integer
    def colorful(self, A):
        has = []
            
        l = len(A)
        for i in range(1,l+1):
            for j in range(0,l-i+1):
                num = 1
                for k in range(j, j+i):
                    num *= int(A[k])

                # print num, has                
                if num in has:
                    return 0

                has.append(num)
        return 1

sol = Solution()
print sol.colorful("3245")
