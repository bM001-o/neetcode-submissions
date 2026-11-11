# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = head
        count = 0

        while temp:
            count += 1
            temp = temp.next

        target = count - n + 1

        if target == 1:
            return head.next
        
        tmp = head
        for i in range(1,target):
            if i == target - 1:
                tmp1 = tmp.next
                tmp.next = tmp.next.next
                tmp1.next = None
            tmp = tmp.next

        return head    