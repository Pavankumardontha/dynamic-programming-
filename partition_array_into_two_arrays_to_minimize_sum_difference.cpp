// DP solution
/*
We cannot generate all the subsets of the array. if the array size is n, then we will have 2^(n) 
subsets. So instead of that , we divide the array into two halfs and generate the subsets for both 
this takes O(2^(n/2) + 2^(n/2))
*/


// recursive solution 
// s1 and s2 are the sum of elements in array-1 and array-2
int solve(int i, int s1, int s2, int n1, int n2, vector<int>& nums, int& n)
{
    if(i==n)
    {
        if(n1==n2)
        return abs(s1-s2); // we need to devide them equally else the case is not valid
        return 1e9+1; // returning some max value
    }
    int ans = INT_MAX;
    // we can take the current element either in array 1 or array 2
    ans = min(ans,solve(i+1,s1+nums[i],s2,n1+1,n2,nums,n)); // if taken in array-1
    ans = min(ans,solve(i+1,s1,s2+nums[i],n1,n2+1,nums,n)); // if taken in array-2
    return ans;
}

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        return solve(0,0,0,0,0,nums,n);
    }
};
