# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        q = deque([(root,float("-infinity"),float("infinity"))])

        while q:
            node, Min, Max = q.popleft()

            if not(node.val > Min and node.val < Max):
                return False
            if node.left:
               q.append((node.left,Min,node.val))
            if node.right:
                q.append((node.right,node.val,Max))

        return True 
        
        