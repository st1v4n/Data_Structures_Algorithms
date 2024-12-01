class Solution {
    int steps[46]{0};
public:
    int climbStairs(int n) {
        steps[1] = 1;
        steps[2] = 2;

        for(int i = 3; i<=n; i++){
            steps[i] = steps[i-2] + steps[i-1];
        }
        return steps[n];
        // n= 4 : 1 1 1 1 ; 2 2; 2 1 1; 1 1 2; 1 2 1; 
    }
};
