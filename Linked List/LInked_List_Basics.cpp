#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* createLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void traverseLinkedList(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int linkedListLength(Node* head){
    int cnt=0;
    while(head!=nullptr){
        cnt++;
        head=head->next;
    }
    return cnt;
}
int searchInLinkedList(Node* head, int target){
    while(head!=nullptr){
        if(head->data == target) return 1;
        head=head->next;
    }
    return 0;
}
int main() {
	vector<int> arr={1,2,3,4};
	Node* head = createLinkedList(arr);
	traverseLinkedList(head);
    cout<<linkedListLength(head)<<endl;
    if(searchInLinkedList(head,5)){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
}
