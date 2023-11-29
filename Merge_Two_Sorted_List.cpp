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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        if(list1==NULL&&list2==NULL)
            return NULL;
        ListNode* list3=NULL;
        ListNode* temp=NULL;
        if((list1->val<=list2->val)){
            list3=new ListNode;
                    list3->val=list1->val;
                    list3->next=NULL;
            list1=list1->next;
        }
        else{
                    list3=new ListNode;
                    list3->val=list2->val;
                    list3->next=NULL;
                    temp=list3;
                list2=list2->next;
            
        }
        temp=list3;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<=list2->val){
                    ListNode *node=new ListNode;
                    node->val=list1->val;
                    node->next=NULL;
                    temp->next=node;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                    ListNode *node=new ListNode;
                    node->val=list2->val;
                    node->next=NULL;
                    temp->next=node;
                temp=temp->next;
                list2=list2->next;
            }
        }
        while(list1!=NULL){
             ListNode *node=new ListNode;
                    node->val=list1->val;
                    node->next=NULL;
                     temp->next=node;
                temp=temp->next;
                list1=list1->next;
            
        }
         while(list2!=NULL){
             ListNode *node=new ListNode;
                    node->val=list2->val;
                     temp->next=node;
                temp=temp->next;
                list2=list2->next;
            
        }
        return list3;
        
    }
};
