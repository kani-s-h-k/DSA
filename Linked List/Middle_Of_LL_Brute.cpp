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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        int n=0,cnt=0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp=head;
        while(cnt!=n/2){
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
};