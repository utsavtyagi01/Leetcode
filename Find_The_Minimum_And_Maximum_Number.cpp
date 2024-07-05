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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
         if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nextt=head->next->next;

        int currnode=2;
        vector<int> criticalpts;
        while(nextt!=NULL){
            if((prev->val<curr->val&&curr->val>nextt->val) || (prev->val>curr->val&&curr->val<nextt->val))
            criticalpts.push_back(currnode);

            prev=curr;
            curr=nextt;
            nextt=nextt->next;
            currnode++;

        }
        
        if(criticalpts.size()<2)
        return {-1,-1};
        int max=criticalpts[criticalpts.size()-1]-criticalpts[0];
        int min=INT_MAX;
        for(int i=0;i<criticalpts.size()-1;i++){
            if(min>criticalpts[i+1]-criticalpts[i])
            min=criticalpts[i+1]-criticalpts[i];
        }

        return {min,max};
    }
};
