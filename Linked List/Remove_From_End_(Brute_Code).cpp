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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
        ListNode* temp = head;
        int cnt =0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        int res = cnt - n;
        temp = head;
        if(res == 0){
            head=head->next;
            delete temp;
            return head;
        }
        cnt = 0;
        while(temp){
            cnt++;
            if(cnt==res){
                ListNode* delNode = temp->next;
                temp->next=temp->next->next;
                delete delNode;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};