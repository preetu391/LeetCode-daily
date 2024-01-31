#include<bits/stdc++.h>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        stack<int> st; //stack stores indices of the temperatures
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;--i){
          while(!st.empty()&&temperatures[i]>=temperatures[st.top()]){
            st.pop();
          }
          if(!st.empty()){
            ans[i] = st.top()-i;
          }else{
            ans[i] = 0;
          }
          st.push(i);
        }
        return ans;
    }
};