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
    // ListNode* e(ListNode* ptr,ListNode* head){
    // if(ptr->next == NULL)return ptr;
    // else if(ptr->next->next == NULL)return ptr;
    // else{
    //     ptr->next= ptr->next->next;
    // }
    // e(ptr, head);
    // return head;
    // }

    // ListNode* o(ListNode* ptr,ListNode* head){
    // if(ptr->next== NULL)return ptr;
    // else if(ptr->next->next == NULL)return ptr;
    // else{
    //     ptr->next= ptr->next->next;
    // }
    // o(ptr,head);
    // return ptr;
    // }
    ListNode* oddEvenList(ListNode* head) {
        // ListNode* s1 = head;
        // ListNode* s2 = head->next;
        // s1 = o(s1,head);
        // s2 = e(s2,head->next);

        // s1->next = s2;
        // return s1;

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* o = head;
        ListNode* e = head->next;

        ListNode* o1 = head;
        ListNode* e1 = head->next;

        ListNode* s1 = head->next;

        while(o != NULL && e != NULL){
            o = o->next;
            e = e->next;

            if(o != NULL){
                o = o->next;
                o1->next = o;
                if(o != NULL)o1 = o;
            }

            if(e != NULL){
                e = e->next;
                e1->next = e;
                e1 = e;
            }
        }

        o1->next = s1;

        return head;



        
    }
};