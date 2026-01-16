/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* temp = head, *prev = nullptr,*front=nullptr;
        while(temp){
            front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode *addOne(ListNode *head) {
        head=reverseLL(head);
        ListNode* temp = head;
        int carry = 1;
        while(temp){
            temp->val +=carry;
            if(temp->val<10){
                carry=0;
                break;
            }
            else{
                temp->val=0;
                carry=1;
            }
            temp=temp->next;
        }
        head=reverseLL(head);
        if(carry==1){
            ListNode* temp = new ListNode(1,head);
            head=temp;
        }
        return head;
    }
};