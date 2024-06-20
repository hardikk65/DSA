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
    TreeNode* findnode(TreeNode* root,int key){
        if(root == NULL)return root;
        if(root->val == key)return root;

        else if(root->val > key)return findnode(root->left,key);

        return findnode(root->right,key);
        
    }

    TreeNode* prevnode(TreeNode* root, int key){
        if(root == NULL)return root;

        if(root->left != NULL && root->left->val == key)return root;
        if(root->right != NULL && root->right->val == key)return root;

        else if(root->val > key)return prevnode(root->left,key);

        return prevnode(root->right,key);
    }

    void addelements(TreeNode* root, vector<int>& answer){
        if(root == NULL)return;

        addelements(root->left,answer);
        answer.push_back(root->val);
        addelements(root->right,answer);
        return;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)return NULL;

        if(root->val == key && (root->left == NULL && root->right == NULL))return NULL;
        vector<int> answer;
        if(findnode(root,key)){

            TreeNode* a = findnode(root,key);
            addelements(findnode(root,key)->left,answer);
            addelements(findnode(root,key)->right,answer);

            if(a->left == NULL && a->right == NULL){
                TreeNode* c = prevnode(root,key);
                if(c){
                    if(c->left != NULL && c->left->val == key)c->left = NULL;
                    else{
                        c->right = NULL;
                    }
                }
                return root;
            }
            a->left = NULL;
            a->right = NULL;

            a->val = answer[0];

            for(int i = 1;i < answer.size();i++){
                TreeNode* b = new TreeNode(answer[i]);

                a->right = b;

                a = a->right;
            }

            return root;

        }
        // cout<<findnode(root,key)->val<<endl;

        return root;
        
    }
};