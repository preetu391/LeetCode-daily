#include<bits/stdc++.h>
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i=1;i<=n;i++) pq.push(i);
    }
    
    int reserve() {
        int reserved_seat = pq.top();
        pq.pop();
        return reserved_seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

void main(){
    return;
}