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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        if(length < 4)return {-1,-1};

        vector<int> criticalpoints;
        int prev = head->val;
        head = head->next;
        int index = 1;

        while(head->next != NULL){
            if(prev < head->val && head->val > head->next->val)criticalpoints.push_back(index);
            else if(prev > head->val && head->val < head->next->val)criticalpoints.push_back(index);
            prev = head->val;
            index++;
            head = head->next;
        }

        if(criticalpoints.size() < 2)return {-1,-1};

        int maxdistance = criticalpoints[criticalpoints.size() - 1] - criticalpoints[0];
        int mindistance = INT_MAX;
        for(int i = 0;i < criticalpoints.size() - 1;i++){
            mindistance = min(mindistance,criticalpoints[i + 1] - criticalpoints[i]);
        }

        return {mindistance,maxdistance};
        
    }
};