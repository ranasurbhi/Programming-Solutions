"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        q=[]
        if(not root):
            return root
        q.insert(0,root)
        while(q):
            s=len(q)
            level=[]
            for i in range(s):
                temp=q[-1]
                q.pop()
                level.append(temp)

                if(temp.left) :
                    q.insert(0,temp.left)
                if(temp.right):
                    q.insert(0,temp.right)
            for i in range(1,len(level)):
                level[i-1].next=level[i]
        return root