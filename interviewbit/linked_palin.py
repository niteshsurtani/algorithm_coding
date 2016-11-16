# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param A : head node of linked list
    # @return an integer
    def reversal(self, A):
        curr = A
        prev = None

        while curr:
            nxt = curr.next
            curr.next = prev

            prev = curr
            curr = nxt

        return prev

    def lPalin(self, A):
        if A == None or A.next == None:
            return True

        slw = A
        fst = A
        prev = None

        while fst:
            prev = slw

            slw = slw.next

            fst = fst.next
            if fst:
                fst = fst.next

        rev = self.reversal(prev)

        while rev:
            if A.val != rev.val:
                return False

            A = A.next
            rev = rev.next

        return True

l = ListNode(1)
n = ListNode(2)
p = ListNode(1)

l.next = n
l.next.next = p

s = Solution()
print s.lPalin(l)
        
        