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
        ListNode* tempo = head;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while(tempo != NULL){
            ListNode* nva = new ListNode();
            curr->val = tempo->val;
            
            nva->next = curr;
            curr = nva;
            tempo = tempo->next;
        }

        return curr->next;
        
    }
};