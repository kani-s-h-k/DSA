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

void preorder(Node* node){
    if(node == nullptr) return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
    
}

void inorder(Node* node){
    if(node == nullptr) return;
    preorder(node->left);
    cout<<node->data<<" ";
    preorder(node->right);
}
void postorder(Node* node){
    if(node == nullptr) return;
    preorder(node->left);
    preorder(node->right);
    cout<<node->data<<" ";
}

int main() {
    Node* root = new Node(5);
    root->left=new Node(2);
    root->right = new Node(6);
    cout<<"Postorder: ";
    postorder(root);
    return 0;
}
