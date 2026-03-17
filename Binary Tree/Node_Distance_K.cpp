/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_mark){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent_mark[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent_mark[current->right]=current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent_mark;
        markParent(root,parent_mark);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i =0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_mark[current] && !visited[parent_mark[current]]){
                    q.push(parent_mark[current]);
                    visited[parent_mark[current]]=true;
                }
            }
        }
        while(!q.empty()){
            ans.emplace_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};