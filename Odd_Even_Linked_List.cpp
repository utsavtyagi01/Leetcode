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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* even2=head->next;
        while(odd->next!=NULL&&even2->next!=NULL){
            odd->next=odd->next->next;
            even2->next=even2->next->next;
            odd=odd->next;
            even2=even2->next;
            
        }
        odd->next=even;
        return head;


        
    }
};
