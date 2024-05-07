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
    ListNode* doubleIt(ListNode* head) {
        ListNode *Next;
        ListNode *curr=head;
        ListNode *prev=NULL;
      while(curr!=NULL){
          Next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=Next;
      }
      curr=prev;
        int temp=0,carry=0;
        ListNode* temp1;
        while(curr!=NULL){
            temp=curr->val*2+carry;
            if(temp<10){
            curr->val=(temp);
            carry=0;}
            else{
                curr->val=((temp%10));
                carry=temp/10;
            }
            temp1=curr;
            curr=curr->next;
        }
        if(carry!=0){
            temp1->next=new ListNode(carry);
        };
        
        curr=prev;
        prev=NULL;
      while(curr!=NULL){
          Next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=Next;
      }
        return prev;
    }
};
