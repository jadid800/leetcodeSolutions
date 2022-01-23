import random
class Solution:
    nodeVals=[]
    def __init__(self, head: Optional[ListNode]):
        self.nodeVals=[]
        while(head):
            self.nodeVals.append(head.val)
            head= head.next

    def getRandom(self) -> int:
        index= random.randint(0, len(self.nodeVals)-1)
        return self.nodeVals[0]
        

