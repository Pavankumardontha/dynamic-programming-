bool comp(vector<int>& x, vector<int>& y)
{
    if(x[1]<y[1])
    return true;
    else
    return false;
}

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        /*
        dp[i] = maximum earnings in the range [0,i]
        analyse this situation
        n=5 , rides = [[0,2,3][2,5,4],[1,2,3],[1,5,1]]
        dp[0]=0;
        dp[1]=0;
        dp[2]=5 There are 2 rounds ending at 2. By picking the ride starting at 0, we earn 2-0+3=5. By picking the 
        ride starting at 1, we earn 2-1+3=4. We take the maximum of both
        dp[3]=5 There is no ride which ends at 3. so we carry forward the earnings.
        dp[4]=5
        dp[5]=. There are 2 rides which end at 5-> [2,5,4]=> 7 ,[1,5,1] = 5 
        so if we choose [2,5,4] ride we can also choose dp[2].
        If we choose [1,5,1] ride we can choose dp[1]
        so dp[5] = max(dp[2]+7,dp[1]+5) = 12
        */

        // sort the rides array in the order of ending
        sort(rides.begin(),rides.end(),comp);
        vector<long long int> dp(n+1,0);
        dp[1]=0;
        int current_ind=0;
        int n1 = rides.size();
        int start,end,tip;
        long long int earning;
        for(int i=2;i<=n;i++)
        {
            while(current_ind<n1)
            {
                if(rides[current_ind][1]==i)
                {
                    start = rides[current_ind][0];
                    end = rides[current_ind][1];
                    tip = rides[current_ind][2];
                    earning = end-start+tip;
                    if(dp[i]<dp[start]+earning)
                    dp[i] = dp[start]+earning;
                    current_ind++;
                }
                else
                break;
            }
            if(dp[i]<dp[i-1])
            dp[i]=dp[i-1];
        }
        return dp[n];
    }
};
