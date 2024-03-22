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
    ListNode *calc(ListNode* head, bool &f){
         ListNode *cur=head;
        unordered_map<int,int>m;
        stack<ListNode *>stk;
        ListNode *tmp=new ListNode(0);
        tmp->next=cur;
        stk.push(tmp);
        ListNode *newHead=tmp;
        int sum=0;
        while(cur){
            sum+=cur->val;
            stk.push(cur);
            if(sum==0||m.count(sum)){
                f=true;
                int newSum=0;
              do{
                    newSum+=stk.top()->val;
                    //    m[newSum]--;
                    // if(m[newSum]==0) m.erase(newSum);
                    stk.pop();
                }  while(newSum!=0&&!stk.empty());
                if(!stk.empty())
                    stk.top()->next=cur->next;
                m[sum]--;
                if(m[sum]==0) m.erase(sum);
            }
            else
                m[sum]++;
            cur=cur->next;
        }
        return newHead->next;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *ans=head;
         bool f=false;
        do {
            f=false;
           ans=calc(ans,f);
       } while(f);
        return ans;
    }
};