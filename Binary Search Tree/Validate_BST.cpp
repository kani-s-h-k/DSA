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
    bool func(TreeNode* root, long long minVal, long long maxVal){
        if(!root) return true;
        if(root->val>=maxVal || root->val<=minVal) return false;
        return func(root->left,minVal, root->val) && func(root->right,root->val,maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return func(root,LLONG_MIN,LLONG_MAX);
    }
};