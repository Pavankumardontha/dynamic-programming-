class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        // find the number of dp[i]'s having the max value
        int n = nums.size();
        vector<int> dp(n,1); // dp[i] = length of longest subsequence in the range [0,i] taking ith element
        vector<int> count(n,1); // count[i] = no of different subsequences that can be formed of length dp[i]
        /*
        take an example:
        index = [0,1,2,3,4,5,6,7] 
        nums =  [1,2,4,3,5,4,7,2]
        dp =    [1,2,3,3,4,4,5,2]
        count = [1,1,1,1,2,1,3,1]
        Now lets come to the count array, Here are the number of longest subsequences ending with 7. so the longest subsequence ending with
        7 can be formed either by using 4 or 5.
        coount[0]=1 : [1]
        count[1]=1 : [1,2]
        count[2]=1 : [1,2,4]
        count[3]=1 : [1,2,3]
        count[4]=2 : [1,2,3,5] , [1,2,4,5] => count[5]=count[4]+count[3]
        count[5]=1 : [1,2,3,4]
        count[6]=3 : [1,2,3,5,7] , [1,2,4,5,7] [1,2,3,4,7] => count[6] = count[5]+count[4]
        count[7]=1 : [1,2]
        */
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] and dp[i]<=1+dp[j])
                {
                    if(dp[i]==1+dp[j])
                    count[i]+=count[j];
                    else
                    {
                        dp[i]=1+dp[j];
                        count[i]=count[j];
                    }
                }
            }
            ans = max(ans,dp[i]);
        }
        int c = 0; // count of longest increasing subsequences
        for(int i=0;i<n;i++)
        {
            if(dp[i]==ans)
            c += count[i];
        }
        return c;
    }
};
