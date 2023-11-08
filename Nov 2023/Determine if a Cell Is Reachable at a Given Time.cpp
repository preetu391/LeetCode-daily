#include<bits/stdc++.h>
using namespace std;
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx &&fy==sy){
            if(t==1) return false;
            return true;
        }
        int m=max(abs(sx-fx),abs(sy-fy));
        if(m<=t) return true;
        return false;
    }
    void main(){
        return;
    }