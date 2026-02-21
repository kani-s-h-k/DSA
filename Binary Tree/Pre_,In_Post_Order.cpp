#include <bits/stdc++.h>
using namespace std;

class Node{ 
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int key){
            data=key;
            left=nullptr;
            right=nullptr;
        }
};

int main() {
    Node* root = new Node(5);
    root->left=new Node(2);
    root->right = new Node(6);
    stack<pair<Node*,int>> st;
    st.push({root,1});
    vector<int> pre,in,post;
    while(!st.empty()){
        auto top = st.top();
        st.pop();
        if(top.second==1){
            pre.emplace_back(top.first->data);
            top.second++;
            st.push(top);
            if(top.first->left!=nullptr){
                st.push({top.first->left,1});
            }
        }
        else if(top.second==2){
            in.emplace_back(top.first->data);
            top.second++;
            st.push(top);
            if(top.first->right!=nullptr){
                st.push({top.first->right,1});
            }
        }
        else{
            post.emplace_back(top.first->data);
        }
    }
    
    cout<<"Preorder: ";
    for(auto it: pre){
        cout<<it<<" ";
    }
    cout<<endl;
   cout<<"Inorder: ";
    for(auto it: in){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Postorder: ";
    for(auto it: post){
        cout<<it<<" ";
    }
    cout<<endl;

}
