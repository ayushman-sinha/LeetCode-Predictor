class Solution {
public:
    string getSmallestString(string s, int k) {
        string x=s;
        int c=0;
       // k%=s.length();
        while(k>0){
            int p=k;
            char mini=x[c];
            int kToBeChanged=1;
            char prevMin='z';
            for(int i=1;i<=p;i++){
                char a=(x[c]-'a'+i)%26+'a';
                char b=(x[c]-'a'-(i%26)+26)%26+'a';
                //cout<<a<<" "<<b<<endl;
                if(a<b&&a<prevMin){
                    mini=a;
                    prevMin=a;
                    kToBeChanged=i;
                }
                else if(b<=a&&b<prevMin){
                    mini=b;
                    prevMin=b;
                    kToBeChanged=i;
                }
            }
            
            string t=x;
            t[c]=mini;
            if(t<x){
                x=t;
                k-= kToBeChanged;
            }
            c++;
            if(c==s.length()) break;
            
        }
        return x;
    }
};
/*
    Strt from left fgor lexographically small string
    
*/