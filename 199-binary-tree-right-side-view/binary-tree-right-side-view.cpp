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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
    
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root,{0,0}});
        
        map<int, int>mp;
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* &node = front.first;
            auto coordinate = front.second;
            auto &row = coordinate.first;
            auto &col = coordinate.second;
            if(mp.find(row) == mp.end() && node != NULL)mp[row] = node -> val;
            if(node != NULL){
                if(node->right)q.push({{node -> right},{row + 1, col + 1}});
                if(node->left)q.push({{node -> left},{row + 1, col - 1}});
            }
            
        }
        for(auto c:mp)ans.push_back(c.second);
        return ans;
        
    }
};