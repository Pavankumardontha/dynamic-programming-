class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        /*
        dp[i] = longest arithmetic subsequence of given difference found in the range [0,i] including ith index element.
        mp[1]=0; dp[0]=1
        mp[5]=1, dp[1]=1 -> try to find if k(arr[i]-difference) is present in the map or not. If its present add its dp value
        mp[7]=2, dp[2]=1 -> mp[9] is not present
        mp[8]=3 , dp[3]=1 -> mp[10] is not present
        mp[5]=4 , dp[4]=2 -> mp[7] is present and dp[4]<dp[mp[7]]+1 so dp[4]=dp[mp[7]]+1 = 2 => (7,5)
        Notice that we already have mp[5]=1 initially but we will replace it with the latest index because always the latest
        index includes the previous answer plus extra subsequences too if there are any. 
        So if arr[i]==a[j] then , dp[i]<=dp[j] where i<=j
        mp[3]= 5 dp[5]=3(dp[4]+1) = (7,5,3)
        mp[4]=6 dp[6]=1
        mp[2]=7 dp[7]=2 = (4,2)
        mp[1]=8 dp[8]=4 = (7,5,3,1)
        */
        int n = arr.size();
        vector<int> dp(n,1);
        int ans=1;
        unordered_map<int,int> mp;
        mp[arr[0]]=0;
        for(int i=1;i<n;i++)
        {
            int k = arr[i]-difference;
            if(mp.find(k)!=mp.end())
            dp[i]= 1 + dp[mp[k]];
            mp[arr[i]]=i;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
