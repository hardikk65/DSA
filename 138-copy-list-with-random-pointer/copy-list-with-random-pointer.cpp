/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,int> og_map;
        map<int,int> index_map;
        map<int,Node*> final_map;

        Node* temp = head;
        Node* final_list = new Node(0);
        Node* tempo = final_list;

        if(head == NULL){
            return head;
        }

        int i = 0;
        while(temp->next != NULL){
            Node* node = new Node(0);
            tempo->val = temp->val;
            tempo->next = node;
            og_map[temp] = i;
            final_map[i] = tempo;
            tempo = node;
            temp = temp->next;
            i++;
        }
        tempo->val = temp->val;
        og_map[temp] = i;
        final_map[i] = tempo;

        temp = head;

        int count = 0;
        while(temp != NULL){
            if(temp->random == NULL){
                index_map[count] = -1;
            }
            else{
                index_map[count] = og_map[temp->random];
            }
            count++;
            temp = temp->next;
        }

        tempo = final_list;

        int counter = 0;
        while(tempo != NULL){

            if(index_map[counter] == -1){
                tempo->random = NULL;
            }
            else{
                tempo->random = final_map[index_map[counter]];
            }
            counter++;
            tempo = tempo->next;

        }

        return final_list;
        
    }
};