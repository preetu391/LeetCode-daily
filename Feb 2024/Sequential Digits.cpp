#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str="123456789";
        vector<int> ans;
        for(int i=2;i<=9;i++){
          for(int j=0;j<=9-i;j++){
            string sub_str=str.substr(j,i);
            int num = stoi(sub_str);
            if(num>=low&&num<=high) ans.push_back(num);
          }
        }
        return ans;
    }
};