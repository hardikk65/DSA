/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL)return 1;
        else if((p == NULL && q != NULL) || (p != NULL && q == NULL))return false;
        else if(p->val == q->val)return check(p->left,q->left)&check(p->right,q->right);
        else if(p ->val != q->val)return false;

        return check(p->left,q->left)&check(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        return check(p,q);
        
    }
};