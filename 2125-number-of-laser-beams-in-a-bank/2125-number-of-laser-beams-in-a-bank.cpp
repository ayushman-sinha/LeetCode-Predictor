class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int c=0;
        for(int i=0;i<bank.size();i++)
        {
            int len=bank[i].length();
            string w="";
            int one_a=0,one_b=0;
            for(int j=0;j<len;j++)
            {
                w+="0";
                if(bank[i][j]=='1')
                one_a++;
            }
            if(w==bank[i])
                continue;
            bool f=false;
            for(int j=i+1;j<bank.size();j++)
            {
                 string s="";
            for(int k=0;k<len;k++)
                s+="0";
            if(s==bank[j])
                continue;
                f=true;
                i=j;
                break;
            }
            if(f)
            {
                 for(int j=0;j<len;j++)
                 {
                      if(bank[i][j]=='1')
                      one_b++;
                 }              
                c+=(one_a*one_b);
                i--;;
            }                
        }
        return c;        
    }
};