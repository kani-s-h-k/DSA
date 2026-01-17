/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        if(head==nullptr ||head->next == nullptr) return {};
         ListNode* temp1 = head;
        vector<vector<int>> ans;

        while(temp1){
        vector<int> pair;
        ListNode* temp2 = temp1->next;
        while(temp2 && temp1->data + temp2->data<=k){
            if(temp1->val + temp2->val == k){
                pair.emplace_back(temp1->val);
                pair.emplace_back(temp2->val);
                ans.emplace_back(pair);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return ans;
    }
};