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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
//         if(!head || !head->next) return head;
//         ListNode* nHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
        
//         return nHead;
    }
};
// Iterative Approach
// ListNode* curr = head;
//         ListNode* prev = NULL;
//         ListNode* next;
//         while(curr){
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         head = prev;
//         return head;
//RECURSIVE APPROACH
// ListNode* dummy = NULL;
//         while(head){
//             ListNode* next = head->next;
//             head->next = dummy;
//             dummy = head;
//             head = next;
//         }
//         return dummy;

