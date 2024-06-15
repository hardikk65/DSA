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

    void answer(TreeNode* root,int* ans){
        if(root == NULL)return ;

        int maxleft = 0;
        int maxright = 0;
        if(root->left != NULL)maxleft = maxlevel(root->left,0);
        if(root->right != NULL)maxright = maxlevel(root->right,0);

        *ans = max(maxleft + maxright,*ans); 

        answer(root->left,ans);
        answer(root->right,ans);

        return;




    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        answer(root,&ans);

        return ans;
        
    }
};