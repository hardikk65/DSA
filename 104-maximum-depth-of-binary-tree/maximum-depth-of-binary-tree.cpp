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
     int maxlevel(TreeNode* root,int level){
        if(root == NULL){
            return level;
        }
        return max(maxlevel(root->left,level + 1),maxlevel(root->right,level + 1));
    }
    int maxDepth(TreeNode* root) {
        return maxlevel(root,0);
        
    }
};