/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fillstack1(TreeNode* root,TreeNode* target,stack<TreeNode*>& st1){
        if(root == NULL)return;
        if(root == target){
            st1.push(root);
            return;
        }
        

        st1.push(root);
        fillstack1(root->left,target,st1);
        fillstack1(root->right,target,st1);
        if(!st1.empty() && st1.top() == target)return;
        st1.pop();
        return;

    }

    void fillstack2(TreeNode* root,TreeNode* target,stack<TreeNode*>& st2){
        if(root == NULL)return;
        if(root == target){
            st2.push(root);
            return;
        }
        
        st2.push(root);
        fillstack2(root->left,target,st2);
        fillstack2(root->right,target,st2);
        if(!st2.empty() && st2.top() == target)return;
        st2.pop();
        return;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        fillstack1(root,p,st1);
        fillstack2(root,q,st2);

        if(st1.size() > st2.size()){
            while(st1.size() != st2.size()){
                st1.pop();
            }
        }

        if(st2.size() > st1.size()){
            while(st1.size() != st2.size()){
                st2.pop();
            }
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top() == st2.top())return st1.top();
            st1.pop();
            st2.pop();
        }

        return root;
        
    }
};