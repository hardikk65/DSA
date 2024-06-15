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
    void postorder1(TreeNode *root,vector<int>& postorder){
    if(root == NULL){
        return;
    }
    postorder1(root->left,postorder);
    postorder1(root->right,postorder);
    postorder.push_back(root->val);
    return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postorder1(root,postorder);

        return postorder;
        
    }
};