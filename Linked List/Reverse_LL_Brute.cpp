#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int data1){
        data = data1;
    }
    
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
};

Node* createLL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        prev->next = temp;
        prev=temp;
    }
    return head;
}

void traverseLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* reverseLL(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++){
	    cin>>nums[i];
	}
    Node* head = createLL(nums);
    traverseLL(head);
    traverseLL(reverseLL(head));
    return 0;
    
}
