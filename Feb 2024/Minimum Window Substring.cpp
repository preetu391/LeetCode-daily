#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int i = 0,j = 0, minx = INT_MAX;
        unordered_map<char,int> mp;
        for(char c : t){
            mp[c]++; 
        }
        int cnt = mp.size(); 
        int start = 0;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    cnt--; 
                }
            }
            j++;
            while(cnt == 0){
                if(minx > j-i){
                    minx = j-i;
                    start = i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0) cnt++;
                }
                i++;
            }
        }
        if(minx != INT_MAX){
            ans = s.substr(start,minx);
        }
        return ans;
    }
};