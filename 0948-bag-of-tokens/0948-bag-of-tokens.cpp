class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int a=0,b=tokens.size()-1;
        int score=0;
        while(a<=b){
            if(power>=tokens[a]){
                power-=tokens[a++];
                score++;
            }
            else{
                if(power+tokens[b]>=tokens[a]&&score!=0&&b-a>=1){
                    power+=tokens[b--];
                    score--;
                }
                else
                    break;
            }
            
        }
        return score;
     }
};