/*
You are given X, Y : Coordinates of the start point of a tourist
You are given N: number of all landmarks in the area
You are given K: number of the closest landmarks that the tourist would like to visit

You have to output the coordinates of all those K landmarks
Landmarks sorting priority: Distance to the start -> X coordinate -> Y coordinate
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Coordinate{
    int x,y;
    double distance;
    Coordinate(int x, int y):x(x),y(y){}
    Coordinate(int x, int y, const Coordinate& start){
        this->x=x;
        this->y=y;
        distance = this->getDist(start);
    }
    double getDist(const Coordinate& other){
        int64_t dx = other.x-x;
        int64_t dy = other.y-y;
        double result = sqrt(dx*dx + dy*dy);
        distance = result;
        return result;
    }
    bool operator<(const Coordinate& other) const{
        if(this->distance == other.distance){
            if(this->x == other.x){
                return this->y<other.y;
            }
            return this->x < other.x;
        }
        return this->distance < other.distance;
    }
    
    bool operator>(const Coordinate& other) const{
        if(this->distance == other.distance){
            if(this->x == other.x){
                return this->y>other.y;
            }
            return this->x > other.x;
        }
        return this->distance > other.distance;
    }
};

int main() {
    int X,Y,N,K;
    cin>>X>>Y>>N>>K;
    Coordinate start(X,Y);
    std::priority_queue<Coordinate, vector<Coordinate>, std::greater<Coordinate>> pq;
    for(int i=0; i < N; i++){
        cin>>X>>Y;
        Coordinate cord(X,Y,start);
        pq.push(cord);
    }
    for(int i=0;i<K;i++){
        cout<<pq.top().x<<' ';
        cout<<pq.top().y<<endl;
        pq.pop();
    }
}
