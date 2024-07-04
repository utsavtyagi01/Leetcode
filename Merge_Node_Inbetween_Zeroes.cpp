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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head;
        ListNode* nextt=head->next;
        while(nextt!=NULL){
            if(nextt->val==0&&nextt->next==NULL)
            break;
            if(nextt->val!=0){
                curr->val+=nextt->val;
                nextt=nextt->next;
            }
            else{
                curr->next=nextt;
                curr=curr->next;
                nextt=nextt->next;
            }
        }
        curr->next=NULL;

        return head;
    }
};
