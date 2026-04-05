#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=nullptr;
    }

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data>b->data;
        }
};

Node* createLL(vector<int> &nums){
    Node* head = new Node(nums.at(0));
    Node* temp = head;
    for(int i =1;i<nums.size();i++){
        Node* node = new Node(nums.at(i));
        temp->next = node;
        temp=temp->next;
    }
    return head;
}

Node* mergerSortedArray(vector<Node*> lists){
   priority_queue<Node*,vector<Node*>,Compare> pq;
   for(auto list: lists){
        if(list) pq.push(list);
   }
   Node* dummy = new Node(-1);
   Node* temp = dummy;
   while(!pq.empty()){
    Node* node = pq.top();
    pq.pop();
    temp->next=node;
    temp=temp->next;
    if(node->next) pq.push(node->next);
   }
   return dummy->next;
}

void dislplayLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here

    Node* a = new Node(1);
    a->next = new Node(4);
    a->next->next = new Node(10);

    Node* b = new Node(1);
    b->next = new Node(3);
    b->next->next = new Node(4);

    Node* c = new Node(2);
    c->next = new Node(6);
    vector<Node*> lists={a,b,c};
    Node* head = mergerSortedArray(lists);
    dislplayLL(head);
    return 0;
}