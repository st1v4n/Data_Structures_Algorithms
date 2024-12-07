/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
*/

class KthLargest {
    int _k;
    priority_queue<int, vector<int>, std::greater<>> _pq;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(int i = 0; i < nums.size(); i++){
            _pq.push(nums[i]);
        }
        while(_pq.size() > k){
            _pq.pop();
        }
    }
    
    int add(int val) {
        _pq.push(val);
        if(_pq.size()>_k)_pq.pop();
        return _pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
