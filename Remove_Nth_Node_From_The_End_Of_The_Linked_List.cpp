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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        if(count-n==0){
            head=head->next;
            return head;
        }
        int i=1;
        while(i<count-n){
            temp=temp->next;
            i++;
        }
        if(temp->next!=NULL)
        temp->next=temp->next->next;

        return head;

        
    }
};
