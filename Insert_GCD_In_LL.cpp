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
    int gcd(int a, int b){
        while(b!=0){
            int temp=a%b;
            a=b;
            b=temp;
        }

        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL)
        return head;
        ListNode* first=head;
        ListNode* second=head->next;
        while(first!=NULL&&second!=NULL){
            int temp=gcd(first->val,second->val);
            ListNode* node=new ListNode(temp);
            first->next=node;
            node->next=second;
            first=second;
            second=second->next;
        }

        return head;
    }
};
