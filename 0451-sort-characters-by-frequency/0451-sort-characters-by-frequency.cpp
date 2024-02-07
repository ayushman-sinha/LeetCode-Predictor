class Solution {
public:
    string frequencySort(string s) {
       map<char,int>m;
        for(int i=0;i<s.length();i++)        
            m[s[i]]++;
        vector<pair<int,char>>ar;
        for(auto i=m.begin();i!=m.end();i++)
        ar.push_back({i->second,i->first});
        sort(ar.rbegin(),ar.rend());
        string w="";
          for(int i=0;i<ar.size();i++)
          {
              int  c=ar[i].first;
              char ch=ar[i].second;
              for(int j=1;j<=c;j++)
              {
                  w+=ch;
              }
          }        
        return w;
    }
};