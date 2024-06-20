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
    void addelements(TreeNode* root, vector<int>& answer){
        if(root == NULL)return;
        addelements(root->left,answer);
        answer.push_back(root->val);
        addelements(root->right,answer);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> answer;
        addelements(root,answer);

        for(int i = 0;i < answer.size() - 1;i++){
            if(answer[i + 1] <= answer[i])return false;
        }
        return true;
    }
};