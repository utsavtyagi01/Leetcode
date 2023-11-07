/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp= headA;
        int counta=1;
        while(temp->next!=NULL){
            counta++;
            temp=temp->next;
        }
        ListNode* temp1= headB;
        int countb=1;
        while(temp1->next!=NULL){
            countb++;
            temp1=temp1->next;
        }
        if(temp!=temp1)
        return NULL;
        temp=headA;
        temp1=headB;
        if(counta>countb){
            while(counta!=countb){
                counta--;
                temp=temp->next;
            }
        }
        else if(counta<countb){
            while(counta!=countb){
                countb--;
                temp1=temp1->next;
            }
        }
        while(temp1!=temp&&temp!=NULL&&temp1!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        return temp;
        
    }
};
