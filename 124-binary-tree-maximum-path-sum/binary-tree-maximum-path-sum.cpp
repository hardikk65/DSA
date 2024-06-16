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

    int pathsum(TreeNode* root,int* maxi,map<TreeNode*,int>& dp){
        if(root == NULL)return 0;
        if(dp.find(root)!=dp.end()) return dp[root];

        dp[root] = max(root->val,max(root->val + pathsum(root->left,maxi,dp),root->val + pathsum(root->right,maxi,dp)));

        *maxi = max(*maxi,max(dp[root],root->val + pathsum(root->left,maxi,dp) + pathsum(root->right,maxi,dp)));

        return dp[root];

    }
    
    int maxPathSum(TreeNode* root) {
        map<TreeNode*,int> dp;
        int maxi = INT_MIN;
        cout<<pathsum(root,&maxi,dp);
        return maxi;
        
    }
};