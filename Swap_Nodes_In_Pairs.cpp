/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr=head;
        int temp=0;
        while(curr!=NULL&&curr->next!=NULL){
            temp=curr->val;
            curr->val=(curr->next)-> val;
            (curr->next)->val=temp;
            if(curr->next!=NULL)
            curr=curr->next->next;
            else 
            break;
        }
        return head;
    }
};
