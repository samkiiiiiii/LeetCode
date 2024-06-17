# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.value(root,0)

    def value(self,root,num):
        if root is None:
            return 0

        curr_val = num * 10 + root.val

        # return if it is leaf
        if root.left is None and root.right is None:
            return curr_val  

        left = self.value(root.left,curr_val)
        right = self.value(root.right,curr_val)

        return left + right


        