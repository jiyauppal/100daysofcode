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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     if(l1==NULL && l2==NULL)
         return NULL;
    ListNode* curr = nullptr;
    ListNode* prev = nullptr;
    int carry = 0;
        while(l1 || l2 || carry > 0)
        {
            int sum = 0;
            if(l1){
            sum+=l1->val;
            l1 = l1->next;
            }
            if(l2){
            sum+=l2->val;
            l2 = l2->next;}
            if(carry){
            sum+=carry;
            carry = 0;}
            if(sum > 9)
            {
                int rem = sum%10;
                carry = sum/10;
                sum = rem;
            }
            ListNode* sumNode = new ListNode(sum);
            if(prev == nullptr)
                prev = sumNode;
            else
            {
                curr->next = sumNode;
            }
            curr = sumNode;
            
        }
        return prev;
    }};