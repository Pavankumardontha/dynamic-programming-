class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        /* see the constraints to get an idea that dynamic programing should not be applied to this question 
        always take 2 steps from the end since greater the current value at which we take the double step,
        the maximum value we can reach to. This is greedy approach
        */
        long long int current_val=target; // we will go from target to 0
        int steps=0;
        while(current_val>1 and maxDoubles>0)
        {
            if(current_val%2==1)
            current_val--;
            else
            {
                current_val = current_val/2;
                maxDoubles--;
            }
            steps++;
        }
        steps += (current_val-1); // we can only take one step for the left over
        return steps;
    }
};
