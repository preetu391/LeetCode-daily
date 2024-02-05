#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
          if(mp.find(s[i])==mp.end()){
            mp[s[i]]=i;
          }else{
            mp[s[i]]=INT_MAX;
          }
        }
        int ans=INT_MAX;
        for(auto it:mp){
          ans=min(it.second,ans);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};