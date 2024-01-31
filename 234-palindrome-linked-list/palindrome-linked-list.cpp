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
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        string number = "";
        string palindrome = "";
        ListNode* ptr = head;

        while(ptr != NULL){
            char c = ptr->val + 48;
            number += c;
            ptr = ptr->next;
        }
        
        for(int i = number.size() - 1;i >= 0;i--){
            palindrome += number[i];
        }

        if(number == palindrome){
            return true;
        }
        return false;
    }
};