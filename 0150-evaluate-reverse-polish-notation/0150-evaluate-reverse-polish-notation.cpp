class Solution {
public:
    long long calc(int a,int b,char ch)
    {
        switch(ch)
        {
            case '+':
                return a+b;
                break;
            case '-':
                return b-a;
                break;
            case '*':
                return a*1LL*b;
                break;
            case '/':
                return b/a;
                default :
                break;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long>stk;long long  ans=0LL;
        for(int i=0;i<tokens.size();i++)
        {
            if(isdigit(tokens[i][0]))//IF the element encountered is a digit or a number
                stk.push(stoi(tokens[i]));
            else if(tokens[i].length()>1&&tokens[i][0]=='-')//IF a negative number is encountered Eg : -7
                stk.push(-1*stoi(tokens[i].substr(1,tokens[i].length()-1)));//pushing it into the stack with negative sign after converting the string to number by excluding the '-' sign which is why I have used substr
            else
            {
                int a=stk.top();//popping two elements from the stack to perform the required operation whenever an operator is encountered
                stk.pop();
                int b=stk.top();
                stk.pop();
                char ch=tokens[i][0];
                ans=calc(a,b,ch);//Getting  the answer 
                stk.push(ans);//pushing the answer back to the stack to compute the next operation
            }
        }
        return stk.top();//The final answer will be the stack top
    }
};