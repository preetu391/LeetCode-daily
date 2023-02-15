#include <bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
        if(k==0) return num;
        string s= to_string(k);
        int j=s.size()-1, i=num.size()-1;
        int carry=0;
        vector<int> ans;
        while(i>=0||j>=0){
            int sum=carry;
            if(i>=0){
                sum+=num[i];
                i--;
            }
            if(j>=0){
                sum+=(s[j]-'0');
                j--;
            }
            carry=sum/10;
            ans.push_back(sum%10);
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    int k=56;
    addToArrayForm(v, k);
    return 0;
}