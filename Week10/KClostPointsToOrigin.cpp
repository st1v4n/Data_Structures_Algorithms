/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/

class Solution {
public:

    struct Point{
        double distance;
        int x, y;
        bool operator<(const Point& other) const{
            return distance < other.distance;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> pq;
        for(int i=0;i<points.size();++i){
            double currDist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({currDist, points[i][0], points[i][1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while(pq.size()){
            Point curr = pq.top();
            pq.pop();
            result.push_back({curr.x, curr.y});
        }
        return result;
    }
};
