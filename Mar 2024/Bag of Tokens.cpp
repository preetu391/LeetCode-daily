#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score=0;
        int n=tokens.size();
        int i=0, j=n-1;
        while(i<j){
          if(power>=tokens[i]){
            power-=tokens[i];
            i++;
            score++;
          }else if(score>=1 && power+tokens[j]>=tokens[i]){
            power+=tokens[j];
            j--;
            score--;
          }
          else break;
        }
        while(i<j+1 && power>=tokens[i]){
          power-=tokens[i];
          i++;
          score++;
        }
        return score;
    }
};