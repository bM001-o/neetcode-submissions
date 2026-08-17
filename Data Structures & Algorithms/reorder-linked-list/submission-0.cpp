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
    void reorderList(ListNode* head) {
        vector<ListNode*> res;
        ListNode* a = head;

        while(a != NULL){
            res.push_back(a);
            a = a -> next;
        }

        int i = 0;
        int j = res.size() - 1;
        for(;i < j;i++){
            if(res[i] -> next != res[j]){
                res[j] -> next = res[i] -> next;
                res[i] -> next = res[j];
            }
            j--;
        }
        res[i] -> next = NULL;
    }
};
