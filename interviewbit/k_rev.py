class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

	def insert(self, l, x):
		if l == None:
			return x

		while l.next:
			l = l.next

		l.next = x
		return l

	def printList(self, l):
		while l:
			print str(l.val) + " - > ",
			l = l.next
		print

	def k_rev(self, t, k):

		s1 = s2 = t1 = t2 = head = None
		
		while True:
			n = 0
			prev = None
			curr = t

			if s1 == None:
				s1 = t

			else:
				s2 = t

			while n < k and curr:
				next = curr.next
				curr.next = prev
				prev = curr
				curr = next

				n += 1

			t = curr

			if t1 == None:
				# First iteration
				t1 = prev
				head = t1

			else:
				# Later iterations
				t2 = prev

				s1.next = t2
				s1 = s2


			if t == None:
				break

		return head

l = ListNode(1)
l.insert(l, ListNode(2))
l.insert(l, ListNode(3))
l.insert(l, ListNode(4))
l.insert(l, ListNode(5))
l.insert(l, ListNode(6))
l.insert(l, ListNode(7))
l.insert(l, ListNode(8))
l.insert(l, ListNode(9))
l.insert(l, ListNode(10))
l.insert(l, ListNode(11))

l.printList(l)

head = l.k_rev(l, 3)
head.printList(head)

