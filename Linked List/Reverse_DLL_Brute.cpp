#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* back;
    Node* next;
    
    Node(int data1){
        data=data1;
        back=nullptr;
        next=nullptr;
    }
    
    Node(int data1, Node* back1, Node* next1){
        data = data1;
        back=back1;
        next=next1;
    }
};

Node* createDLL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i =1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        temp->back = prev;
        prev->next = temp;
        prev= temp;
    }
    return head;
}

Node* reverseDLLBrute(Node* head){
    Node* temp = head;
    stack<int> st;
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

Node* reverseDLLOptimal(Node* head){
    Node* last = nullptr, *current = head;
    while(current){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    head = last->back;
    return head;
}
void traverseDLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main() {
    int n;
    cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	Node* head = createDLL(nums);
    traverseDLL(reverseDLLOptimal(head));
}
