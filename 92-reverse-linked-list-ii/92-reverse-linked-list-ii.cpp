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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;   //to return result
        ListNode* curr;
        dummy->next = head;
        for(int i = 0; i < left-1; i++) 
            prev = prev->next; // until you find or reach the left index
        curr = prev->next;   //at left index
        for(int i = 0; i < right-left; i++){  //loop for right-left times
            ListNode* temp = prev->next;    // swap the next nodes
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};