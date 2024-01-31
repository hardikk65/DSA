/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> address;
        if(head == NULL){
            return head;
        }
        ListNode* slow = head;
        address[slow] = 1;
        while(slow != NULL){
            slow = slow->next;
            if(address[slow] > 0){
                return slow;
            }
            address[slow]++;
        }

        return NULL;
        
    }
};