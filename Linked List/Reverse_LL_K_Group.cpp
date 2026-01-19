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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head,*prevNode=nullptr;
        while(temp){
            ListNode* kNode = findKNode(temp,k);
            if(!kNode){
                if(prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode=kNode->next;
            kNode->next = nullptr;
            reverseLL(temp);
            if(temp == head) head = kNode;
            else prevNode->next = kNode;
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head,*prev = nullptr;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* findKNode(ListNode* temp, int k){
        k-=1;
        while(temp!= nullptr && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
};