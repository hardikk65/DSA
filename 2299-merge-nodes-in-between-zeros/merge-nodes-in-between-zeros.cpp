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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead = new ListNode(0);
        ListNode* answer = newhead;
        head = head->next;
        while(head->next != NULL){
            if(head->val == 0){
                ListNode* temp = new ListNode(0);
                newhead->next = temp;
                newhead = newhead->next;
            }
            else{
                newhead->val += head->val;
            }
            head = head->next;
        }
        return answer;
    }
};