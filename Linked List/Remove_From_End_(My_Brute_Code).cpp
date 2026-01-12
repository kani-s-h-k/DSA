/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head,*prev = nullptr,*front = nullptr;
        if(head==nullptr || head->next == nullptr) return head;
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        head=reverseLL(head);
        if(n==1){
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            head=reverseLL(head);
            return head;
        }
        ListNode* temp = head,*prev = nullptr;
        int cnt =0;
        while(temp){
            cnt++;
            if(cnt==n){
                prev->next = temp->next;
                temp->next = nullptr;
                delete temp;
                break;
            }
            prev = temp;
            temp=temp->next;
        }
        head=reverseLL(head);
        return head;
    }
};