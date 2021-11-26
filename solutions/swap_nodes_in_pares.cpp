/*https://leetcode.com/problems/swap-nodes-in-pairs/*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr){return nullptr;}
        auto temp= head;
        auto newHead= head->next;
        ListNode* prev=nullptr;
        
        while(temp!= nullptr && temp->next!=nullptr){
            auto node1= temp;
            auto node2= temp->next;
            node1->next= node2->next;
            node2->next= node1;
            
            if(prev!=nullptr){
                prev->next= node2;
            }
            prev=node1;
            temp= temp->next;
        }
        
        return newHead==nullptr? head: newHead;
        
    }
};
