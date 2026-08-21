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
        int Tcount = 0;
        ListNode* p = head;

        while(p != NULL){
            Tcount++;
            p = p -> next;
        }

        int count = 0;
        int target = Tcount - n;

        if(target == 0) {
            return head -> next;
        }

        ListNode* q = head;

        while(q != NULL){
            if(count == target - 1){
                q -> next = q -> next -> next;
                break;
            }
            count++;
            q = q -> next;
        }
        return head;
    }
};
