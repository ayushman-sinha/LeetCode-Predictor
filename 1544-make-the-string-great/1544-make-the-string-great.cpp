class Solution {
public:
    bool check(char a,char b){
        if(isupper(a)&&a==b-32)
            return true;
        if(islower(a)&&a==b+32)
            return true;
        return false;
    }
    string makeGood(string s) {
        bool f=true;
        while(f&&s.length()>1){
            f=false;
            for(int i=0;i<s.length()-1;i++){
                if(check(s[i],s[i+1])){
                    s=s.erase(i,2);
                    
                    f=true;
                    break;
                }
            }
        }
      
        return s;
    }
};