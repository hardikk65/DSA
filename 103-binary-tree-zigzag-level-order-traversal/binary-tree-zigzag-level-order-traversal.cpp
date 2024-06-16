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


    void zigzag(TreeNode* root, vector<vector<int>>& answer,int level){
        if(root == NULL)return;

        if(level%2 == 0)answer[level].push_back(root->val);
        if(level%2 != 0)answer[level].insert(answer[level].begin(),root->val);

        zigzag(root->left,answer,level + 1);
        zigzag(root->right,answer,level + 1);

        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer(maxlevel(root,0),vector<int>(0));
        zigzag(root,answer,0);

        return answer;
        

    }
};