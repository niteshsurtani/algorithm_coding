maximum = 0

def maxPathSum(self, A):
    global maximum
    
    if not A:
        return 0
        
    val = A.val + self.maxPathSum(A.left) + self.maxPathSum(A.right)
    if val > maximum:
        maximum = val
    return maximum

