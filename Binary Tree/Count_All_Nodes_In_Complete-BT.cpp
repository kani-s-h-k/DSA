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
    int findLeftHeight(TreeNode* node){
        int count = 0;
        if(!node) return 0;
        while(node){
            count++;
            node=node->left;
        }
        return count;
    }
    int findRightHeight(TreeNode* node){
        int count = 0;
        if(!node) return 0;
        while(node){
            count++;
            node=node->right;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};