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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> numbers;

        for(int i = 0;i < lists.size();i++){
            ListNode* head = lists[i];
            while(head != NULL){
                numbers.push_back(head->val);
                head = head->next;
            }
        }
        sort(numbers.begin(),numbers.end());

        if(numbers.size() == 0){
            return NULL;

        }
        ListNode* answer = new ListNode(numbers[0]);
        ListNode* tempo = answer;
        for(int i = 1;i < numbers.size();i++){
            ListNode* temp = new ListNode(numbers[i]);
            answer->next = temp;
            answer = answer->next;
        }
        return tempo;
        
    }
};