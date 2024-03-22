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
     ListNode *middle(ListNode *head){
        ListNode *slow=head,*fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *&head){
        ListNode *prev=nullptr;
        while(head){
            ListNode *tmp=head->next;
            head->next=prev;
            prev=head;
            head=tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *mid=middle(head);
        mid->next=reverse(mid->next);
        mid=mid->next;
        ListNode *a=head,*b=mid;
        while(a&&b){
            if(a->val!=b->val) return false;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};