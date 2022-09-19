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
  ListNode* reverseEvenLengthGroups(ListNode* head) {
    ListNode* cur = head, *end = head;
    int groupSize = 2;
    
    while (cur) {
      for (int i = 0; i < groupSize and end; i++) {
        if (cur != end and !end->next and i % 2 == 0) { // handle edge case: the length of last group is even
          reverseList(cur->next, end->next);
          cur->next = end;
          return head;
        }
        end = end->next;
      }
      
      if (end and groupSize % 2 == 0) {
        ListNode* nextGroupHead = end->next, *next = cur->next;
        reverseList(cur->next, end->next);
        cur->next->next = nextGroupHead; // after reversing the list, we have to rearrange the connection
        cur->next = end;
        cur = next;
        end = cur;
      }
      else {
        cur = end;
      }
      groupSize++;
    }
    
    return head;
  }
  
private:
  void reverseList(ListNode* cur, ListNode* end) {
    ListNode* prev = nullptr;
    while (cur != end) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
  }
};