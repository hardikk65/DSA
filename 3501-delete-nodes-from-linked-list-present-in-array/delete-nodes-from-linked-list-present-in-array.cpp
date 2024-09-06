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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int> check;
        for(auto i:nums)check[i]++;
        vector<int> new_nums;


        while(head != NULL){
            if(check[head->val] == 0)new_nums.push_back(head->val);
            head = head->next;
        }
        ListNode* temp1 = new ListNode();
        ListNode* temp2 = temp1;
        for(int i = 0;i < new_nums.size();i++){
            if(i < new_nums.size() - 1){
                temp1->val = new_nums[i];
                ListNode* b = new ListNode();
                temp1->next = b;
                temp1 = temp1->next;

            }
            else{
                temp1->val = new_nums[i];
            }
            
        }
        return temp2;
    }
};