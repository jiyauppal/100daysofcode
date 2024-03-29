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
        // int cnt = 0;
        // ListNode* temp = head;
        // while(temp){
        //     cnt++;
        //     temp = temp->next;
        // }
        // temp = head;
        // for(int i = 0; i < cnt/2; i++){
        //     temp = temp->next;
        // }
        // return temp;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};