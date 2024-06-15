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

    void levelordertraversal(TreeNode* root,int level,vector<vector<int>>& answer){
        if(root == NULL){
            return;
        }
        answer[level].push_back(root->val);
        levelordertraversal(root->left,level + 1,answer);
        levelordertraversal(root->right,level + 1,answer);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> answer(maxlevel(root,0),vector<int>(0));
        levelordertraversal(root,0,answer);

        return answer;
        
    }
};