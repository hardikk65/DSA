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
        ListNode* slow = head;
        ListNode* fast = head;

        int count = 0;

        while(slow != NULL){
            count++;
            slow = slow->next;
        }
        count = (count/2);

        while(count != 0){
            count--;
            fast= fast->next;
        }
        return fast;
        
    }
};