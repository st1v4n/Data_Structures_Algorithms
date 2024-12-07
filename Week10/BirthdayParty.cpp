/*
You are given N: number of friends;
On the next N rows, you are given (arrivalTime, departureTime) for each of the friends
You are given T - index ot Target Friend
Print which chair he should sit on when he comes to the party
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Friend {
    int arrives, leaves, idx;

    bool operator<(const Friend& other) {
        return this->arrives < other.arrives;
    }
};

struct Guest {
    int leaves, chair;
};

auto compareGuests = [](const Guest& lhs, const Guest& rhs){
    return lhs.leaves > rhs.leaves;
};

int main() {
    int N;
    cin>>N;
    vector<Friend> friends(N);
    for(int i=0;i<N;i++){
        cin>>friends[i].arrives;
        cin>>friends[i].leaves;
        friends[i].idx = i;
    }
    int T;
    cin>>T;
    std::sort(friends.begin(), friends.end());
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<>> guests;
    std::priority_queue<int, vector<int>, std::greater<>> chairs;
    for(int i=0;i<N;i++){
        chairs.push(i);
    }
    int iter = 0;
    while(true){
        while(guests.size() && guests.top().first <= friends[iter].arrives){
                chairs.push(guests.top().second);
                guests.pop();
        }
        int toSeat = chairs.top();
        guests.push({friends[iter].leaves, toSeat});
        chairs.pop();
        if(friends[iter].idx == T){
            std::cout<<toSeat;
            return 0;
        }
        iter++;
    }
    return 0;
}
