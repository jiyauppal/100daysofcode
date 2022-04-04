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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node1 = nullptr;
        ListNode* node2 = nullptr;
        for(auto p = head; p != nullptr; p=p->next)
        {
            node2 = node2 == nullptr ? nullptr : node2->next;
            if(--k == 0){
                node1 = p;
                node2 = head;
            }
        }
        if(node1->val == node2->val)
            return head;
        else
            swap(node1->val, node2->val);
        
        return head;
    }
};