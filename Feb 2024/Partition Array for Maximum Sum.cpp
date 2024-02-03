#include<bits/stdc++.h>
using namespace std;

//Recursion
class Solution_with_recursion {
public:
    int recur(vector<int> &arr,int ind, int n, int k){
      if(ind>=n) return 0;
      int max_ele = INT_MIN, sum = 0, len=1;
      for(int i=ind;i<min(ind+k,n);i++){
        max_ele = max(max_ele, arr[i]);
        sum = max(sum, recur(arr, i+1, n, k)+len*max_ele);
        len++;
      }
      return sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return recur(arr, 0, arr.size(), k);
    }
};

//Tabulation
class Solution_Tabulation {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
          int max_ele = 0, sum =0, len=1;
          for(int j=i;j<min(i+k,n);j++){
            max_ele = max(max_ele, arr[j]);
            sum = max(sum, max_ele*len+dp[j+1]);
            len++;
          } 
          dp[i] = sum;
        }
        return dp[0];
    }
};