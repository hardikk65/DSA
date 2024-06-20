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
    void addelements(TreeNode* root, map<int,int>& elements){
        if(root == NULL)return;
        addelements(root->left,elements);
        elements[root->val]++;
        addelements(root->right,elements);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int> elements;
        addelements(root,elements);

        for(auto c: elements){
            if(elements.find(k - c.first) != elements.end() && k - c.first != c.first)return true;
        }

        return false;
        
    }
};