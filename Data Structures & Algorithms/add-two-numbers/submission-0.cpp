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
        ListNode* head = new ListNode();
        ListNode* prev = head;
        bool carry = false;

        while(l1 != nullptr && l2 != nullptr){
            int curr = l1 -> val + l2 -> val;
            if(carry){
                curr += 1;
                carry = false;
            }
            if(curr >= 10){
                curr = curr % 10;
                carry = true;
            }
            ListNode* newNode = new ListNode(curr);
            prev -> next = newNode;
            prev = newNode;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != nullptr){
            int curr = l1 -> val;
            if(carry){
                curr = curr + 1;
                carry = false;
            }
            if(curr >= 10){
                curr = curr % 10;
                carry = true;
            }
            ListNode* newNode = new ListNode(curr);
            prev -> next = newNode;
            prev = newNode;

            l1 = l1 -> next;
        }
        while(l2 != nullptr){
            int curr = l2 -> val;
            if(carry){
                curr = curr + 1;
                carry = false;
            }
            if(curr >= 10){
                curr = curr % 10;
                carry = true;
            }
            ListNode* newNode = new ListNode(curr);
            prev -> next = newNode;
            prev = newNode;
            l2 = l2 -> next;
        }
        if(carry){
            ListNode* newNode = new ListNode(1);
            prev -> next = newNode;
        }
        return head -> next;
    }
};
