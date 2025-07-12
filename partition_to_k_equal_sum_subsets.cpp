
int solve(int ind, int current_partition, int current_sum, int& target, vector<bool>& picked, vector<int>& nums, int& n, int& k)
{
    if(current_partition == k+1)
    return true;
    if(current_sum == target)
    return solve(0,current_partition+1,0,target,picked,nums,n,k);
    if(ind==n)
    return false;
    if(picked[ind]==true) // current element is picked to form a target sum in some other previous partitions
    {
        // just move to the next index
        return solve(ind+1,current_partition,current_sum,target,picked,nums,n,k);
    }
    else
    {
        // we pick the current index element and move forward if the current_sum + nums[ind] <= target
        bool ans1 = false;
        bool ans2 = false;
        if(current_sum + nums[ind] <= target)
        {
            picked[ind]=true;
            ans1 = solve(ind+1,current_partition,current_sum+nums[ind],target,picked,nums,n,k);
            picked[ind]=false;
        }
        // do not pick and move forward
        if(ans1==false)
        ans2 = solve(ind+1,current_partition,current_sum, target,picked,nums,n,k);
        return ans1||ans2;
    }
}

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        sum = sum + nums[i];
        if(sum%k!=0)
        return false;
        int target = sum/k;
        vector<bool> picked(n,false);
        return solve(0,1,0,target,picked,nums,n,k);
    }
};
