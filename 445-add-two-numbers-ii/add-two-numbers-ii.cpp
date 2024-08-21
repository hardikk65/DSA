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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string ans1;
        string ans2;
        // int count1 = 1;
        while(l1 != NULL){
            char a = l1->val + 48;
            ans1 += a;
            l1 = l1->next;
        }
        while(l2 != NULL){
            char a = l2->val + 48;
            ans2 += a;
            l2 = l2->next;
        }

        string result;

        int i = ans1.size() - 1;
        int j = ans2.size() - 1;

        int carry = 0;

        while(i >= 0 && j >= 0){
            
            int a = ans1[i] - 48;
            int b = ans2[j] - 48;
            int rem = a + b + carry;
            result += (rem%10 + 48);
            carry = rem/10;
            i--;
            j--;
            
 
        }


        if(i < 0 && j < 0 && carry != 0)result += (carry + 48);
        else if(j < 0){
            for(int p = i;p >= 0;p--){
                int a = ans1[p] - 48;
                int rem = a + carry;
                result += rem%10 + 48;
                carry = rem/10;
            }

            if(carry != 0)result += carry + 48;
        }
        else if(i < 0){

            for(int p = j;p >= 0;p--){
                int a = ans2[p] - 48;
                int rem = a + carry;
                result += rem%10 + 48;
                carry = rem/10;
            }
            if(carry != 0)result += carry + 48;

        }

        
        cout<<result<<endl;
        ListNode* a = new ListNode();
        ListNode* head = a;
        int ptr = result.size() - 1;

        while(ptr >= 0){
            if(ptr == 0){
                a->val = result[ptr] - 48;
                ptr--;
            }
            else{
                a->val = result[ptr] - 48;
                ListNode* b = new ListNode();
                a->next = b;
                a = a->next;
                ptr--;
            }

        }
        
        return head;

        
        
    }
};