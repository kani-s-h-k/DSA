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
    int sol(TreeNode* root){
        if(root==nullptr) return 0;
        int lh = sol(root->left);
        int rh = sol(root->right);
        return 1+max(lh,rh);
    }
    void findMax(TreeNode* root, int &maxi){
         if(root==nullptr) return ;
        int lh = sol(root->left);
        int rh = sol(root->right);
        maxi=max(maxi,(lh+rh));
        findMax(root->left,maxi);
        findMax(root->right,maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {  
        int maxi = INT_MIN;
        findMax(root,maxi);
        return maxi;
    }
};