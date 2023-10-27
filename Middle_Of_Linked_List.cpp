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
    ListNode* middleNode(ListNode* head) {
        ListNode* once=head;
        ListNode* twice=head;
        while( twice!=NULL&&twice->next!=NULL){//Yahan pe twice!=NULL condition pehle aayegi kyuki agar hum second condition pehle likhenge aur twice null hu ato null->next will give error
            twice=(twice->next)->next;
            once=once->next;
        }
        return once;  
    }
};
