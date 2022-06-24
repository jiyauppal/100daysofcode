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
    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head;
        if(l1->val <= l2->val){
            head = l1;
            head->next = mergeTwo(l1->next, l2);
        }
        else{
            head = l2;
            head->next = mergeTwo(l1, l2->next);
        }
          return head;  
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode* res = lists[0];
        for(int i = 1; i < lists.size(); i++){
            res = mergeTwo(res, lists[i]);
        }
        return res;
    }
};