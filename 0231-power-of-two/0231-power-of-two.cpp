class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)
            return false;
        while(n!=0)
        {
            if(n==1)
            return true;
            if(n%2!=0)
                return false;
            else
                n=n/2;
        }
        return true;
    }
};