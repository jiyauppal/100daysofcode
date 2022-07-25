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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val < list2->val){
            res = list1;
            res->next = mergeTwoLists(list1->next, list2);
        }
        else{
            res = list2;
            res->next = mergeTwoLists(list2->next, list1);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode* ans = lists[0];
        for(int i = 1; i < lists.size(); i++){
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};