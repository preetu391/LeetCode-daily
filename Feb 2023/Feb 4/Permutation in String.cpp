#include <bits/stdc++.h>
using namespace std;

bool isPermutation(string &s1, string &s2){
    unordered_map<char, int> m;
    for(int i=0;i<s1.size();i++){
        m[s1[i]]++;
        m[s2[i]]--;
    }
    for(auto &it: m){
        if(it.second!=0){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
        int n=s2.size(), m=s1.size();
        for(int i=0;i<=n-m;i++){
            string temp= s2.substr(i, m);
            if(isPermutation(s1,temp)){
                return true;
            }
        }
        return false;
    }

int main()
{
    string s1 = "ABABAB", s2="ABCCBABHJDGSHJ";
    checkInclusion(s1, s2);
    return 0;
}