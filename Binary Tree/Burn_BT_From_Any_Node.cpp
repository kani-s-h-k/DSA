/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    TreeNode* markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_mark,int start){
        queue<TreeNode*> q;
        TreeNode* target=nullptr;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            if(current->data==start) target=current;
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
        return target;
    }
	public:
		int timeToBurnTree(TreeNode* root, int start){
            unordered_map<TreeNode*, TreeNode*> parent_mark;
            TreeNode* target=markParent(root,parent_mark,start);
            unordered_map<TreeNode*,bool> visited;
            queue<TreeNode*> q;
            q.push(target);
            visited[target]=true;
            int ans =0;
            while(!q.empty()){
                int size = q.size();
                int fl =0 ;
                for(int i =0 ;i<size;i++){
                    auto node = q.front();
                    q.pop();
                    if(node->left && !visited[node->left]){
                        fl=1;
                        visited[node->left]=true;
                        q.push(node->left);
                    }
                    if(node->right && !visited[node->right]){
                        fl=1;
                        visited[node->right]=true;
                        q.push(node->right);
                    }
                    if(parent_mark[node] && !visited[parent_mark[node]]){
                        fl=1;
                        visited[parent_mark[node]]=true;
                        q.push(parent_mark[node]);
                    }
                }
                if(fl) ans++;
            }
            return ans;
		}	
};