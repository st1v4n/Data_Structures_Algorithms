/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, std::greater<>> right; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() && left.top() > num){
            left.push(num);
        }
        else{
            right.push(num);
        }
        if(left.size() + 1 < right.size()){
            left.push(right.top());
            right.pop();
        }
        else if(right.size() + 1 < left.size()){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (left.top() + right.top())/2.0;
        }
        return left.size() > right.size() ? left.top() : right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
