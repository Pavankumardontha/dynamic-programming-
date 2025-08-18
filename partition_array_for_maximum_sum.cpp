int dp[501];
int solve(int current_ind, vector<int>& arr, int& k, int& n)
{
    if(current_ind==n)
    return 0;
    if(dp[current_ind]!=-1)
    return dp[current_ind];
    int ans = 0;
    int maximum = 0;
    for(int i=1;i<=k;i++)
    {
        /*
        we can either take only current element in move to next partition
        we can take [current_ind , current_ind+1] and move forward
        .
        .
        we can take k elements at max from the current element to form a partition
        calculate the answer in each case and take the maximum of all
        */
        // here i represents here the no. of elements to take starting from current element
        // we cannot take atmax k elements always since we might reach the end of the array
        if(current_ind+i-1<n)
        {
            maximum = max(maximum,arr[current_ind+i-1]);
            ans = max(ans , i*maximum + solve(current_ind+i,arr,k,n));
        }
    }
    return dp[current_ind] = ans;
}

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        /*
        arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4 this changes as below
        arr = [1,7,7,7,7,9,9,9,9,9,9] = 1+28+54 = 83
        */
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,arr,k,n);
    }
};
