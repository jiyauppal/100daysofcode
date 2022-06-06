/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        int l1 =1;
        int l2 = 1;
        while(t1->next){
            l1++;
            t1 = t1->next;
        }
        while(t2->next){
            l2++;
            t2 = t2->next;
        }
        if(t1 != t2) return NULL;
        int m1 = max(0, l1-l2);
        int m2 = max(0, l2-l1);
        while(m1 > 0){
            head1 = head1->next;
            m1--;
        }
        while(m2 > 0){
            head2 = head2->next;
            m2--;
        }
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        return head2;
    }
};