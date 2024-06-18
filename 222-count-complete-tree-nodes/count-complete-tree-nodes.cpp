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
    void number(TreeNode* root, int* count){
        if(root == NULL)return;
        *count = *count + 1;
        number(root->left,count);
        number(root->right,count);
        return;
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        number(root,&count);

        return count;
        
    }
};