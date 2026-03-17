/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if(!root) return true;
        int left = root->left?root->left->val:0;
        int right = root->right?root->right->val:0;
        if(left==0 && right ==0) return true;
        if(left+right!=root->val) return false;
        return checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};
