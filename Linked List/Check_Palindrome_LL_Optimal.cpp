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
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head, *second = newHead;
        while(second){
            if(first->val!=second->val){
                newHead=reverseLL(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        newHead=reverseLL(newHead);
        return true;
    }
};