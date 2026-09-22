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
    ListNode* reverseList(ListNode* head) {
        ListNode* Temp1 = NULL;
        ListNode* Temp2 = NULL;
        ListNode* q = head;

        while(q != NULL){
            if(q == head){
                Temp1 = q;
                q = q -> next;
                Temp1 -> next = NULL;
            }
            else{
                Temp2 = q;
                q = q -> next;
                Temp2 -> next = Temp1;
                Temp1 = Temp2;
            }
        }
        return Temp1;
    }
};
