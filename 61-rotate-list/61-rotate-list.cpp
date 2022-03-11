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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = head;
        ListNode* nhead = head;
        int size = 1;
        if(!head || head->next == NULL||k==0) return head;
        
        while(dummy->next){
            dummy = dummy->next;
            size++;
        }
        dummy->next = head;
        if(k %= size){
            for(auto i = 0; i < size-k; i++)
            dummy = dummy->next;}
        
            nhead = dummy->next;
            dummy->next = NULL;
        
        return nhead;
        
    }
};