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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        return true;
        if(head->next->next==NULL){
            if(head->val==(head->next)->val)
            return true;
            else 
            return false;
        }
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        vector<int> first;
        vector<int> second;
        if(fast->next==NULL){
            ListNode* temp=head;
            while(temp!=slow){
                first.push_back(temp->val);
                temp=temp->next;
            }
            temp=temp->next;
            while(temp!=NULL){
                second.push_back(temp->val);
                temp=temp->next;
            }
        }
        else{
            ListNode* temp=head;
            while(temp!=slow->next){
                first.push_back(temp->val);
                temp=temp->next;
            }
            while(temp!=NULL){
                second.push_back(temp->val);
                temp=temp->next;
            }
        }
        reverse(second.begin(),second.end());
        if(first==second)
        return true;
        else 
        return false;
    }
};
